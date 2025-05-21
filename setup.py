#!/usr/bin/env python3
import os, sysconfig

linux_dir = 'thirdparty/Linux'
os.makedirs(linux_dir, exist_ok=True)

symlinks = {
    f'{linux_dir}/bin': sysconfig.get_config_var('BINDIR'),
    f'{linux_dir}/include': sysconfig.get_config_var('CONFINCLUDEPY'),
    f'{linux_dir}/lib': sysconfig.get_config_var('DESTLIB')
}

for name, target in symlinks.items():
    if os.path.islink(name) or os.path.exists(name): os.unlink(name)  # remove existing link or file
    os.symlink(target, name)
    print(f"Symlinked ./{name} to {target}")
