/*
    PORTS/ERRORTYPES.C - Error defines for the errno constants on diffrent targets

    Copyright (C) 2024 Mariusz Łapkowski

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include <ports/libc/errors.h>

#include <error.h>

/* 
Error descriptions are based on the:
    - GNU C Library documentation, sourceware.org (https://sourceware.org/glibc/manual/latest/html_node/Error-Codes.html), Copyright (C) 2024 Free Software Fundation, Inc., Retrived 23-05-2024
    - Visual Studio documentation for Microsoft C++, learn.microsoft.com (https://learn.microsoft.com/en-us/cpp/c-runtime-library/errno-constants), Copyright (C) 2022 Microsoft Corporation, Retrived 23-05-2024
    - MacOS X intro(2) man page, developer.apple.com (https://developer.apple.com/library/archive/documentation/System/Conceptual/ManPages_iPhoneOS/man2/intro.2.html), Copyright (C) 2016 Apple Inc., Retrived 23-05-2024
    - FreeBSD 14.0 errno(2) man page, man.freebsd.org (https://man.freebsd.org/cgi/man.cgi?errno(2)), Copyright (C) 1995-2024 The FreeBSD Project, Retrived 23-05-2024
    - NetBSD 10.0 errno(2) man page, man.netbsd.org (https://man.netbsd.org/errno.2), Copyright (C) 2015 The NetBSD fundation, Retrived 23-05-2024
    - OpenBSD 7.5 intro(2) man page, man.openbsd.org (https://man.openbsd.org/errno), Copyright (C) 2022 The OpenBSD fundation, Retrived 23-05-2024
    - Linux errno(3) man page, kernel.org (https://kernel.org/pub/linux/docs/man-pages/man-pages-6.8.tar.xz), Copyright (C) 1996 Andries Brouwer, Retrived 23-05-2024
    - The Open Group Base Specyfications Issue 7 errno.h page, pubs.opengroup.org (https://pubs.opengroup.org/onlinepubs/9699919799.2016edition/basedefs/errno.h.html), Copyright (C) 2001-2016 The IEEE and The Open Group, Retrived 23-05-2024

    This library is an independent entity and is neither affiliated with, nor authorized, sponsored, or approved by, Apple Inc., Free Software Fundation, Inc., Microsoft Corporation, The FreeBSD Project, The NetBSD fundation, The OpenBSD fundation, The Linux Kernel Organization, Inc., The Open group or The IEEE.
*/

ERRORTYPE_DEFINE(PermissionNotPermitted,                PermissionErrorExitCode,        "An attempt was made to perform an operation that is reserved for higher privilage processes.")
ERRORTYPE_DEFINE(FileDoesNotExist,                      FileOperationFailedExitCode,    "No file or directory could be found in the path specified.")
ERRORTYPE_DEFINE(ProcessNotFound,                       InvalidRequestExitCode,         "No process could be found corresponding to the PID specified.")
ERRORTYPE_DEFINE(InterruptedSysCall,                    OtherErrorExitCode,             "An asynchronous signal occured and prevented completion of the call.")
ERRORTYPE_DEFINE(IOError,                               FileOperationFailedExitCode,    "Some physical input or output error occured.")
ERRORTYPE_DEFINE(DeviceNotFoundOrAddress,               FileOperationFailedExitCode,    "Attached device couldn't handle the request, was incorectly installed, or was not found.")
ERRORTYPE_DEFINE(ArgumentListTooBig,                    InvalidRequestExitCode,         "The number of bytes used in the argument list exceeded the limit.")
ERRORTYPE_DEFINE(ExecFormatError,                       InvalidRequestExitCode,         "An attempt was made to execute a file that does not contain an executable-specific format.")
ERRORTYPE_DEFINE(BadFileDescriptor,                     FileOperationFailedExitCode,    "A file descriptor is not pointing to an opened file, or cannot handle the request.")
ERRORTYPE_DEFINE(NoChildProcesses,                      InvalidRequestExitCode,         "An attempt was made to manipulate a non-existing child process.")
ERRORTYPE_DEFINE(ResourceDeadlockAvoided,               OtherErrorExitCode,             "An attempt was made to lock a system resource that would have resulted in a deadlock situation.")
ERRORTYPE_DEFINE(NotEnoughMemory,                       MemoryRelatedErrorExitCode,     "This process requires more memory than is allowed by the hardware or by system-managed constraints.")
ERRORTYPE_DEFINE(PermissionDenied,                      FileOperationFailedExitCode,    "An attempt was made to access a file in a way forbidden by it's file access permissions.")
ERRORTYPE_DEFINE(BadAddress,                            MemoryRelatedErrorExitCode,     "The system detected an invalid address in attempting to use an argument of a call.")
ERRORTYPE_DEFINE(NotABlockDevice,                       FileOperationFailedExitCode,    "An attempt was made to do a block operation on an non-block device or file.")
ERRORTYPE_DEFINE(DeviceOrResourceBusy,                  OtherErrorExitCode,             "An attempt was made to use a system resource which was used at a time in a conflicting way.")
ERRORTYPE_DEFINE(FileExists,                            FileOperationFailedExitCode,    "An attempt was made to create a file in a location used by another file.")
ERRORTYPE_DEFINE(InvalidCrossDeviceLink,                FileOperationFailedExitCode,    "An attempt was made to create a hard link across file systems.")
ERRORTYPE_DEFINE(UnsupportedDeviceOperation,            InvalidRequestExitCode,         "An attempt was made to apply an inappropriate function to a device.")
ERRORTYPE_DEFINE(NotADirectory,                         FileOperationFailedExitCode,    "An attempt was made to apply a directory-expecting function to a non-directory path.")
ERRORTYPE_DEFINE(IsADirectory,                          FileOperationFailedExitCode,    "An attempt was made to apply an inappropriate function to a directory.")
ERRORTYPE_DEFINE(InvalidArgument,                       InvalidRequestExitCode,         "An invalid argument was supplied to a function.")
ERRORTYPE_DEFINE(TooManyOpenedFiles,                    FileOperationFailedExitCode,    "The current process has too many files open and can't open any more.")
ERRORTYPE_DEFINE(TooManyOpenedFilesInSystem,            FileOperationFailedExitCode,    "The operating system has too many files open and can't open any more.")
ERRORTYPE_DEFINE(InappropriateIoctlForDevice,           InvalidRequestExitCode,         "An attempt was made to apply an inappropriate control function operation on a file or a special device.")
ERRORTYPE_DEFINE(TextSegmentBusy,                       FileOperationFailedExitCode,    "An attempt was made to modify a file while it's beeing executed, or execute a file while it's beeing modified.")
ERRORTYPE_DEFINE(FileTooLarge,                          FileOperationFailedExitCode,    "The size of a file is larger than allowed by the system.")
ERRORTYPE_DEFINE(NoSpaceLeftOnDevice,                   FileOperationFailedExitCode,    "A write operation was attempted on a device that is full.")
ERRORTYPE_DEFINE(IllegalSeek,                           InvalidRequestExitCode,         "A seek operation was attempted on a socket, pipe or FIFO.")
ERRORTYPE_DEFINE(ReadOnlyFileSystem,                    FileOperationFailedExitCode,    "An attempt was made to modify a file or directory was made on a filesystem that was read-only at the time.")
ERRORTYPE_DEFINE(TooManyLinks,                          FileOperationFailedExitCode,    "Maximum allowable hard links to a single file has been exceeded.")
ERRORTYPE_DEFINE(BrokenPipe,                            OtherErrorExitCode,             "A write on a pipe, socket of FIFO for which there is no process to read the data.")
ERRORTYPE_DEFINE(DeviceNotFound,                        InvalidRequestExitCode,         " The wrong type of device was given to a function that expects a particular sort of device.")
ERRORTYPE_DEFINE(NumericalArgumentOutOfDomain,          MathRelatedErrorExitCode,       "A numerical input argument was ouside the defined domain of the mathematical function")
ERRORTYPE_DEFINE(NumericalArgumentOutOfRange,           MathRelatedErrorExitCode,       "A numerical result of the function was too large to fit in the avaiable space.")
ERRORTYPE_DEFINE(ResourceUnavailable,                   OtherErrorExitCode,             "The system lacks resources to complete the operation. This operation may succeed later, when system resources are freed.")
ERRORTYPE_DEFINE(InProgress,                            OtherErrorExitCode,             "A long operation was attempted at a non-blocking function. [If you (a user) see this error message, this is a programming error. Please report it to the program authors.]")
ERRORTYPE_DEFINE(AlreadyInProgress,                     OtherErrorExitCode,             "An operation was attempted on a non-blocking object that already had an operation in progress.")
ERRORTYPE_DEFINE(SocketOperationOnNonSocket,            InvalidRequestExitCode,         "An attempt was made to apply a socket-expecting function to a non-socket file.")
ERRORTYPE_DEFINE(MessageTooLong,                        InvalidRequestExitCode,         "A message sent on a socket was larger than the internal message buffer or some other network limit.")
ERRORTYPE_DEFINE(WrongProtocolForSocket,                InvalidRequestExitCode,         "A protocol was specified that does not support the semantics of the socket type requested.")
ERRORTYPE_DEFINE(ProtocolNotAvailable,                  InvalidRequestExitCode,         "A socket option was specified that does not make sense for the particular protocol being used in the socket.")
ERRORTYPE_DEFINE(SocketTypeNotSupported,                InvalidRequestExitCode,         "The support for the socket type has not been configured into the system or no implementation for it exists.")
ERRORTYPE_DEFINE(NotSupported,                          InvalidRequestExitCode,         "The attempted operation is not supported for the type of object referenced.")
ERRORTYPE_DEFINE(ProtocolFamilyNotSupported,            InvalidRequestExitCode,         "The protocol family has not been configured into the system or no implementation for it exists.")
ERRORTYPE_DEFINE(ProtocolNotSupported,                  InvalidRequestExitCode,         "The protocol has not been configured into the system or no implementation for it exists.")
ERRORTYPE_DEFINE(AddressFamilyNotSupportedByProtocol,   InvalidRequestExitCode,         "An address incompatible with the requested protocol was used.")
ERRORTYPE_DEFINE(AddressAlreadyInUse,                   InvalidRequestExitCode,         "The requested socket address is already in use.")
ERRORTYPE_DEFINE(CannotAssignRequestedAddress,          InvalidRequestExitCode,         "The requested socket address is not available.")
ERRORTYPE_DEFINE(NetworkIsDown,                         NetworkConectionErrorExitCode,  "A socket operation encontered a dead network.")
ERRORTYPE_DEFINE(NetworkIsUnreachable,                  NetworkConectionErrorExitCode,  "A socket operation was attempted to an unreachable network.")
ERRORTYPE_DEFINE(NetworkDroppedConnectionOnReset,       NetworkConectionErrorExitCode,  "The host you were connected to crashed and rebooted.")
ERRORTYPE_DEFINE(SoftwareCausedConnectionAbort,         NetworkConectionErrorExitCode,  "A network connection was aborted locally.")
ERRORTYPE_DEFINE(ConnectionResetByPeer,                 NetworkConectionErrorExitCode,  "A network connection was closed for reasons outside the control of the local host.")
ERRORTYPE_DEFINE(NoBufferSpaceAvailable,                OtherErrorExitCode,             "An operation was not performed because the system lacked sufficient buffer space or because a queue was full.")
ERRORTYPE_DEFINE(SocketIsAlreadyConnected,              NetworkConectionErrorExitCode,  "A connect request was made on an already connected socket.")
ERRORTYPE_DEFINE(SocketIsNotConnected,                  NetworkConectionErrorExitCode,  "A request to send or receive data was disallowed because the socket was not connected and no address was supplied.")
ERRORTYPE_DEFINE(CannotSendAfterSocketShutdown,         NetworkConectionErrorExitCode,  "A request to send data was disallowed because the socket had already been shut down.")
ERRORTYPE_DEFINE(DestinationAddressRequired,            InvalidRequestExitCode,         "A required address was omitted from an operation on a socket.")
ERRORTYPE_DEFINE(TooManyReferences,                     OtherErrorExitCode,             "A splice cannot be completed, because there are too many references.")
ERRORTYPE_DEFINE(ConnectionTimedOut,                    NetworkConectionErrorExitCode,  "A connect or send request failed because the connected party did not properly respond after a period of time.")
ERRORTYPE_DEFINE(ConnectionRefused,                     NetworkConectionErrorExitCode,  "No connection could be made because the target machine actively refused it.")
ERRORTYPE_DEFINE(TooManyLevelsOfSymbolicLinks,          FileOperationFailedExitCode,    "Too many levels of symbolic links were encountered in looking up a file name.")
ERRORTYPE_DEFINE(FileNameTooLong,                       FileOperationFailedExitCode,    "FileName or host name exceeded the limit of characters")
ERRORTYPE_DEFINE(HostIsDown,                            NetworkConectionErrorExitCode,  "The remote host for a requested network connection is down.")
ERRORTYPE_DEFINE(NoRouteToHost,                         NetworkConectionErrorExitCode,  "The remote host for a requested connection is not reachable.")
ERRORTYPE_DEFINE(DirectoryNotEmpty,                     FileOperationFailedExitCode,    "An non-empty directory was supplied.")
ERRORTYPE_DEFINE(TooManyProceses,                       OtherErrorExitCode,             "The per-user limit on new processes was exceeded.")
ERRORTYPE_DEFINE(TooManyUsers,                          OtherErrorExitCode,             "The new user limit was exceeded.")
ERRORTYPE_DEFINE(DiskQuotaExceeded,                     FileOperationFailedExitCode,    "The user's quota of disk blocks was exhaused.")
ERRORTYPE_DEFINE(StaleNFSFileHandle,                    FileOperationFailedExitCode,    "An attempt was made to access an open file (on an NFS filesystem) which is now unavailable.")
ERRORTYPE_DEFINE(NFSObjectIsRemote,                     FileOperationFailedExitCode,    "An attempt was made to NFS-mount a remote file system with a file name that already specifies an NFS-mounted file.")
ERRORTYPE_DEFINE(RPCStructIsBad,                        OtherErrorExitCode,             "Exchange of RPC information was unseccessful.")
ERRORTYPE_DEFINE(RPCVersionWrong,                       OtherErrorExitCode,             "The version of RPC on the remote peer is not compatible with the local version.")
ERRORTYPE_DEFINE(RPCProgramNotAvailable,                OtherErrorExitCode,             "The requested program is not registered on the remote host.")
ERRORTYPE_DEFINE(RPCProgramVersionWrong,                OtherErrorExitCode,             "The requested version of the program is not available on the remote host (RPC).")
ERRORTYPE_DEFINE(BadRPCProcedureForProgram,             OtherErrorExitCode,             "An RPC call was attempted for a procedure which doesn't exist in the remote program.")
ERRORTYPE_DEFINE(NoLocksAvailable,                      FileOperationFailedExitCode,    "Attempted a system call that is not available on this system.") /* Whoa */
ERRORTYPE_DEFINE(InappropriateFileTypeOrFormat,         FileOperationFailedExitCode,    "The file was the wrong type for the operation, or a data file had the wrong format.")
ERRORTYPE_DEFINE(AuthenticationError,                   FileOperationFailedExitCode,    "Attempted to use an invalid authentication ticket to mount an NFS file system.")
ERRORTYPE_DEFINE(NeedAuthenticator,                     FileOperationFailedExitCode,    "An authentication ticket must be obtained before the given NFS file system may be mounted.")
ERRORTYPE_DEFINE(FunctionNotImplemented,                OtherErrorExitCode,             "The function called is not implemented at all, or not available in the system.")
ERRORTYPE_DEFINE(CannotExecASharedLibrary,              OtherErrorExitCode,             "An attempt was made to execute a shared library.")
ERRORTYPE_DEFINE(WrongOrIncompleteMultibyteOrWideChar,  OtherErrorExitCode,             "While decoding a multibyte character the function came along an invalid or an incomplete sequence of bytes or the given wide characted is invalid.")
ERRORTYPE_DEFINE(InappropriateOperationForBgProcess,    InvalidRequestExitCode,         "An inappropriate operation was attempted in a background process.")
ERRORTYPE_DEFINE(TranslatorDied,                        OtherErrorExitCode,             "A translator program died while starting up.")
ERRORTYPE_DEFINE(BadMessage,                            InvalidRequestExitCode,         "The message to be received is inappropriate for the operation being attempted.")
ERRORTYPE_DEFINE(IdentifierRemoved,                     OtherErrorExitCode,             "An IPC identiffier was removed while the current process was waiting on it.")
ERRORTYPE_DEFINE(MultihopAttempted,                     OtherErrorExitCode,             "Components of path require hopping to multiple remorte machines and the filesystem does not allow it.")
ERRORTYPE_DEFINE(NoDataAvailable,                       OtherErrorExitCode,             "No message is available.")
ERRORTYPE_DEFINE(LinkHasBeenServed,                     FileOperationFailedExitCode,    "The link connection to a remote machine is gone.")
ERRORTYPE_DEFINE(NoMessageOfDesiredType,                OtherErrorExitCode,             "No message of desired type could be found.")
ERRORTYPE_DEFINE(OutOfStreamsResources,                 OtherErrorExitCode,             "The buffer could not be allocated due to insufficient STREAMs memory resources.")
ERRORTYPE_DEFINE(NotAStream,                            OtherErrorExitCode,             "A STREAM is not associeted with the specified file descriptor.")
ERRORTYPE_DEFINE(ValueTooLarge,                         MathRelatedErrorExitCode,       "A numerical result of a function was too large to be stored in the caller provided space.")
ERRORTYPE_DEFINE(ProtocolError,                         OtherErrorExitCode,             "Some protocol error occured (This error is device-specyfic, but is generaly not related to hardware faliure. For more information refer to the manufacturer's manual.")
ERRORTYPE_DEFINE(TimerExpired,                          OtherErrorExitCode,             "A timer set for an I/O operation expired.")
ERRORTYPE_DEFINE(OperationCanceled,                     OtherErrorExitCode,             "An ansychronous operation was canceled before it was completed.")
ERRORTYPE_DEFINE(OwnerDied,                             OtherErrorExitCode,             "The last owner of a robust mutex died while holding it.")
ERRORTYPE_DEFINE(MutexStateNotRecoverable,              OtherErrorExitCode,             "The last owner of a robust mutex died while holding it, and the new owner had unlocked the mutex without making it's state consistent.")
ERRORTYPE_DEFINE(TruncatedString,                       OtherErrorExitCode,             "A string copy or concatenation resulted in a truncated string.")
ERRORTYPE_DEFINE(UnexpectedError,                       OtherErrorExitCode,             "An error happend, but the error code passed is invalid.")
ERRORTYPE_DEFINE(CodeAbuse,                             InvalidRequestExitCode,         "A function or API is being abused in a way which could only be detected at run-time")
ERRORTYPE_DEFINE(BadCPUType,                            InvalidRequestExitCode,         "The executable in question does not support the current CPU")
ERRORTYPE_DEFINE(MalformedExecutableOrSharedLibrary,    InvalidRequestExitCode,         "The executable or shared library in question was malformed.")
ERRORTYPE_DEFINE(MalformedMachObject,                   InvalidRequestExitCode,         "The Mach Object file in question was malformed.")
ERRORTYPE_DEFINE(DeviceError,                           OtherErrorExitCode,             "A device error has occured.")
ERRORTYPE_DEFINE(NoSuchPolicy,                          InvalidRequestExitCode,         "No such policy registered.")
ERRORTYPE_DEFINE(DevicePowerIsOff,                      OtherErrorExitCode,             "The device power is off.")
ERRORTYPE_DEFINE(FullInterfaceOutputQueue,              OtherErrorExitCode,             "Interface output queue is full.")
ERRORTYPE_DEFINE(SharedLibraryVersionMismatch,          OtherErrorExitCode,             "The version of the shared library on the system does not match the version which was expected.")
ERRORTYPE_DEFINE(IPSecProcessingFailure,                NetworkConectionErrorExitCode,  "IPsec subsystem error.") 
ERRORTYPE_DEFINE(NotPermittedInCapabilityMode,          InvalidRequestExitCode,         "The system call or operation is not permitted for capability mode processes.")
ERRORTYPE_DEFINE(IntegrityCheckFailed,                  OtherErrorExitCode,             "An integrity check failed and detected inconsistencies in data questioned.")
ERRORTYPE_DEFINE(CapabilitiesInsufficient,              InvalidRequestExitCode,         "An operation requires greater privilege than the capability allows.")
/* Folowing error codes are defined in the linux kernel, but not documented enough to make a consistent error message. Their messages and exit codes can change in the future. */
ERRORTYPE_DEFINE(InterruptedSyscallShouldBeRestarted,   OtherErrorExitCode,             "Interrupted system call should be restarted.")
ERRORTYPE_DEFINE(ChannelNumberOutOfRange,               OtherErrorExitCode,             "Channel number out of range.")
ERRORTYPE_DEFINE(Level2NotSynchronized,                 OtherErrorExitCode,             "Level 2 not synchronized.")
ERRORTYPE_DEFINE(Level3Halted,                          OtherErrorExitCode,             "Level 3 halted.")
ERRORTYPE_DEFINE(Level3Reset,                           OtherErrorExitCode,             "Level 3 reset.")
ERRORTYPE_DEFINE(LinkNumberOutOfRange,                  OtherErrorExitCode,             "Link number out of range.")
ERRORTYPE_DEFINE(ProtocolDriverNotAttached,             OtherErrorExitCode,             "Protocol driver not attached.")
ERRORTYPE_DEFINE(NoCSIStructure,                        OtherErrorExitCode,             "No CSI structure available.")
ERRORTYPE_DEFINE(Level2Halted,                          OtherErrorExitCode,             "Level 2 halted.")
ERRORTYPE_DEFINE(InvalidExchange,                       OtherErrorExitCode,             "Invalid exchange.")
ERRORTYPE_DEFINE(InvalidRequestDescriptor,              OtherErrorExitCode,             "Invalid request descriptor.")
ERRORTYPE_DEFINE(ExchangeFull,                          OtherErrorExitCode,             "Exchange full.")
ERRORTYPE_DEFINE(NoAnode,                               OtherErrorExitCode,             "No anode.")
ERRORTYPE_DEFINE(InvalidRequestCode,                    OtherErrorExitCode,             "Invalid request code.")
ERRORTYPE_DEFINE(InvalidSlot,                           OtherErrorExitCode,             "Invalid slot.")
ERRORTYPE_DEFINE(FileLockingDeadlock,                   OtherErrorExitCode,             "File locking deadlock.")
ERRORTYPE_DEFINE(BadFontFileFormat,                     OtherErrorExitCode,             "Bad font file format.")
ERRORTYPE_DEFINE(MachineIsNotOnTheNetwork,              OtherErrorExitCode,             "Machine is not on the network.")
ERRORTYPE_DEFINE(PackageNotInstalled,                   OtherErrorExitCode,             "Package not installed.")
ERRORTYPE_DEFINE(AdvertiseError,                        OtherErrorExitCode,             "Advertise error.")
ERRORTYPE_DEFINE(SrmountError,                          OtherErrorExitCode,             "Srmount error.")
ERRORTYPE_DEFINE(CommunicationErrorOnSend,              OtherErrorExitCode,             "Communication error on send.")
ERRORTYPE_DEFINE(RFSError,                              OtherErrorExitCode,             "RFS specyfic error.")
ERRORTYPE_DEFINE(NameNotUniqueOnNetwork,                OtherErrorExitCode,             "Name not unique on network.")
ERRORTYPE_DEFINE(FileDescriptorInBadState,              OtherErrorExitCode,             "File descriptor in bad state.")
ERRORTYPE_DEFINE(RemoteAddressChanged,                  OtherErrorExitCode,             "Remote address changed.")
ERRORTYPE_DEFINE(CannotAccessANeededSharedLibrary,      OtherErrorExitCode,             "Cannot access a needed shared library.")
ERRORTYPE_DEFINE(AccessingACorruptedSharedLibrary,      OtherErrorExitCode,             "Accessing a corrupted shared library.")
ERRORTYPE_DEFINE(DotLibSectionCorrupted,                OtherErrorExitCode,             ".lib section corrupted in a.out.")
ERRORTYPE_DEFINE(TooManySharedLibraries,                OtherErrorExitCode,             "An attempt was made to link too many shared libraries.")
ERRORTYPE_DEFINE(StreamsPipeError,                      OtherErrorExitCode,             "STREAMs pipe error.")
ERRORTYPE_DEFINE(StructureNeedsCleaning,                OtherErrorExitCode,             "Structure needs cleaning.")
ERRORTYPE_DEFINE(NotXENIXNamedTypeFile,                 OtherErrorExitCode,             "Not a XENIX named type file.")
ERRORTYPE_DEFINE(NoXENIXSemaphoresAvailable,            OtherErrorExitCode,             "No XENIX Semaphores available.")
ERRORTYPE_DEFINE(IsANamedTypeFile,                      OtherErrorExitCode,             "Is a named type file.")
ERRORTYPE_DEFINE(RemoteIOError,                         OtherErrorExitCode,             "Remote I/O error.")
ERRORTYPE_DEFINE(NoMediumFound,                         OtherErrorExitCode,             "No medium found.")
ERRORTYPE_DEFINE(WrongMediumType,                       OtherErrorExitCode,             "Wrong medium type.")
ERRORTYPE_DEFINE(RequiredKeyNotAvailable,               OtherErrorExitCode,             "Required key not available.")
ERRORTYPE_DEFINE(KeyHasExpired,                         OtherErrorExitCode,             "Key has expired.")
ERRORTYPE_DEFINE(KeyHasBeenRevoked,                     OtherErrorExitCode,             "Key has been revoked.")
ERRORTYPE_DEFINE(KeyWasRejectedByService,               OtherErrorExitCode,             "Key was rejected by service.")
ERRORTYPE_DEFINE(OperationPreventedByRFKILL,            OtherErrorExitCode,             "Operation not possible due to RF-kill.")
ERRORTYPE_DEFINE(MemoryPageHasHardwareError,            OtherErrorExitCode,             "Memory page has hardware error.")
ERRORTYPE_DEFINE(Async,                                 OtherErrorExitCode,             "Async") /* ERRNO used internaly by the DragonFlyBSD source that should NOT be used extrernaly as en error. */

ERRORTYPE_DEFINE(UnknownError,                          OtherErrorExitCode,             "Unknown error occured.")

/*
    - Linux - defined by kernel headers
    - DragonFlyBSD - defined by kernel headers
    - FreeBSD - defined by kernel headers
    - OpenBSD - defined by kernel headers
    - NetBSD - defined by kernel headers
    - MS-DOS && Win9x - defined by the libc
    - Windows NT - defined by the libc
    - OS/2 - defined by the libc
*/

#if defined(__WIN32)
const ___ERRNO_BIND ___errno_binds[] = {
    { E2BIG,            ERR(ArgumentListTooBig) },
    { EAGAIN,           ERR(ResourceUnavailable) },
    { EBADF,            ERR(BadFileDescriptor) },
    { EBUSY,            ERR(DeviceOrResourceBusy) },
    { ECHILD,           ERR(NoChildProcesses) },
    { EDEADLK,          ERR(ResourceDeadlockAvoided) },
    { EDEADLOCK,        ERR(ResourceDeadlockAvoided) },
    { EDOM,             ERR(NumericalArgumentOutOfDomain) },
    { EEXIST,           ERR(FileExists) },
    { EFAULT,           ERR(BadAddress) },
    { EFBIG,            ERR(FileTooLarge) },
    { EILSEQ,           ERR(WrongOrIncompleteMultibyteOrWideChar) },
    { EINTR,            ERR(InterruptedSysCall) },
    { EINVAL,           ERR(InvalidArgument) },
    { EIO,              ERR(IOError) },
    { EISDIR,           ERR(IsADirectory) },
    { EMFILE,           ERR(TooManyOpenedFiles) },
    { EMLINK,           ERR(TooManyLinks) },
    { ENAMETOOLONG,     ERR(FileNameTooLong) },
    { ENFILE,           ERR(TooManyOpenedFilesInSystem) },
    { ENODEV,           ERR(DeviceNotFound) },
    { ENOENT,           ERR(FileDoesNotExist) },
    { ENOEXEC,          ERR(ExecFormatError) },
    { ENOLCK,           ERR(NoLocksAvailable) },
    { ENOMEM,           ERR(NotEnoughMemory) },
    { ENOSPC,           ERR(NoSpaceLeftOnDevice) },
    { ENOSYS,           ERR(FunctionNotImplemented) },
    { ENOTDIR,          ERR(NotADirectory) },
    { ENOTEMPTY,        ERR(DirectoryNotEmpty) },
    { ENOTTY,           ERR(InappropriateIoctlForDevice) },
    { ENXIO,            ERR(DeviceNotFoundOrAddress) },
    { EPERM,            ERR(PermissionNotPermitted) }
    { EPIPE,            ERR(BrokenPipe) },
    { ERANGE,           ERR(NumericalArgumentOutOfDomain) },
    { EROFS,            ERR(ReadOnlyFileSystem) },
    { ESPIPE,           ERR(IllegalSeek) },
    { ESRCH,            ERR(ProcessNotFound) },
    { EXDEV,            ERR(InvalidCrossDeviceLink) },
    { STRUNCATE,        ERR(TruncatedString) },
    { EADDRINUSE,       ERR(AddressAlreadyInUse) },
    { EADDRNOTAVAIL,    ERR(CannotAssignRequestedAddress) },
    { EAFNOSUPPORT,     ERR(AddressFamilyNotSupportedByProtocol) },
    { EALREADY,         ERR(AlreadyInProgress) },
    { EBADMSG,          ERR(BadMessage) },
    { ECANCELED,        ERR(OperationCanceled) },
    { ECONNABORTED,     ERR(SoftwareCausedConnectionAbort) },
    { ECONNREFUSED,     ERR(ConnectionRefused) },
    { ECONNRESET,       ERR(ConnectionResetByPeer) },
    { EDESTADDRREQ,     ERR(DestinationAddressRequired) },
    { EHOSTUNREACH,     ERR(NetworkIsUnreachable) },
    { EIDRM,            ERR(IdentifierRemoved) },
    { EINPROGRESS,      ERR(AlreadyInProgress) },
    { EISCONN,          ERR(SocketIsAlreadyConnected) },
    { ELOOP,            ERR(TooManyLevelsOfSymbolicLinks) },
    { EMSGSIZE,         ERR(MessageTooLong) },
    { ENETDOWN,         ERR(NetworkIsDown) },
    { ENETRESET,        ERR(NetworkDroppedConnectionOnReset) },
    { ENETUNREACH,      ERR(NetworkIsUnreachable) },
    { ENOBUFS,          ERR(NoBufferSpaceAvailable) },
    { ENODATA,          ERR(NoDataAvailable) },
    { ENOLINK,          ERR(LinkHasBeenServed) },
    { ENOMSG,           ERR(NoMessageOfDesiredType) },
    { ENOPROTOOPT,      ERR(ProtocolNotAvailable) }, 
    { ENOSR,            ERR(OutOfStreamsResources) },
    { ENOSTR,           ERR(NotAStream) },
    { ENOTCONN,         ERR(SocketIsNotConnected) },
    { ENOTRECOVERABLE,  ERR(MutexStateNotRecoverable) },
    { ENOTSOCK,         ERR(SocketOperationOnNonSocket) },
    { ENOTSUP,          ERR(NotSupported) },
    { EOPNOTSUPP,       ERR(NotSupported) }
    { EOVERFLOW,        ERR(ValueTooLarge) },
    { EOWNERDEAD,       ERR(OwnerDied) },
    { EPROTO,           ERR(ProtocolError) },
    { EPROTONOSUPPORT,  ERR(ProtocolNotSupported) },
    { EPROTOTYPE,       ERR(WrongProtocolForSocket) },
    { ETIME,            ERR(TimerExpired) },
    { ETIMEDOUT,        ERR(ConnectionTimedOut) },
    { ETXTBSY,          ERR(TextSegmentBusy) },
    { EWOULDBLOCK,      ERR(ResourceUnavailable) },
};

const int ___errno_binds_size = sizeof(___errno_binds);

#elif defined(__DragonFly__)

#include <sys/errno.h>

const ___ERRNO_BIND ___errno_binds[] = {
    { EMULTIHOP,        ERR(MultihopAttempted) },
    { EAFNOSUPPORT,     ERR(AddressFamilyNotSupportedByProtocol) },
    { EACCES,           ERR(PermissionDenied) },
    { EDESTADDRREQ,     ERR(DestinationAddressRequired) },
    { EILSEQ,           ERR(WrongOrIncompleteMultibyteOrWideChar) },
    { ESPIPE,           ERR(IllegalSeek) },
    { EMLINK,           ERR(TooManyLinks) },
    { EPROGUNAVAIL,     ERR(RPCProgramNotAvailable },
    { EOWNERDEAD,       ERR(OwnerDied) },
    { ERANGE,           ERR(NumericalArgumentOutOfDomain) },
    { EBADF,            ERR(BadFileDescriptor) },
    { ENOTTY,           ERR(InappropriateIoctlForDevice) },
    { ECANCELED,        ERR(OperationCanceled) },
    { ETXTBSY,          ERR(TextSegmentBusy) },
    { ENOMEM,           ERR(NotEnoughMemory) },
    { EINPROGRESS,      ERR(AlreadyInProgress) },
    { ENOTBLK,          ERR(NotABlockDevice) },
    { EPROTOTYPE,       ERR(WrongProtocolForSocket) },
    { ENOMSG,           ERR(NoMessageOfDesiredType) },
    { ERPCMISMATCH,     ERR(RpcVersionWrong) },
    { EALREADY,         ERR(AlreadyInProgress) },
    { ETIMEDOUT,        ERR(ConnectionTimedOut) },
    { ENEEDAUTH,        ERR(NeedAuthenticator) },
    { EINTR,            ERR(InterruptedSysCall) },
    { ENOLINK,          ERR(LinkHasBeenServed) },
    { EPERM,            ERR(PermissionNotPermitted) }
    { ENETDOWN,         ERR(NetworkIsDown) },
    { ESTALE,           ERR(StaleNFSFileHandle) },
    { EAUTH,            ERR(AuthenticationError) },
    { ECHILD,           ERR(NoChildProcesses) },
    { EPIPE,            ERR(BrokenPipe) },
    { ENOATTR,          ERR(AttributeNotFound) },
    { EBADMSG,          ERR(BadMessage) },
    { EREMOTE,          ERR(NFSObjectIsRemote) },
    { ETOOMANYREFS,     ERR(TooManyReferences) },
    { ENOTEMPTY,        ERR(DirectoryNotEmpty) },
    { EADDRINUSE,       ERR(AddressAlreadyInUse) },
    { ENETRESET,        ERR(NetworkDroppedConnectionOnReset) },
    { EISDIR,           ERR(IsADirectory) },
    { EIDRM,            ERR(IdentifierRemoved) },
    { ENOTSOCK,         ERR(SocketOperationOnNonSocket) },
    { EHOSTUNREACH,     ERR(NetworkIsUnreachable) },
    { EDOOFUS,          ERR(CodeAbuse) },
    { ELOOP,            ERR(TooManyLevelsOfSymbolicLinks) },
    { EINVAL,           ERR(InvalidArgument) },
    { ESHUTDOWN,        ERR(CannotSendAfterSocketShutdown) },
    { ENOMEDIUM,        ERR(NoMediumFound) },
    { EOVERFLOW,        ERR(ValueTooLarge) },
    { EBUSY,            ERR(DeviceOrResourceBusy) },
    { EPROCLIM,         ERR(TooManyProcesses) },
    { EPROTO,           ERR(ProtocolError) },
    { ENODEV,           ERR(DeviceNotFound) },
    { EROFS,            ERR(ReadOnlyFileSystem) },
    { E2BIG,            ERR(ArgumentListTooBig) },
    { EDEADLK,          ERR(ResourceDeadlockAvoided) },
    { ENOTDIR,          ERR(NotADirectory) },
    { ECONNRESET,       ERR(ConnectionResetByPeer) },
    { ENXIO,            ERR(DeviceNotFoundOrAddress) },
    { EBADRPC,          ERR(RPCStructIsBad) },
    { ENAMETOOLONG,     ERR(FileNameTooLong) },
    { ESOCKTNOSUPPORT,  ERR(SocketTypeNotSupported) },
    { EADDRNOTAVAIL,    ERR(CannotAssignRequestedAddress) },
    { EPROTONOSUPPORT,  ERR(ProtocolNotSupported) },
    { ENOTRECOVERABLE,  ERR(MutexStateNotRecoverable) },
    { EIO,              ERR(IOError) },
    { ENETUNREACH,      ERR(NetworkIsUnreachable) },
    { EXDEV,            ERR(InvalidCrossDeviceLink) },
    { EDQUOT,           ERR(DiskQuotaExceeded) },
    { ENOSPC,           ERR(NoSpaceLeftOnDevice) },
    { EPROCUNAVAIL,     ERR(BadRPCProcedureForProgram) },
    { ENOEXEC,          ERR(ExecFormatError) },
    { EMSGSIZE,         ERR(MessageTooLong) },
    { EFTYPE,           ERR(InappropriateFileTypeOrFormat) },
    { EASYNC,           ERR(Async) },
    { EDOM,             ERR(NumericalArgumentOutOfDomain) },
    { EFBIG,            ERR(FileTooLarge) },
    { ESRCH,            ERR(ProcessNotFound) },
    { EHOSTDOWN,        ERR(HostIsDown) },
    { ENOLCK,           ERR(NoLocksAvailable) },
    { ENFILE,           ERR(TooManyOpenedFilesInSystem) },
    { ENOSYS,           ERR(FunctionNotImplemented) },
    { ENOTCONN,         ERR(SocketIsNotConnected) },
    { EPFNOSUPPORT,     ERR(ProtocolFamilyNotSupported) },
    { ENOTSUP,          ERR(NotSupported) },
    { ECONNABORTED,     ERR(SoftwareCausedConnectionAbort) },
    { EISCONN,          ERR(SocketIsAlreadyConnected) },
    { EUSERS,           ERR(TooManyUsers) },
    { ENOPROTOOPT,      ERR(ProtocolNotAvailable) }, 
    { EMFILE,           ERR(TooManyOpenedFiles) },
    { ENOBUFS,          ERR(NoBufferSpaceAvailable) },
    { EFAULT,           ERR(BadAddress) },
    { EWOULDBLOCK,      ERR(ResourceUnavailable) },
    { ECONNREFUSED,     ERR(ConnectionRefused) },
    { EAGAIN,           ERR(ResourceUnavailable) },
    { EEXIST,           ERR(FileExists) },
    { EPROGMISMATCH,    ERR(RPCProgramVersionWrong) },
    { ENOENT,           ERR(FileDoesNotExist) },
    { EOPNOTSUPP,       ERR(NotSupported) }
};

const int ___errno_binds_size = sizeof(___errno_binds);

#elif (defined(__APPLE__) && defined(__MACH__))

const ___ERRNO_BIND ___errno_binds[] = {
    { E2BIG,            ERR(ArgumentListTooBig) },
    { EACCES,           ERR(PermissionDenied) },
    { EADDRINUSE,       ERR(AddressAlreadyInUse) },
    { EADDRNOTAVAIL,    ERR(CannotAssignRequestedAddress) },
    { EAFNOSUPPORT,     ERR(AddressFamilyNotSupportedByProtocol) },
    { EAGAIN,           ERR(ResourceUnavailable) },
    { EALREADY,         ERR(AlreadyInProgress) },
    { EAUTH,            ERR(AuthenticationError) },
    { EBADARCH,         ERR(BadCPUType) },
    { EBADEXEC,         ERR(MalformedExecutableOrSharedLibrary) },
    { EBADF,            ERR(BadFileDescriptor) },
    { EBADMACHO,        ERR(MalformedMachObject) },
    { EBADMSG,          ERR(BadMessage) },
    { EBADRPC,          ERR(RPCStructIsBad) },
    { EBUSY,            ERR(DeviceOrResourceBusy) },
    { ECANCELED,        ERR(OperationCanceled) },
    { ECHILD,           ERR(NoChildProcesses) },
    { ECONNABORTED,     ERR(SoftwareCausedConnectionAbort) },
    { ECONNREFUSED,     ERR(ConnectionRefused) },
    { ECONNRESET,       ERR(ConnectionResetByPeer) },
    { EDEADLK,          ERR(ResourceDeadlockAvoided) },
    { EDESTADDRREQ,     ERR(DestinationAddressRequired) },
    { EDEVERR,          ERR(DeviceError) },
    { EDOM,             ERR(NumericalArgumentOutOfDomain) },
    { EDQUOT,           ERR(DiskQuotaExceeded) },
    { EEXIST,           ERR(FileExists) },
    { EFAULT,           ERR(BadAddress) },
    { EFBIG,            ERR(FileTooLarge) },
    { EFTYPE,           ERR(InappropriateFileTypeOrFormat) },
    { EHOSTDOWN,        ERR(HostIsDown) },
    { EHOSTUNREACH,     ERR(NetworkIsUnreachable) },
    { EIDRM,            ERR(IdentifierRemoved) },
    { EILSEQ,           ERR(WrongOrIncompleteMultibyteOrWideChar) },
    { EINPROGRESS,      ERR(AlreadyInProgress) },
    { EINTR,            ERR(InterruptedSysCall) },
    { EINVAL,           ERR(InvalidArgument) },
    { EIO,              ERR(IOError) },
    { EISCONN,          ERR(SocketIsAlreadyConnected) },
    { EISDIR,           ERR(IsADirectory) },
    { ELOOP,            ERR(TooManyLevelsOfSymbolicLinks) },
    { EMFILE,           ERR(TooManyOpenedFiles) },
    { EMLINK,           ERR(TooManyLinks) },
    { EMSGSIZE,         ERR(MessageTooLong) },
    { EMULTIHOP,        ERR(MultihopAttempted) },
    { ENAMETOOLONG,     ERR(FileNameTooLong) },
    { ENEEDAUTH,        ERR(NeedAuthenticator) },
    { ENETDOWN,         ERR(NetworkIsDown) },
    { ENETRESET,        ERR(NetworkDroppedConnectionOnReset) },
    { ENETUNREACH,      ERR(NetworkIsUnreachable) },
    { ENFILE,           ERR(TooManyOpenedFilesInSystem) },
    { ENOATTR,          ERR(AttributeNotFound) },
    { ENOBUFS,          ERR(NoBufferSpaceAvailable) },
    { ENODATA,          ERR(NoDataAvailable) },
    { ENODEV,           ERR(DeviceNotFound) },
    { ENOENT,           ERR(FileDoesNotExist) },
    { ENOEXEC,          ERR(ExecFormatError) },
    { ENOLCK,           ERR(NoLocksAvailable) },
    { ENOLINK,          ERR(LinkHasBeenServed) },
    { ENOMEM,           ERR(NotEnoughMemory) },
    { ENOMSG,           ERR(NoMessageOfDesiredType) },
    { ENOPOLICY,        ERR(NoSuchPolicy) },
    { ENOPROTOOPT,      ERR(ProtocolNotAvailable) }, 
    { ENOSPC,           ERR(NoSpaceLeftOnDevice) },
    { ENOSR,            ERR(OutOfStreamsResources) },
    { ENOSTR,           ERR(NotAStream) },
    { ENOSYS,           ERR(FunctionNotImplemented) },
    { ENOTBLK,          ERR(NotABlockDevice) },
    { ENOTCONN,         ERR(SocketIsNotConnected) },
    { ENOTDIR,          ERR(NotADirectory) },
    { ENOTEMPTY,        ERR(DirectoryNotEmpty) },
    { ENOTRECOVERABLE,  ERR(MutexStateNotRecoverable) },
    { ENOTSOCK,         ERR(SocketOperationOnNonSocket) },
    { ENOTSUP,          ERR(NotSupported) },
    { ENOTTY,           ERR(InappropriateIoctlForDevice) },
    { ENXIO,            ERR(DeviceNotFoundOrAddress) },
    { EOPNOTSUPP,       ERR(NotSupported) },
    { EOVERFLOW,        ERR(ValueTooLarge) },
    { EOWNERDEAD,       ERR(OwnerDied) },
    { EPERM,            ERR(PermissionNotPermitted) }
    { EPFNOSUPPORT,     ERR(ProtocolFamilyNotSupported) },
    { EPIPE,            ERR(BrokenPipe) },
    { EPROCLIM,         ERR(TooManyProcesses) },
    { EPROCUNAVAIL,     ERR(BadRPCProcedureForProgram) },
    { EPROGMISMATCH,    ERR(RPCProgramVersionWrong) },
    { EPROGUNAVAIL,     ERR(RPCProgramNotAvailable },
    { EPROTO,           ERR(ProtocolError) },
    { EPROTONOSUPPORT,  ERR(ProtocolNotSupported) },
    { EPROTOTYPE,       ERR(WrongProtocolForSocket) },
    { EPWROFF,          ERR(DevicePowerIsOff) },
    { EQFULL,           ERR(FullInterfaceOutputQueue) },
    { ERANGE,           ERR(NumericalArgumentOutOfDomain) },
    { EREMOTE,          ERR(NFSObjectIsRemote) },
    { EROFS,            ERR(ReadOnlyFileSystem) },
    { ERPCMISMATCH,     ERR(RpcVersionWrong) },
    { ESHLIBVERS,       ERR(SharedLibraryVersionMismatch) },
    { ESHUTDOWN,        ERR(CannotSendAfterSocketShutdown) },
    { ESOCKTNOSUPPORT,  ERR(SocketTypeNotSupported) },
    { ESPIPE,           ERR(IllegalSeek) },
    { ESRCH,            ERR(ProcessNotFound) },
    { ESTALE,           ERR(StaleNFSFileHandle) },
    { ETIME,            ERR(TimerExpired) },
    { ETIMEDOUT,        ERR(ConnectionTimedOut) },
    { ETOOMANYREFS,     ERR(TooManyReferences) },
    { ETXTBSY,          ERR(TextSegmentBusy) },
    { EUSERS,           ERR(TooManyUsers) },
    { EWOULDBLOCK,      ERR(ResourceUnavailable) },
    { EXDEV,            ERR(InvalidCrossDeviceLink) }
};

const int ___errno_binds_size = sizeof(___errno_binds);

#elif defined(__OpenBSD__)

const ___ERRNO_BIND ___errno_binds[] = {
    { E2BIG,            ERR(ArgumentListTooBig) },
    { EACCES,           ERR(PermissionDenied) },
    { EADDRINUSE,       ERR(AddressAlreadyInUse) },
    { EADDRNOTAVAIL,    ERR(CannotAssignRequestedAddress) },
    { EAFNOSUPPORT,     ERR(AddressFamilyNotSupportedByProtocol) },
    { EAGAIN,           ERR(ResourceUnavailable) },
    { EALREADY,         ERR(AlreadyInProgress) },
    { EAUTH,            ERR(AuthenticationError) },
    { EBADF,            ERR(BadFileDescriptor) },
    { EBADMSG,          ERR(BadMessage) },
    { EBADRPC,          ERR(RPCStructIsBad) },
    { EBUSY,            ERR(DeviceOrResourceBusy) },
    { ECANCELED,        ERR(OperationCanceled) },
    { ECHILD,           ERR(NoChildProcesses) },
    { ECONNABORTED,     ERR(SoftwareCausedConnectionAbort) },
    { ECONNREFUSED,     ERR(ConnectionRefused) },
    { ECONNRESET,       ERR(ConnectionResetByPeer) },
    { EDEADLK,          ERR(ResourceDeadlockAvoided) },
    { EDESTADDRREQ,     ERR(DestinationAddressRequired) },
    { EDOM,             ERR(NumericalArgumentOutOfDomain) },
    { EDQUOT,           ERR(DiskQuotaExceeded) },
    { EEXIST,           ERR(FileExists) },
    { EFAULT,           ERR(BadAddress) },
    { EFBIG,            ERR(FileTooLarge) },
    { EFTYPE,           ERR(InappropriateFileTypeOrFormat) },
    { EHOSTDOWN,        ERR(HostIsDown) },
    { EHOSTUNREACH,     ERR(NetworkIsUnreachable) },
    { EIDRM,            ERR(IdentifierRemoved) },
    { EILSEQ,           ERR(WrongOrIncompleteMultibyteOrWideChar) },
    { EINPROGRESS,      ERR(AlreadyInProgress) },
    { EINTR,            ERR(InterruptedSysCall) },
    { EINVAL,           ERR(InvalidArgument) },
    { EIO,              ERR(IOError) },
    { EIPSEC,           ERR(IPSecProcessingFailure) },
    { EISCONN,          ERR(SocketIsAlreadyConnected) },
    { EISDIR,           ERR(IsADirectory) },
    { ELOOP,            ERR(TooManyLevelsOfSymbolicLinks) },
    { EMEDIUMTYPE,      ERR(WrongMediumType) },
    { EMFILE,           ERR(TooManyOpenedFiles) },
    { EMLINK,           ERR(TooManyLinks) },
    { EMSGSIZE,         ERR(MessageTooLong) },
    { ENAMETOOLONG,     ERR(FileNameTooLong) },
    { ENEEDAUTH,        ERR(NeedAuthenticator) },
    { ENETDOWN,         ERR(NetworkIsDown) },
    { ENETRESET,        ERR(NetworkDroppedConnectionOnReset) },
    { ENETUNREACH,      ERR(NetworkIsUnreachable) },
    { ENFILE,           ERR(TooManyOpenedFilesInSystem) },
    { ENOATTR,          ERR(AttributeNotFound) },
    { ENOBUFS,          ERR(NoBufferSpaceAvailable) },
    { ENODEV,           ERR(DeviceNotFound) },
    { ENOENT,           ERR(FileDoesNotExist) },
    { ENOEXEC,          ERR(ExecFormatError) },
    { ENOLCK,           ERR(NoLocksAvailable) },
    { ENOMEDIUM,        ERR(NoMediumFound) },
    { ENOMEM,           ERR(NotEnoughMemory) },
    { ENOMSG,           ERR(NoMessageOfDesiredType) },
    { ENOPROTOOPT,      ERR(ProtocolNotAvailable) }, 
    { ENOSPC,           ERR(NoSpaceLeftOnDevice) },
    { ENOSYS,           ERR(FunctionNotImplemented) },
    { ENOTBLK,          ERR(NotABlockDevice) },
    { ENOTCONN,         ERR(SocketIsNotConnected) },
    { ENOTDIR,          ERR(NotADirectory) },
    { ENOTEMPTY,        ERR(DirectoryNotEmpty) },
    { ENOTRECOVERABLE,  ERR(MutexStateNotRecoverable) },
    { ENOTSOCK,         ERR(SocketOperationOnNonSocket) },
    { ENOTSUP,          ERR(NotSupported) },
    { ENOTTY,           ERR(InappropriateIoctlForDevice) },
    { ENXIO,            ERR(DeviceNotFoundOrAddress) },
    { EOPNOTSUPP,       ERR(NotSupported) },
    { EOVERFLOW,        ERR(ValueTooLarge) },
    { EOWNERDEAD,       ERR(OwnerDied) },
    { EPERM,            ERR(PermissionNotPermitted) }
    { EPFNOSUPPORT,     ERR(ProtocolFamilyNotSupported) },
    { EPIPE,            ERR(BrokenPipe) },
    { EPROCLIM,         ERR(TooManyProcesses) },
    { EPROCUNAVAIL,     ERR(BadRPCProcedureForProgram) },
    { EPROGMISMATCH,    ERR(RPCProgramVersionWrong) },
    { EPROGUNAVAIL,     ERR(RPCProgramNotAvailable },
    { EPROTO,           ERR(ProtocolError) },
    { EPROTONOSUPPORT,  ERR(ProtocolNotSupported) },
    { EPROTOTYPE,       ERR(WrongProtocolForSocket) },
    { ERANGE,           ERR(NumericalArgumentOutOfDomain) },
    { EREMOTE,          ERR(NFSObjectIsRemote) },
    { EROFS,            ERR(ReadOnlyFileSystem) },
    { ERPCMISMATCH,     ERR(RpcVersionWrong) },
    { ESHUTDOWN,        ERR(CannotSendAfterSocketShutdown) },
    { ESOCKTNOSUPPORT,  ERR(SocketTypeNotSupported) },
    { ESPIPE,           ERR(IllegalSeek) },
    { ESRCH,            ERR(ProcessNotFound) },
    { ESTALE,           ERR(StaleNFSFileHandle) },
    { ETIMEDOUT,        ERR(ConnectionTimedOut) },
    { ETOOMANYREFS,     ERR(TooManyReferences) },
    { ETXTBSY,          ERR(TextSegmentBusy) },
    { EUSERS,           ERR(TooManyUsers) },
    { EWOULDBLOCK,      ERR(ResourceUnavailable) },
    { EXDEV,            ERR(InvalidCrossDeviceLink) }
};

const int ___errno_binds_size = sizeof(___errno_binds);

#elif defined(__FreeBSD__)

const ___ERRNO_BIND ___errno_binds[] = {
    { E2BIG,            ERR(ArgumentListTooBig) },
    { EACCES,           ERR(PermissionDenied) },
    { EADDRINUSE,       ERR(AddressAlreadyInUse) },
    { EADDRNOTAVAIL,    ERR(CannotAssignRequestedAddress) },
    { EAFNOSUPPORT,     ERR(AddressFamilyNotSupportedByProtocol) },
    { EAGAIN,           ERR(ResourceUnavailable) },
    { EALREADY,         ERR(AlreadyInProgress) },
    { EAUTH,            ERR(AuthenticationError) },
    { EBADF,            ERR(BadFileDescriptor) },
    { EBADMSG,          ERR(BadMessage) },
    { EBADRPC,          ERR(RPCStructIsBad) },
    { EBUSY,            ERR(DeviceOrResourceBusy) },
    { ECANCELED,        ERR(OperationCanceled) },
    { ECAPMODE,         ERR(NotPermittedInCapabilityMode) },
    { ECHILD,           ERR(NoChildProcesses) },
    { ECONNABORTED,     ERR(SoftwareCausedConnectionAbort) },
    { ECONNREFUSED,     ERR(ConnectionRefused) },
    { ECONNRESET,       ERR(ConnectionResetByPeer) },
    { EDEADLK,          ERR(ResourceDeadlockAvoided) },
    { EDESTADDRREQ,     ERR(DestinationAddressRequired) },
    { EDOM,             ERR(NumericalArgumentOutOfDomain) },
    { EDOOFUS,          ERR(CodeAbuse) },
    { EDQUOT,           ERR(DiskQuotaExceeded) },
    { EEXIST,           ERR(FileExists) },
    { EFAULT,           ERR(BadAddress) },
    { EFBIG,            ERR(FileTooLarge) },
    { EFTYPE,           ERR(InappropriateFileTypeOrFormat) },
    { EHOSTDOWN,        ERR(HostIsDown) },
    { EHOSTUNREACH,     ERR(NetworkIsUnreachable) },
    { EIDRM,            ERR(IdentifierRemoved) },
    { EILSEQ,           ERR(WrongOrIncompleteMultibyteOrWideChar) },
    { EINPROGRESS,      ERR(AlreadyInProgress) },
    { EINTEGRITY,       ERR(IntegrityCheckFailed) },
    { EINTR,            ERR(InterruptedSysCall) },
    { EINVAL,           ERR(InvalidArgument) },
    { EIO,              ERR(IOError) },
    { EISCONN,          ERR(SocketIsAlreadyConnected) },
    { EISDIR,           ERR(IsADirectory) },
    { ELOOP,            ERR(TooManyLevelsOfSymbolicLinks) },
    { EMFILE,           ERR(TooManyOpenedFiles) },
    { EMLINK,           ERR(TooManyLinks) },
    { EMSGSIZE,         ERR(MessageTooLong) },
    { EMULTIHOP,        ERR(MultihopAttempted) },
    { ENAMETOOLONG,     ERR(FileNameTooLong) },
    { ENEEDAUTH,        ERR(NeedAuthenticator) },
    { ENETDOWN,         ERR(NetworkIsDown) },
    { ENETRESET,        ERR(NetworkDroppedConnectionOnReset) },
    { ENETUNREACH,      ERR(NetworkIsUnreachable) },
    { ENFILE,           ERR(TooManyOpenedFilesInSystem) },
    { ENOATTR,          ERR(AttributeNotFound) },
    { ENOBUFS,          ERR(NoBufferSpaceAvailable) },
    { ENODEV,           ERR(DeviceNotFound) },
    { ENOENT,           ERR(FileDoesNotExist) },
    { ENOEXEC,          ERR(ExecFormatError) },
    { ENOLCK,           ERR(NoLocksAvailable) },
    { ENOLINK,          ERR(LinkHasBeenServed) },
    { ENOMEM,           ERR(NotEnoughMemory) },
    { ENOMSG,           ERR(NoMessageOfDesiredType) },
    { ENOPROTOOPT,      ERR(ProtocolNotAvailable) }, 
    { ENOSPC,           ERR(NoSpaceLeftOnDevice) },
    { ENOSYS,           ERR(FunctionNotImplemented) },
    { ENOTBLK,          ERR(NotABlockDevice) },
    { ENOTCAPABLE,      ERR(CapabilitiesInsufficient) },
    { ENOTCONN,         ERR(SocketIsNotConnected) },
    { ENOTDIR,          ERR(NotADirectory) },
    { ENOTEMPTY,        ERR(DirectoryNotEmpty) },
    { ENOTRECOVERABLE,  ERR(MutexStateNotRecoverable) },
    { ENOTSOCK,         ERR(SocketOperationOnNonSocket) },
    { ENOTSUP,          ERR(NotSupported) },
    { ENOTTY,           ERR(InappropriateIoctlForDevice) },
    { ENXIO,            ERR(DeviceNotFoundOrAddress) },
    { EOPNOTSUPP,       ERR(NotSupported) },
    { EOVERFLOW,        ERR(ValueTooLarge) },
    { EOWNERDEAD,       ERR(OwnerDied) },
    { EPERM,            ERR(PermissionNotPermitted) }
    { EPFNOSUPPORT,     ERR(ProtocolFamilyNotSupported) },
    { EPIPE,            ERR(BrokenPipe) },
    { EPROCLIM,         ERR(TooManyProcesses) },
    { EPROCUNAVAIL,     ERR(BadRPCProcedureForProgram) },
    { EPROGMISMATCH,    ERR(RPCProgramVersionWrong) },
    { EPROGUNAVAIL,     ERR(RPCProgramNotAvailable },
    { EPROTO,           ERR(ProtocolError) },
    { EPROTONOSUPPORT,  ERR(ProtocolNotSupported) },
    { EPROTOTYPE,       ERR(WrongProtocolForSocket) },
    { ERANGE,           ERR(NumericalArgumentOutOfDomain) },
    { EREMOTE,          ERR(NFSObjectIsRemote) },
    { EROFS,            ERR(ReadOnlyFileSystem) },
    { ERPCMISMATCH,     ERR(RpcVersionWrong) },
    { ESHUTDOWN,        ERR(CannotSendAfterSocketShutdown) },
    { ESOCKTNOSUPPORT,  ERR(SocketTypeNotSupported) },
    { ESPIPE,           ERR(IllegalSeek) },
    { ESRCH,            ERR(ProcessNotFound) },
    { ESTALE,           ERR(StaleNFSFileHandle) },
    { ETIMEDOUT,        ERR(ConnectionTimedOut) },
    { ETOOMANYREFS,     ERR(TooManyReferences) },
    { ETXTBSY,          ERR(TextSegmentBusy) },
    { EUSERS,           ERR(TooManyUsers) },
    { EWOULDBLOCK,      ERR(ResourceUnavailable) },
    { EXDEV,            ERR(InvalidCrossDeviceLink) }
};

const int ___errno_binds_size = sizeof(___errno_binds);
#elif defined(__NetBSD__)

const ___ERRNO_BIND ___errno_binds[] = {
    { E2BIG,            ERR(ArgumentListTooBig) },
    { EAFNOSUPPORT,     ERR(AddressFamilyNotSupportedByProtocol) },
    { EACCES,           ERR(PermissionDenied) },
    { EDESTADDRREQ,     ERR(DestinationAddressRequired) },
    { EILSEQ,           ERR(WrongOrIncompleteMultibyteOrWideChar) },
    { ESPIPE,           ERR(IllegalSeek) },
    { EMLINK,           ERR(TooManyLinks) },
    { EREMOTE,          ERR(NFSObjectIsRemote) },
    { EPROGUNAVAIL,     ERR(RPCProgramNotAvailable },
    { EOWNERDEAD,       ERR(OwnerDied) },
    { ENOTTY,           ERR(InappropriateIoctlForDevice) },
    { EBADF,            ERR(BadFileDescriptor) },
    { ERANGE,           ERR(NumericalArgumentOutOfDomain) },
    { ECANCELED,        ERR(OperationCanceled) },
    { ETXTBSY,          ERR(TextSegmentBusy) },
    { ENOMEM,           ERR(NotEnoughMemory) },
    { EINPROGRESS,      ERR(AlreadyInProgress) },
    { ENOTEMPTY,        ERR(DirectoryNotEmpty) },
    { ENOTBLK,          ERR(NotABlockDevice) },
    { EPROTOTYPE,       ERR(WrongProtocolForSocket) },
    { ENOMSG,           ERR(NoMessageOfDesiredType) },
    { ERPCMISMATCH,     ERR(RpcVersionWrong) },
    { EALREADY,         ERR(AlreadyInProgress) },
    { EADDRINUSE,       ERR(AddressAlreadyInUse) },
    { ETIMEDOUT,        ERR(ConnectionTimedOut) },
    { ENEEDAUTH,        ERR(NeedAuthenticator) },
    { ENODATA,          ERR(NoDataAvailable) },
    { EINTR,            ERR(InterruptedSysCall) },
    { ENOLINK,          ERR(LinkHasBeenServed) },
    { EPERM,            ERR(PermissionNotPermitted) },
    { ESTALE,           ERR(StaleNFSFileHandle) },
    { ENOTSOCK,         ERR(SocketOperationOnNonSocket) },
    { ENOSR,            ERR(OutOfStreamsResources) },
    { EAUTH,            ERR(AuthenticationError) },
    { ECHILD,           ERR(NoChildProcesses) },
    { EPIPE,            ERR(BrokenPipe) },
    { ENOATTR,          ERR(AttributeNotFound) },
    { ENOTDIR,          ERR(NotADirectory) },
    { EBADMSG,          ERR(BadMessage) },
    { ETOOMANYREFS,     ERR(TooManyReferences) },
    { EPFNOSUPPORT,     ERR(ProtocolFamilyNotSupported) },
    { EPROCUNAVAIL,     ERR(BadRPCProcedureForProgram) },
    { ENETRESET,        ERR(NetworkDroppedConnectionOnReset) },
    { EISDIR,           ERR(IsADirectory) },
    { EIDRM,            ERR(IdentifierRemoved) },
    { ECONNABORTED,     ERR(SoftwareCausedConnectionAbort) },
    { EHOSTUNREACH,     ERR(NetworkIsUnreachable) },
    { EINVAL,           ERR(InvalidArgument) },
    { ESHUTDOWN,        ERR(CannotSendAfterSocketShutdown) },
    { ENOSTR,           ERR(NotAStream) },
    { EOVERFLOW,        ERR(ValueTooLarge) },
    { EBUSY,            ERR(DeviceOrResourceBusy) },
    { EPROCLIM,         ERR(TooManyProcesses) },
    { EPROTO,           ERR(ProtocolError) },
    { ENODEV,           ERR(DeviceNotFound) },
    { EROFS,            ERR(ReadOnlyFileSystem) },
    { E2BIG,            ERR(ArgumentListTooBig) },
    { EDEADLK,          ERR(ResourceDeadlockAvoided) },
    { ECONNRESET,       ERR(ConnectionResetByPeer) },
    { ENXIO,            ERR(DeviceNotFoundOrAddress) },
    { EBADRPC,          ERR(RPCStructIsBad) },
    { ENAMETOOLONG,     ERR(FileNameTooLong) },
    { EAFNOSUPPORT,     ERR(AddressFamilyNotSupportedByProtocol) },
    { EADDRNOTAVAIL,    ERR(CannotAssignRequestedAddress) },
    { ETIME,            ERR(TimerExpired) },
    { EPROTONOSUPPORT,  ERR(ProtocolNotSupported) },
    { ENOTRECOVERABLE,  ERR(MutexStateNotRecoverable) },
    { EIO,              ERR(IOError) },
    { ENETUNREACH,      ERR(NetworkIsUnreachable) },
    { EXDEV,            ERR(InvalidCrossDeviceLink) },
    { EDQUOT,           ERR(DiskQuotaExceeded) },
    { ENOSPC,           ERR(NoSpaceLeftOnDevice) },
    { ENOEXEC,          ERR(ExecFormatError) },
    { EMSGSIZE,         ERR(MessageTooLong) },
    { EFTYPE,           ERR(InappropriateFileTypeOrFormat) },
    { EDOM,             ERR(NumericalArgumentOutOfDomain) },
    { EFBIG,            ERR(FileTooLarge) },
    { ESRCH,            ERR(ProcessNotFound) },
    { EHOSTDOWN,        ERR(HostIsDown) },
    { ENOLCK,           ERR(NoLocksAvailable) },
    { ENFILE,           ERR(TooManyOpenedFilesInSystem) },
    { ENOSYS,           ERR(FunctionNotImplemented) },
    { ENOTCONN,         ERR(SocketIsNotConnected) },
    { ENOTSUP,          ERR(NotSupported) },
    { EISCONN,          ERR(SocketIsAlreadyConnected) },
    { EUSERS,           ERR(TooManyUsers) },
    { ENETDOWN,         ERR(NetworkIsDown) },
    { ENOPROTOOPT,      ERR(ProtocolNotAvailable) }, 
    { EMFILE,           ERR(TooManyOpenedFiles) },
    { ELOOP,            ERR(TooManyLevelsOfSymbolicLinks) },
    { ENOBUFS,          ERR(NoBufferSpaceAvailable) },
    { EFAULT,           ERR(BadAddress) },
    { EWOULDBLOCK,      ERR(ResourceUnavailable) },
    { ECONNREFUSED,     ERR(ConnectionRefused) },
    { EAGAIN,           ERR(ResourceUnavailable) },
    { EEXIST,           ERR(FileExists) },
    { EPROGMISMATCH,    ERR(RPCProgramVersionWrong) },
    { ENOENT,           ERR(FileDoesNotExist) },
    { EOPNOTSUPP,       ERR(NotSupported) }
};

const int ___errno_binds_size = sizeof(___errno_binds);

#elif defined(__linux__)

#include <sys/errno.h>

const ___ERRNO_BIND ___errno_binds[] = {
    { E2BIG,            ERR(ArgumentListTooBig) },
    { EACCES,           ERR(PermissionDenied) },
    { EADDRINUSE,       ERR(AddressAlreadyInUse) },
    { EADDRNOTAVAIL,    ERR(CannotAssignRequestedAddress) },
    { EAFNOSUPPORT,     ERR(AddressFamilyNotSupportedByProtocol) },
    { EAGAIN,           ERR(ResourceUnavailable) },
    { EALREADY,         ERR(AlreadyInProgress) },
    { EBADE,            ERR(InvalidExchange) },
    { EBADF,            ERR(BadFileDescriptor) },
    { EBADFD,           ERR(FileDescriptorInBadState) },
    { EBADMSG,          ERR(BadMessage) },
    { EBADR,            ERR(InvalidRequestDescriptor) },
    { EBADRQC,          ERR(InvalidRequestCode) },
    { EBADSLT,          ERR(InvalidSlot) },
    { EBUSY,            ERR(DeviceOrResourceBusy) },
    { ECANCELED,        ERR(OperationCanceled) },
    { ECHILD,           ERR(NoChildProcesses) },
    { ECHRNG,           ERR(ChannelNumberOutOfRange) },
    { ECOMM,            ERR(CommunicationErrorOnSend) },
    { ECONNABORTED,     ERR(SoftwareCausedConnectionAbort) },
    { ECONNREFUSED,     ERR(ConnectionRefused) },
    { ECONNRESET,       ERR(ConnectionResetByPeer) },
    { EDEADLK,          ERR(ResourceDeadlockAvoided) },
    { EDESTADDRREQ,     ERR(DestinationAddressRequired) },
    { EDOM,             ERR(NumericalArgumentOutOfDomain) },
    { EDQUOT,           ERR(DiskQuotaExceeded) },
    { EEXIST,           ERR(FileExists) },
    { EFAULT,           ERR(BadAddress) },
    { EFBIG,            ERR(FileTooLarge) },
    { EHOSTDOWN,        ERR(HostIsDown) },
    { EHOSTUNREACH,     ERR(NetworkIsUnreachable) },
    { EIDRM,            ERR(IdentifierRemoved) },
    { EILSEQ,           ERR(WrongOrIncompleteMultibyteOrWideChar) },
    { EINPROGRESS,      ERR(AlreadyInProgress) },
    { EINTR,            ERR(InterruptedSysCall) },
    { EINVAL,           ERR(InvalidArgument) },
    { EIO,              ERR(IOError) },
    { EISCONN,          ERR(SocketIsAlreadyConnected) },
    { EISDIR,           ERR(IsADirectory) },
    { EISNAM,           ERR(IsANamedTypeFile) },
    { EKEYEXPIRED,      ERR(KeyHasExpired) },
    { EKEYREJECTED,     ERR(KeyWasRejectedByService) },
    { EKEYREVOKED,      ERR(KeyHasBeenRevoked) },
    { EL2HLT,           ERR(Level2Halted) },
    { EL2NSYNC,         ERR(Level2NotSynchronized) },
    { EL3HLT,           ERR(Level3Halted) },
    { EL3RST,           ERR(Level3Reset) },
    { ELIBACC,          ERR(CannotAccessANeededSharedLibrary) },
    { ELIBBAD,          ERR(AccessingACorruptedSharedLibrary) },
    { ELIBMAX,          ERR(TooManySharedLibraries) },
    { ELIBSCN,          ERR(DotLibSectionCorrupted) },
    { ELIBEXEC,         ERR(CannotExecASharedLibrary) },
    { ELOOP,            ERR(TooManyLevelsOfSymbolicLinks) },
    { EMEDIUMTYPE,      ERR(WrongMediumType) },
    { EMFILE,           ERR(TooManyOpenedFiles) },
    { EMLINK,           ERR(TooManyLinks) },
    { EMSGSIZE,         ERR(MessageTooLong) },
    { EMULTIHOP,        ERR(MultihopAttempted) },
    { ENAMETOOLONG,     ERR(FileNameTooLong) },
    { ENETDOWN,         ERR(NetworkIsDown) },
    { ENETRESET,        ERR(NetworkDroppedConnectionOnReset) },
    { ENETUNREACH,      ERR(NetworkIsUnreachable) },
    { ENFILE,           ERR(TooManyOpenedFilesInSystem) },
    { ENOBUFS,          ERR(NoBufferSpaceAvailable) },
    { ENODATA,          ERR(NoDataAvailable) },
    { ENODEV,           ERR(DeviceNotFound) },
    { ENOENT,           ERR(FileDoesNotExist) },
    { ENOEXEC,          ERR(ExecFormatError) },
    { ENOKEY,           ERR(RequiredKeyNotAvailable) },
    { ENOLCK,           ERR(NoLocksAvailable) },
    { ENOLINK,          ERR(LinkHasBeenServed) },
    { ENOMEDIUM,        ERR(NoMediumFound) },
    { ENOMEM,           ERR(NotEnoughMemory) },
    { ENOMSG,           ERR(NoMessageOfDesiredType) },
    { ENONET,           ERR(MachineIsNotOnTheNetwork) },
    { ENOPKG,           ERR(PackageNotInstalled) },
    { ENOPROTOOPT,      ERR(ProtocolNotAvailable) }, 
    { ENOSPC,           ERR(NoSpaceLeftOnDevice) },
    { ENOSR,            ERR(OutOfStreamsResources) },
    { ENOSTR,           ERR(NotAStream) },
    { ENOSYS,           ERR(FunctionNotImplemented) },
    { ENOTBLK,          ERR(NotABlockDevice) },
    { ENOTCONN,         ERR(SocketIsNotConnected) },
    { ENOTDIR,          ERR(NotADirectory) },
    { ENOTEMPTY,        ERR(DirectoryNotEmpty) },
    { ENOTRECOVERABLE,  ERR(MutexStateNotRecoverable) },
    { ENOTSOCK,         ERR(SocketOperationOnNonSocket) },
    { ENOTSUP,          ERR(NotSupported) },
    { ENOTTY,           ERR(InappropriateIoctlForDevice) },
    { ENOTUNIQ,         ERR(NameNotUniqueOnNetwork) },
    { ENXIO,            ERR(DeviceNotFoundOrAddress) },
    { EOPNOTSUPP,       ERR(NotSupported) }, /* This error message has the same value with ENOTSUP on linux, and this library threats them the same */
    { EOVERFLOW,        ERR(ValueTooLarge) },
    { EOWNERDEAD,       ERR(OwnerDied) },
    { EPERM,            ERR(PermissionNotPermitted) },
    { EPFNOSUPPORT,     ERR(ProtocolFamilyNotSupported) },
    { EPIPE,            ERR(BrokenPipe) },
    { EPROTO,           ERR(ProtocolError) },
    { EPROTONOSUPPORT,  ERR(ProtocolNotSupported) },
    { EPROTOTYPE,       ERR(WrongProtocolForSocket) },
    { ERANGE,           ERR(NumericalArgumentOutOfDomain) },
    { EREMCHG,          ERR(RemoteAddressChanged) },
    { EREMOTE,          ERR(NFSObjectIsRemote) },
    { EREMOTEIO,        ERR(RemoteIOError) },
    { ERESTART,         ERR(InterruptedSysCall) },
    { ERFKILL,          ERR(OperationPreventedByRFKILL) },
    { EROFS,            ERR(ReadOnlyFileSystem) },
    { ESHUTDOWN,        ERR(CannotSendAfterSocketShutdown) },
    { ESPIPE,           ERR(IllegalSeek) },
    { ESOCKTNOSUPPORT,  ERR(SocketTypeNotSupported) },
    { ESRCH,            ERR(ProcessNotFound) },
    { ESTALE,           ERR(StaleNFSFileHandle) },
    { ESTRPIPE,         ERR(StreamsPipeError) },
    { ETIME,            ERR(TimerExpired) },
    { ETIMEDOUT,        ERR(ConnectionTimedOut) },
    { ETOOMANYREFS,     ERR(TooManyReferences) },
    { ETXTBSY,          ERR(TextSegmentBusy) },
    { EUCLEAN,          ERR(StructureNeedsCleaning) },
    { EUNATCH,          ERR(ProtocolDriverNotAttached) },
    { EUSERS,           ERR(TooManyUsers) },
    { EWOULDBLOCK,      ERR(ResourceUnavailable) },
    { EXDEV,            ERR(InvalidCrossDeviceLink) },
    { EXFULL,           ERR(ExchangeFull) }
};

const int ___errno_binds_size = sizeof(___errno_binds);

#elif defined(__unix__) || defined(__unix)
/* POSIX.1-2008 */

const ___ERRNO_BIND ___errno_binds[] = {
    { E2BIG,            ERR(ArgumentListTooBig) },
    { EACCES,           ERR(PermissionDenied) },
    { EADDRINUSE,       ERR(AddressAlreadyInUse) },
    { EADDRNOTAVAIL,    ERR(CannotAssignRequestedAddress) },
    { EAFNOSUPPORT,     ERR(AddressFamilyNotSupportedByProtocol) },
    { EAGAIN,           ERR(ResourceUnavailable) },
    { EALREADY,         ERR(AlreadyInProgress) },
    { EBADF,            ERR(BadFileDescriptor) },
    { EBADMSG,          ERR(BadMessage) },
    { EBUSY,            ERR(DeviceOrResourceBusy) },
    { ECANCELED,        ERR(OperationCanceled) },
    { ECHILD,           ERR(NoChildProcesses) },
    { ECONNABORTED,     ERR(SoftwareCausedConnectionAbort) },
    { ECONNREFUSED,     ERR(ConnectionRefused) },
    { ECONNRESET,       ERR(ConnectionResetByPeer) },
    { EDEADLK,          ERR(ResourceDeadlockAvoided) },
    { EDESTADDRREQ,     ERR(DestinationAddressRequired) },
    { EDOM,             ERR(NumericalArgumentOutOfDomain) },
    { EDQUOT,           ERR(DiskQuotaExceeded) },
    { EEXIST,           ERR(FileExists) },
    { EFAULT,           ERR(BadAddress) },
    { EFBIG,            ERR(FileTooLarge) },
    { EHOSTUNREACH,     ERR(NetworkIsUnreachable) },
    { EIDRM,            ERR(IdentifierRemoved) },
    { EILSEQ,           ERR(WrongOrIncompleteMultibyteOrWideChar) },
    { EINPROGRESS,      ERR(AlreadyInProgress) },
    { EINTR,            ERR(InterruptedSysCall) },
    { EINVAL,           ERR(InvalidArgument) },
    { EIO,              ERR(IOError) },
    { EISCONN,          ERR(SocketIsAlreadyConnected) },
    { EISDIR,           ERR(IsADirectory) },
    { ELOOP,            ERR(TooManyLevelsOfSymbolicLinks) },
    { EMFILE,           ERR(TooManyOpenedFiles) },
    { EMLINK,           ERR(TooManyLinks) },
    { EMSGSIZE,         ERR(MessageTooLong) },
    { EMULTIHOP,        ERR(MultihopAttempted) },
    { ENAMETOOLONG,     ERR(FileNameTooLong) },
    { ENETDOWN,         ERR(NetworkIsDown) },
    { ENETRESET,        ERR(NetworkDroppedConnectionOnReset) },
    { ENETUNREACH,      ERR(NetworkIsUnreachable) },
    { ENFILE,           ERR(TooManyOpenedFilesInSystem) },
    { ENOBUFS,          ERR(NoBufferSpaceAvailable) },
    { ENODATA,          ERR(NoDataAvailable) },
    { ENODEV,           ERR(DeviceNotFound) },
    { ENOENT,           ERR(FileDoesNotExist) },
    { ENOEXEC,          ERR(ExecFormatError) },
    { ENOLCK,           ERR(NoLocksAvailable) },
    { ENOLINK,          ERR(LinkHasBeenServed) },
    { ENOMEM,           ERR(NotEnoughMemory) },
    { ENOMSG,           ERR(NoMessageOfDesiredType) },
    { ENOPROTOOPT,      ERR(ProtocolNotAvailable) }, 
    { ENOSPC,           ERR(NoSpaceLeftOnDevice) },
    { ENOSR,            ERR(OutOfStreamsResources) },
    { ENOSTR,           ERR(NotAStream) },
    { ENOSYS,           ERR(FunctionNotImplemented) },
    { ENOTCONN,         ERR(SocketIsNotConnected) },
    { ENOTDIR,          ERR(NotADirectory) },
    { ENOTEMPTY,        ERR(DirectoryNotEmpty) },
    { ENOTRECOVERABLE,  ERR(MutexStateNotRecoverable) },
    { ENOTSOCK,         ERR(SocketOperationOnNonSocket) },
    { ENOTSUP,          ERR(NotSupported) },
    { ENOTTY,           ERR(InappropriateIoctlForDevice) },
    { ENXIO,            ERR(DeviceNotFoundOrAddress) },
    { EOPNOTSUPP,       ERR(NotSupported) },
    { EOVERFLOW,        ERR(ValueTooLarge) },
    { EOWNERDEAD,       ERR(OwnerDied) },
    { EPERM,            ERR(PermissionNotPermitted) },
    { EPIPE,            ERR(BrokenPipe) },
    { EPROTO,           ERR(ProtocolError) },
    { EPROTONOSUPPORT,  ERR(ProtocolNotSupported) },
    { EPROTOTYPE,       ERR(WrongProtocolForSocket) },
    { ERANGE,           ERR(NumericalArgumentOutOfDomain) },
    { EROFS,            ERR(ReadOnlyFileSystem) },
    { ESPIPE,           ERR(IllegalSeek) },
    { ESRCH,            ERR(ProcessNotFound) },
    { ESTALE,           ERR(StaleNFSFileHandle) },
    { ETIME,            ERR(TimerExpired) },
    { ETIMEDOUT,        ERR(ConnectionTimedOut) },
    { ETXTBSY,          ERR(TextSegmentBusy) },
    { EWOULDBLOCK,      ERR(ResourceUnavailable) },
    { EXDEV,            ERR(InvalidCrossDeviceLink) }
};

const int ___errno_binds_size = sizeof(___errno_binds);

#else
#error "LIBC/LIBM ports not supported by target."
#endif 
