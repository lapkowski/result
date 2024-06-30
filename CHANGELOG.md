# Unreleased (XX.XX.XXXX)
    - Added the RESULT_DEFINE_WITH_TYPE macro to replace the RESULT_DECLARE(type) RESULT_DEFINE(type) in result types used in a single source file.
    - Added the (RESULT/ERROR)_DECLARE macros for declaring types without compiling them with every header include.
    - Prepare for the shared/static library port.
    - Enabled shared/static library installation and generation of pkg-config files
    - Ported panic.h to a compiled source
    - Moved libc error definitions to the ports/libc directory
    - The ROADMAP was chaned to display properly
    - Fixed the build system to account for the libc error definition move and added the missing default panic declaration to include/panic.h

# 0.1.3 (24.06.2024)
    - Changed the documentation installation directory to /usr/share/doc/result
    - Fixed some minor conversion errors in the documentation

# 0.1.2 (24.06.2024)
    - RESULT_VERSION is now defined by the result header file.

# 0.1.1 (22.06.2024)
    - Fixed the build system and removed the vcs version file.
    - Added the .gitignore file

# 0.1.0 (17.06.2024)
    - Initial Release
