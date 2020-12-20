import config
import pexpect


qemu-cmd = 'qemu-system-'
qemu-cmd += config.machine + ' '
qemu-cmd += config.image
# QEMU command to run


child = pexpect.spawn(qemu-cmd)
child.logfile = sys.stdout

child.expect('(?i)login:')
child.sendline(user)
child.expect('(?i)password:')
child.sendline(password)
child.expect('# ')


if child.isalive():
    child.sendline('init 0')
    child.close()

if child.isalive():
    print('Child did not exit gracefully.')
else:
    print('Child exited gracefully.')