# Testing examples

You can test examples using the [htrun](https://github.com/ARMmbed/mbed-os-tools/tree/master/packages/mbed-host-tests) tool and templated print log.

To run the test, use this command after you build the example:

```
$ mbedhtrun -d <MOUNT_POINT> -p <SERIAL_PORT> -m <TARGET> -f ./BUILD/<TARGET>/<TOOLCHAIN>/mbed-os-example-blinky-baremetal.bin --compare-log tests/blinky-baremetal.log
```

For example:

```
mbedhtrun -d /Volumes/DAPLINK -p /dev/tty.usbmodem21102 -m K64F -f ./BUILD/K64F/GCC_ARM/mbed-os-example-blinky-baremetal.bin --compare-log tests/blinky-baremetal.log
```

To find your target `MOUNT_POINT` and `SERIAL_PORT`, please see [mbedls](https://github.com/ARMmbed/mbed-os-tools/blob/master/packages/mbed-ls/README.md#mbed-ls).
