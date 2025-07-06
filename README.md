# SpectrumWorx 🔊
SpectrumWorx - the ultimate sound mangler (VST/AU).

![img](https://github.com/LittleEndianLtd/SpectrumWorx/blob/main/doc/All_windows_numbered.png)

## Current state? 🔮
The state of the project is - 2016 - very outdated. This includes the directory structure (inherited from SVN), 3rd party software, CMake makefiles, installer, VST/AU compatibility, etc. The code does not compile, the build does not work. 
## Where to start? 🚀
- [doc/readme.txt](./doc/readme.txt)
- [source/externals/le/doc/internal/readme.txt](./source/externals/le/doc/internal/readme.txt)

## Building 🛠️

This repository bundles all required 3rd party libraries in the `3rd_party`
directory.  If you keep them there no extra configuration is needed.  To use a
different location set the `LEB_3rdParty_root` environment variable before
running CMake:

```bash
export LEB_3rdParty_root=/path/to/your/libs
cmake -S source -B build
```
