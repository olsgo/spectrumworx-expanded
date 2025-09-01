# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_APPLE_GUI_ICON "/Users/gjb/Projects/spectrumworx-expanded/source/../installer/resources/OSX/SpectrumWorx.icns")
set(CPACK_BUILD_SOURCE_DIRS "/Users/gjb/Projects/spectrumworx-expanded/source;/Users/gjb/Projects/spectrumworx-expanded/source")
set(CPACK_CMAKE_GENERATOR "Unix Makefiles")
set(CPACK_COMPONENTS_ALL_IN_ONE_PACKAGE "ON")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "/opt/homebrew/share/cmake/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "SpectrumWorx built using CMake")
set(CPACK_DMG_SLA_USE_RESOURCE_FILE_LICENSE "ON")
set(CPACK_GENERATOR "PackageMaker")
set(CPACK_INNOSETUP_ARCHITECTURE "x64")
set(CPACK_INSTALL_CMAKE_PROJECTS "/Users/gjb/Projects/spectrumworx-expanded/source;SpectrumWorx;ALL;/")
set(CPACK_INSTALL_COMMANDS "strip -S -x \"/Library/Application Support/Little Endian/SpectrumWorx/Release/SpectrumWorx.dylib\"")
set(CPACK_INSTALL_PREFIX "/")
set(CPACK_MODULE_PATH "/Users/gjb/Projects/spectrumworx-expanded/source/../installer/resources")
set(CPACK_MONOLITHIC_INSTALL "ON")
set(CPACK_NSIS_DISPLAY_NAME "SpectrumWorx")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
set(CPACK_NSIS_PACKAGE_NAME "SpectrumWorx")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OBJDUMP_EXECUTABLE "/usr/bin/objdump")
set(CPACK_OSX_PACKAGE_VERSION "10.6")
set(CPACK_OUTPUT_CONFIG_FILE "/Users/gjb/Projects/spectrumworx-expanded/source/CPackConfig.cmake")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "/opt/homebrew/share/cmake/Templates/CPack.GenericDescription.txt")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Will be installed...")
set(CPACK_PACKAGE_FILE_NAME "SpectrumWorx-3.0.0-development-Setup")
set(CPACK_PACKAGE_ICON "/Users/gjb/Projects/spectrumworx-expanded/source/../installer/resources/OSX/SpectrumWorx.icns")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "SpectrumWorx")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "SpectrumWorx")
set(CPACK_PACKAGE_NAME "SpectrumWorx")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "Little Endian Ltd.")
set(CPACK_PACKAGE_VERSION "3.0.0")
set(CPACK_PACKAGE_VERSION_MAJOR "3")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGING_INSTALL_PREFIX "/")
set(CPACK_POSTFLIGHT_SCRIPT "/Users/gjb/Projects/spectrumworx-expanded/source/../installer/resources/OSX/make_symlinks.sh")
set(CPACK_POSTINSTALL_SCRIPT "/Users/gjb/Projects/spectrumworx-expanded/source/../installer/resources/OSX/make_symlinks.sh")
set(CPACK_POSTUPGRADE_SCRIPT "/Users/gjb/Projects/spectrumworx-expanded/source/../installer/resources/OSX/make_symlinks.sh")
set(CPACK_RESOURCE_FILE_LICENSE "/Users/gjb/Projects/spectrumworx-expanded/source/../installer/ProgramFolder/Licences/EULA.txt")
set(CPACK_RESOURCE_FILE_README "/Users/gjb/Projects/spectrumworx-expanded/source/../installer/ProgramFolder/ReadMe.rtf")
set(CPACK_RESOURCE_FILE_WELCOME "/Users/gjb/Projects/spectrumworx-expanded/source/../installer/resources/OSX/MacInstallIntro.txt")
set(CPACK_SET_DESTDIR "TRUE")
set(CPACK_SOURCE_GENERATOR "TBZ2;TGZ;TXZ;TZ")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/Users/gjb/Projects/spectrumworx-expanded/source/CPackSourceConfig.cmake")
set(CPACK_SOURCE_RPM "OFF")
set(CPACK_SOURCE_TBZ2 "ON")
set(CPACK_SOURCE_TGZ "ON")
set(CPACK_SOURCE_TXZ "ON")
set(CPACK_SOURCE_TZ "ON")
set(CPACK_SOURCE_ZIP "OFF")
set(CPACK_STRIP_FILES "TRUE")
set(CPACK_SYSTEM_NAME "Darwin")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "Little Endian")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/Users/gjb/Projects/spectrumworx-expanded/source/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()

# Configuration for component "SupportFiles"
set(CPACK_COMPONENT_SUPPORTFILES_DISPLAY_NAME "Support files")
set(CPACK_COMPONENT_SUPPORTFILES_DESCRIPTION "Documents, licences, presets, skins...")

# Configuration for component "VST24PluginBundle"
set(CPACK_COMPONENT_VST24PLUGINBUNDLE_DISPLAY_NAME "VST 2.4 plugin")
set(CPACK_COMPONENT_VST24PLUGINBUNDLE_DESCRIPTION "SpectrumWorx VST 2.4 wrapper")
set(CPACK_COMPONENT_VST24PLUGINBUNDLE_DEPENDS SupportFiles PluginBinary)

# Configuration for component "AUComponent"
set(CPACK_COMPONENT_AUCOMPONENT_DISPLAY_NAME "Audio Unit component")
set(CPACK_COMPONENT_AUCOMPONENT_DESCRIPTION "SpectrumWorx AU wrapper")
set(CPACK_COMPONENT_AUCOMPONENT_DEPENDS SupportFiles PluginBinary)

# Configuration for component "PluginBinary"
set(CPACK_COMPONENT_PLUGINBINARY_DISPLAY_NAME "Plugin binary")
set(CPACK_COMPONENT_PLUGINBINARY_DESCRIPTION "The actual SpectrumWorx binary")
set(CPACK_COMPONENT_PLUGINBINARY_DEPENDS SupportFiles)
