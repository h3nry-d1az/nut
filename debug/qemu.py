import config
import pexpect


qemu_cmd = 'qemu-system-'
qemu_cmd += config.machine + ' '
qemu_cmd += config.flags
qemu_cmd += config.image
# QEMU command to run


child = pexpect.spawn(qemu_cmd)
child.logfile = sys.stdout

child.expect('(?i)login:')
child.sendline(config.user)
child.expect('(?i)password:')
child.sendline(config.password)
child.expect('# ')


if child.isalive():
    child.sendline('init 0')
    child.close()

if child.isalive():
    print('Child did not exit gracefully.')
else:
    print('Child exited gracefully.')