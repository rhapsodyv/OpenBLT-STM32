Import("env")

board = DefaultEnvironment().BoardConfig()

env['BUILD_FLAGS'].append('-DBOARD_F_CPU=' + env['BOARD_F_CPU'])

maximum_flash_size = int(board.get("upload.maximum_size") / 1024)
env['BUILD_FLAGS'].append('-DSTM32_FLASH_SIZE=' + str(maximum_flash_size))