import unittest

import jgLedCube


class TestSerial(unittest.TestCase):

    def test_encode_clear(self):
        clear_cmd = jgLedCube.serial.encode_clear()
        clear_pkt = jgLedCube.serial.construct_transport_packet(clear_cmd)
        d_clear_cmd = jgLedCube.serial.deconstruct_transport_packet(clear_pkt)

        for i, c in enumerate(d_clear_cmd):
            self.assertTrue(c == clear_cmd[i])

    def test_encode_set_led(self):
        enc_set_led_cmd = jgLedCube.serial.encode_set_led(4, 8, 7, 15, 13, 1)
        out_set_led_pkt = jgLedCube.serial.construct_transport_packet(enc_set_led_cmd)
        dec_set_led_cmd = jgLedCube.serial.deconstruct_transport_packet(out_set_led_pkt)

        for i, c in enumerate(dec_set_led_cmd):
            self.assertTrue(c == enc_set_led_cmd[i])

    def test_encode_get_led(self):
        enc_get_led_cmd = jgLedCube.serial.encode_get_led(4, 8, 7)
        out_get_led_pkt = jgLedCube.serial.construct_transport_packet(enc_get_led_cmd)
        dec_get_led_cmd = jgLedCube.serial.deconstruct_transport_packet(out_get_led_pkt)

        for i, c in enumerate(dec_get_led_cmd):
            self.assertTrue(c == enc_get_led_cmd[i])

    def test_encode_get_config(self):
        enc_get_config_cmd = jgLedCube.serial.encode_get_config()
        out_get_config_pkt = jgLedCube.serial.construct_transport_packet(enc_get_config_cmd)
        dec_get_config_cmd = jgLedCube.serial.deconstruct_transport_packet(out_get_config_pkt)

        for i, c in enumerate(dec_get_config_cmd):
            self.assertTrue(c == enc_get_config_cmd[i])


if __name__ == '__main__':
    unittest.main(verbosity=2)
