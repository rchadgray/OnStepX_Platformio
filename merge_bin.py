Import("env")

# This script merges bootloader, partitions, and application into a single bin file
env.AddCustomTarget(
    name="mergebin",
    dependencies=["$BUILD_DIR/${PROGNAME}.bin"],
    actions=[
        "esptool.py --chip esp32 merge_bin -o $BUILD_DIR/merged-firmware.bin "
        "--flash_mode dio --flash_freq 40m --flash_size 4MB "
        "0x1000 $BUILD_DIR/bootloader.bin "
        "0x8000 $BUILD_DIR/partitions.bin "
        "0x10000 $BUILD_DIR/${PROGNAME}.bin"
    ],
    title="Merge Binaries",
    description="Merge bootloader, partitions, and app into one binary"
)

# Tell PlatformIO to run this automatically after every build
env.AddPostAction("$BUILD_DIR/${PROGNAME}.bin", [
    "esptool.py --chip esp32 merge_bin -o $BUILD_DIR/merged-firmware.bin "
    "--flash_mode dio --flash_freq 40m --flash_size 4MB "
    "0x1000 $BUILD_DIR/bootloader.bin "
    "0x8000 $BUILD_DIR/partitions.bin "
    "0x10000 $BUILD_DIR/${PROGNAME}.bin"
])
