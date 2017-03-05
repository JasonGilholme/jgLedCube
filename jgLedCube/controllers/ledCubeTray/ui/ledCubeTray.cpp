//
// Created by jase on 4/03/17.
//

#include "ledCubeTray.h"
#include "jgLedCube/controllers/ledCubeTray/ui/ledCubeTrayUi.h"

#include <QTextStream>
#include <QCoreApplication>
#include <QtSerialPort/QSerialPortInfo>


LedCubeTray::LedCubeTray(QWidget *parent) :
    QWidget(parent), ui(new Ui::Form)
{
    ui->setupUi(this);
    this->setupInterface();
}

LedCubeTray::~LedCubeTray()
{
    delete ui;
}

void LedCubeTray::setupInterface() {
//    initialize the library by calling the function libusb_init and creating a session
//    Call the function libusb_get_device_list to get a list of connected devices. This creates an array of libusb_device containing all usb devices connected to the system.
//            Loop through all these devices and check their options
//    Discover the one and open the device either by libusb_open or libusb_open_device_with_vid_pid(when you know vendor and product id of the device) to open the device
//    Clear the list you got from libusb_get_device_list by using libusb_free_device_list
//    Claim the interface with libusb_claim_interface (requires you to know the interface numbers of device)
//    Do desired I/O
//    Release the device by using libusb_release_interface
//    Close the device you openedbefore, by using libusb_close
//    Close the session by using libusb_exit

//    libusb_init(NULL);
//    libusb_device **devs;
//    size_t n_devices;
//    n_devices = libusb_get_device_list(NULL, &devs);
//
//    libusb_device *dev;
//    int i = 0, j = 0;
//    uint8_t path[8];
//
//    while ((dev = devs[i++]) != NULL) {
//        struct libusb_device_descriptor desc;
//        int r = libusb_get_device_descriptor(dev, &desc);
//
//        printf("%04x:%04x (bus %d, device %d)\n",
//               desc.idVendor, desc.idProduct,
//               libusb_get_bus_number(dev), libusb_get_device_address(dev));
//
//        r = libusb_get_port_numbers(dev, path, sizeof(path));
//        printf(" path: %d", path[0]);
//        for (j = 1; j < r; j++)
//            printf(".%d", path[j]);
//        printf("\n");
//
//    }
//

    QTextStream out(stdout);

    QList<QSerialPortInfo> availablePorts = QSerialPortInfo::availablePorts();
//    QSerialPortInfo::availablePortsBySysfs()
//    QSerialPortInfo::availablePortsByUdev()
    const QString blankString = QObject::tr("N/A");
    out << QObject::tr("Total number of ports available: ") << availablePorts.count() << endl;

    QString description;
    QString manufacturer;
    QString serialNumber;

    for (const QSerialPortInfo &serialPortInfo : availablePorts) {
        description = serialPortInfo.description();
        manufacturer = serialPortInfo.manufacturer();
        serialNumber = serialPortInfo.serialNumber();
        out << endl
            << QObject::tr("Port: ") << serialPortInfo.portName() << endl
            << QObject::tr("Location: ") << serialPortInfo.systemLocation() << endl
            << QObject::tr("Description: ") << (!description.isEmpty() ? description : blankString) << endl
            << QObject::tr("Manufacturer: ") << (!manufacturer.isEmpty() ? manufacturer : blankString) << endl
            << QObject::tr("Serial number: ") << (!serialNumber.isEmpty() ? serialNumber : blankString) << endl
            << QObject::tr("Vendor Identifier: ") << (serialPortInfo.hasVendorIdentifier() ? QByteArray::number(serialPortInfo.vendorIdentifier(), 16) : blankString) << endl
            << QObject::tr("Product Identifier: ") << (serialPortInfo.hasProductIdentifier() ? QByteArray::number(serialPortInfo.productIdentifier(), 16) : blankString) << endl
            << QObject::tr("Busy: ") << (serialPortInfo.isBusy() ? QObject::tr("Yes") : QObject::tr("No")) << endl;
    }


    QStringList items({"asdf","zxvc"});
    ui->cmbDevice->addItems(items);
//
//    libusb_exit(NULL);
}
