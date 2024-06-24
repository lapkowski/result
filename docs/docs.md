# NAME

**result** - A library providing better error handling in C, v0.1.0

# SYPNOSIS

**#include \<result/result.h\>**

# DISCLAIMER

Result is a library in beta development stage. Its API can change before
the 1.0 release.

# DESCRIPTION

**Result** provides a special wrapper for return types that prohibits
retriving values without checking for errors while making the handling
of those errors easier.

**Result** is designed to be a direct replacement to the libc *errno*
variable, providing tools to easly convert between the two.

# USING RESULT IN FUNCTION DECLARATIONS

To return Results in your function, first you need to declare a result
for your type (Results for all libc types are already defined.)

`RESULT_DEFINE(yourtype_t)`

*Note:* All pointer types (like char\*) or types with spaces (like long
int) require type redefinition:

```
typedef long int long_int;
RESULT_DEFINE(long_int)

typedef char* char_ptr;
RESULT_DEFINE(char_ptr)
```

Declare a function with a Result return type by using the
**Result**(type) macro:

`Result(int) myfunction(int argument);`

Return an OK result with the **result_OK**(type\[, value\]) macro,
return an error result with the **result_ERR**(type, error) macro:

```
Result(int) myfunction(int argument)
{
    if (argument == 0) return result_ERR(int, MyError);
    return result_OK(argument+2);
}
```

For defining custom error messages refer to the **ERRORS** section.

# USING RESULT FOR ERROR HANDLING

To get the return value from a function and abort on error use
**unwrap**(type, result):

`int myvalue = unwrap(int, myfunction(3));`

To get the error from a function and abort on an ok result use
**unwrap_err**(type, result):

`const Error\* error = unwrap_err(int, myfunction(0));`

To print a custom error message on abort use **expect**(type, result,
message):

`int myvalue = expect(int, myfunction(3), "Unable to retrieve value from myfunction.");`

For more error handling methods refer to the **RESULT METHODS** section.

# UNRECOVERABLE ERRORS

For unrecoverable errors and result on-error exits **panicf**(code, str,
\...) is used:

`if (error == true) panic("DON'T PANIC");`

To define custom unrecoverable error behavior define a custom panic
function:

```
void mypanic(RESULT_PANIC_FUNCTION_PARAMETERS)
{
    va_list arguments;
    va_start(arguments, str);

    printf("An error occured!");

    vprintf(str, arguments);
    va_end(arguments);

    exit(exit_code);
}

#define panic_function mypanic
```

Variables provided by **RESULT_PANIC_FUNCTION_PARAMETERS** :

> src_line
>
> :   The line from which the panic was called
>
> src_function
>
> :   the function from which the panic was called
>
> src_file
>
> :   the file from which the panic was called
>
> exit_code
>
> :   Prefered program exit code
>
> message
>
> :   Panic message with printf-like formatting
>
> ... (va_list)
>
> :   Panic message format specifier replacements

# ERRORS

Result refers to errors by constant Error type pointers (const Error\*)
To get a result type by an id use the **ERR**(id) macro:

`const Error* myerror = ERR(MyError);`

You can compare errors normally using the == operator.

`if (myerror == ERR(MyError)) printf("Oh no!");`

Define custom errors with the **ERROR_DEFINE**(id, exit_code, message)
macro:

`ERROR_DEFINE(MyError, -1, "Something bad happened!")`

# RESULT METHODS

> result_and(type, self, other)
>
> :   Returns *other* if the result is OK, otherwise returns the Err
>     value of *self*. - type is the result type. - self is the result
>     that the method is called on. - other is a result, that has the
>     same type as self.
>
> result_and_then(type, self, call)
>
> :   Calls *call* if the result is OK, otherrwise returns the ERR value
>     of *self*. - type is the result type. - self is the result that
>     the method is called on. - call is a function pointer that returns
>     a result, that has the same type as self, and takes nothing.
>
> result_expect(type, self, error)
>
> :   Call **panicf** when *self* is ERR with the provided error message
>     (*error*), otherwise return the OK value. - type is the result
>     type. - self is the result that the method is called on. - error
>     is a provided error message, when **expect** panics.
>
> result_expect_err(type, self, error)
>
> :   The same as **result_expect**, but it panics on an OK value, and
>     returns the ERR value. - type is the result type. - self is the
>     result that the method is called on. - error is a provided error
>     message, when **expect_err** panics.
>
> result_inspect(type, self, call)
>
> :   When *self* is OK it calls *call* with the OK value, otherwise
>     does nothing. - type is the result type. - self is the result that
>     the method is called on. - call is a function pointer that returns
>     nothing, and takes the OK value.
>
> result_inspect_err(type, self, call)
>
> :   The same as **result_inspect**, but calls the method when *self*
>     is ERR, and provides the error to the call. - type is the result
>     type. - self is the result that the method is called on. - call is
>     a function pointer that returns nothing, and takes the ERR value.
>
> result_is_ok_and(type, self, call)
>
> :   Similar to **result_inspect**, but *call* returns a boolean, and
>     the function returns true when *self* is OK, and call returns
>     true. Otherwise returns false. - type is the result type. - self
>     is the result that the method is called on. - call is a function
>     pointer that returns a boolean, and takes the OK value.
>
> result_is_err_and(type, self, call)
>
> :   Similar to **result_inspect_err**, but *call* returns a boolean,
>     and the function returns true when *self* is ERR, and call returns
>     true. Otherwise returns false. - type is the result type. - self
>     is the result that the method is called on. - call is a function
>     pointer that returns a boolean, and takes the ERR value.
>
> result_unwrap(type, self)
>
> :   Call **panicf** when *self* is ERR, otherwise return the OK
>     value. - type is the result type. - self is the result that the
>     method is called on.
>
> result_unwrap_err(type, self)
>
> :   The same as **result_unwarp**, but it calls **panicf** on OK and
>     returns on ERR. - type is the result type. - self is the result
>     that the method is called on.
>
> result_unwrap_or(type, self, fallback)
>
> :   The same as **result_unwrap**, but it returns *fallback* on ERR
>     and returns the value of *self* on OK. - type is the result
>     type. - self is the result that the method is called on. -
>     fallback is the fallback OK value.
>
> result_unwrap_or_err(type, self, fallback)
>
> :   The same as **result_unwarp_or**, but it returns *fallback* on
>     OK. - type is the result type. - self is the result that the
>     method is called on. - fallback is the fallback ERR value.
>
> result_or(type, self, other)
>
> :   Returns *other* is the result is Err, otherwise returns the OK
>     value of self. - type is the result type. - self is the result
>     that the method is called on. - other is a result, that has the
>     same type as self.
>
> result_or_else(type, self, call)
>
> :   Calls *call* if the result is ERR, otherwise returns the OK value
>     of *self*. - type is the result type. - self is the result that
>     the method is called on. - call is a function pointer that returns
>     a result, that has the same type as self, and takes nothing.
>
> result_ERR(type, id)
>
> :   Constructs a result with an ERR value. - type is the result
>     type. - id is the Error ID.
>
> result_OK(type, value)
>
> :   Constructs a result with an OK value. - type is the result type. -
>     id is the OK value (don\'t pass the value with the void type)
>
> result_is_ok(type, self)
>
> :   Returns true if *self* has an OK value, otherwise returns false. -
>     type is the result type. - self is the result that the method is
>     called on.
>
> result_is_err(type, self)
>
> :   Returns false if *self* has an OK value, otherwise returns true. -
>     type is the result type. - self is the result that the method is
>     called on.

# SHORTCUTS

If **RESULT_DONT_DEFINE_SHORTCUTS** is not defined Result defines shortcuts for the following functions: 
    - expect = result_expect 
    - expect_err = result_expect_err
    - is_err_and = result_is_err_and
    - is_ok_and = result_is_ok_and
    - unwrap = result_unwrap
    - unwrap_err = result_unwrap_err
    - unwrap_or = result_unwrap_or
    - unwrap_err_or = result_unwrap_err_or
    - is_ok = result_is_ok
    - is_err = result_is_err

# PROVIDED ERROR IDS

> PermissionNotPermitted
>
> :   An attempt was made to perform an operation that is reserved for
>     higher privilage processes.
>
> FileDoesNotExist
>
> :   No file or directory could be found in the path specified.
>
> ProcessNotFound
>
> :   No process could be found corresponding to the PID specified.
>
> InterruptedSysCall
>
> :   An asynchronous signal occured and prevented completion of the
>     call.
>
> IOError
>
> :   Some physical input or output error occured.
>
> DeviceNotFoundOrAddress
>
> :   Attached device couldn\'t handle the request, was incorectly
>     installed, or was not found.
>
> ArgumentListTooBig
>
> :   The number of bytes used in the argument list exceeded the limit.
>
> ExecFormatError
>
> :   An attempt was made to execute a file that does not contain an
>     executable-specific format.
>
> BadFileDescriptor
>
> :   A file descriptor is not pointing to an opened file, or cannot
>     handle the request.
>
> NoChildProcesses
>
> :   An attempt was made to manipulate a non-existing child process.
>
> ResourceDeadlockAvoided
>
> :   An attempt was made to lock a system resource that would have
>     resulted in a deadlock situation.
>
> NotEnoughMemory
>
> :   This process requires more memory than is allowed by the hardware
>     or by system-managed constraints.
>
> PermissionDenied
>
> :   An attempt was made to access a file in a way forbidden by it\'s
>     file access permissions.
>
> BadAddress
>
> :   The system detected an invalid address in attempting to use an
>     argument of a call.
>
> NotABlockDevice
>
> :   An attempt was made to do a block operation on an non-block device
>     or file.
>
> DeviceOrResourceBusy
>
> :   An attempt was made to use a system resource which was used at a
>     time in a conflicting way.
>
> FileExists
>
> :   An attempt was made to create a file in a location used by another
>     file.
>
> InvalidCrossDeviceLink
>
> :   An attempt was made to create a hard link across file systems.
>
> UnsupportedDeviceOperation
>
> :   An attempt was made to apply an inappropriate function to a
>     device.
>
> NotADirectory
>
> :   An attempt was made to apply a directory-expecting function to a
>     non-directory path.
>
> IsADirectory
>
> :   An attempt was made to apply an inappropriate function to a
>     directory.
>
> InvalidArgument
>
> :   An invalid argument was supplied to a function.
>
> TooManyOpenedFiles
>
> :   The current process has too many files open and can\'t open any
>     more.
>
> TooManyOpenedFilesInSystem
>
> :   The operating system has too many files open and can\'t open any
>     more.
>
> InappropriateIoctlForDevice
>
> :   An attempt was made to apply an inappropriate control function
>     operation on a file or a special device.
>
> TextSegmentBusy
>
> :   An attempt was made to modify a file while it\'s beeing executed,
>     or execute a file while it\'s beeing modified.
>
> FileTooLarge
>
> :   The size of a file is larger than allowed by the system.
>
> NoSpaceLeftOnDevice
>
> :   A write operation was attempted on a device that is full.
>
> IllegalSeek
>
> :   A seek operation was attempted on a socket, pipe or FIFO.
>
> ReadOnlyFileSystem
>
> :   An attempt was made to modify a file or directory was made on a
>     filesystem that was read-only at the time.
>
> TooManyLinks
>
> :   Maximum allowable hard links to a single file has been exceeded.
>
> BrokenPipe
>
> :   A write on a pipe, socket of FIFO for which there is no process to
>     read the data.
>
> DeviceNotFound
>
> :   The wrong type of device was given to a function that expects a
>     particular sort of device.
>
> NumericalArgumentOutOfDomain
>
> :   A numerical input argument was ouside the defined domain of the
>     mathematical function
>
> NumericalArgumentOutOfRange
>
> :   A numerical result of the function was too large to fit in the
>     avaiable space.
>
> ResourceUnavailable
>
> :   The system lacks resources to complete the operation. This
>     operation may succeed later, when system resources are freed.
>
> InProgress
>
> :   A long operation was attempted at a non-blocking function. \[If
>     you (a user) see this error message, this is a programming error.
>     Please report it to the program authors.]
>
> AlreadyInProgress
>
> :   An operation was attempted on a non-blocking object that already
>     had an operation in progress.
>
> SocketOperationOnNonSocket
>
> :   An attempt was made to apply a socket-expecting function to a
>     non-socket file.
>
> MessageTooLong
>
> :   A message sent on a socket was larger than the internal message
>     buffer or some other network limit.
>
> WrongProtocolForSocket
>
> :   A protocol was specified that does not support the semantics of
>     the socket type requested.
>
> ProtocolNotAvailable
>
> :   A socket option was specified that does not make sense for the
>     particular protocol being used in the socket.
>
> SocketTypeNotSupported
>
> :   The support for the socket type has not been configured into the
>     system or no implementation for it exists.
>
> NotSupported
>
> :   The attempted operation is not supported for the type of object
>     referenced.
>
> ProtocolFamilyNotSupported
>
> :   The protocol family has not been configured into the system or no
>     implementation for it exists.
>
> ProtocolNotSupported
>
> :   The protocol has not been configured into the system or no
>     implementation for it exists.
>
> AddressFamilyNotSupportedByProtocol
>
> :   An address incompatible with the requested protocol was used.
>
> AddressAlreadyInUse
>
> :   The requested socket address is already in use.
>
> CannotAssignRequestedAddress
>
> :   The requested socket address is not available.
>
> NetworkIsDown
>
> :   A socket operation encontered a dead network.
>
> NetworkIsUnreachable
>
> :   A socket operation was attempted to an unreachable network.
>
> NetworkDroppedConnectionOnReset
>
> :   The host you were connected to crashed and rebooted.
>
> SoftwareCausedConnectionAbort
>
> :   A network connection was aborted locally.
>
> ConnectionResetByPeer
>
> :   A network connection was closed for reasons outside the control of
>     the local host.
>
> NoBufferSpaceAvailable
>
> :   An operation was not performed because the system lacked
>     sufficient buffer space or because a queue was full.
>
> SocketIsAlreadyConnected
>
> :   A connect request was made on an already connected socket.
>
> SocketIsNotConnected
>
> :   A request to send or receive data was disallowed because the
>     socket was not connected and no address was supplied.
>
> CannotSendAfterSocketShutdown
>
> :   A request to send data was disallowed because the socket had
>     already been shut down.
>
> DestinationAddressRequired
>
> :   A required address was omitted from an operation on a socket.
>
> TooManyReferences
>
> :   A splice cannot be completed, because there are too many
>     references.
>
> ConnectionTimedOut
>
> :   A connect or send request failed because the connected party did
>     not properly respond after a period of time.
>
> ConnectionRefused
>
> :   No connection could be made because the target machine actively
>     refused it.
>
> TooManyLevelsOfSymbolicLinks
>
> :   Too many levels of symbolic links were encountered in looking up a
>     file name.
>
> FileNameTooLong
>
> :   FileName or host name exceeded the limit of characters
>
> HostIsDown
>
> :   The remote host for a requested network connection is down.
>
> NoRouteToHost
>
> :   The remote host for a requested connection is not reachable.
>
> DirectoryNotEmpty
>
> :   An non-empty directory was supplied.
>
> TooManyProceses
>
> :   The per-user limit on new processes was exceeded.
>
> TooManyUsers
>
> :   The new user limit was exceeded.
>
> DiskQuotaExceeded
>
> :   The user's quota of disk blocks was exhaused.
>
> StaleNFSFileHandle
>
> :   An attempt was made to access an open file (on an NFS filesystem)
>     which is now unavailable.
>
> NFSObjectIsRemote
>
> :   An attempt was made to NFS-mount a remote file system with a file
>     name that already specifies an NFS-mounted file.
>
> RPCStructIsBad
>
> :   Exchange of RPC information was unseccessful.
>
> RPCVersionWrong
>
> :   The version of RPC on the remote peer is not compatible with the
>     local version.
>
> RPCProgramNotAvailable
>
> :   The requested program is not registered on the remote host.
>
> RPCProgramVersionWrong
>
> :   The requested version of the program is not available on the
>     remote host (RPC).
>
> BadRPCProcedureForProgram
>
> :   An RPC call was attempted for a procedure which doesn\'t exist in
>     the remote program.
>
> NoLocksAvailable
>
> :   Attempted a system call that is not available on this system.
>
> InappropriateFileTypeOrFormat
>
> :   The file was the wrong type for the operation, or a data file had
>     the wrong format.
>
> AuthenticationError
>
> :   Attempted to use an invalid authentication ticket to mount an NFS
>     file system.
>
> NeedAuthenticator
>
> :   An authentication ticket must be obtained before the given NFS
>     file system may be mounted.
>
> FunctionNotImplemented
>
> :   The function called is not implemented at all, or not available in
>     the system.
>
> CannotExecASharedLibrary
>
> :   An attempt was made to execute a shared library.
>
> WrongOrIncompleteMultibyteOrWideChar
>
> :   While decoding a multibyte character the function came along an
>     invalid or an incomplete sequence of bytes or the given wide
>     characted is invalid.
>
> InappropriateOperationForBgProcess
>
> :   An inappropriate operation was attempted in a background process.
>
> TranslatorDied
>
> :   A translator program died while starting up.
>
> BadMessage
>
> :   The message to be received is inappropriate for the operation
>     being attempted.
>
> IdentifierRemoved
>
> :   An IPC identiffier was removed while the current process was
>     waiting on it.
>
> MultihopAttempted
>
> :   Components of path require hopping to multiple remorte machines
>     and the filesystem does not allow it.
>
> NoDataAvailable
>
> :   No message is available.
>
> LinkHasBeenServed
>
> :   The link connection to a remote machine is gone.
>
> NoMessageOfDesiredType
>
> :   No message of desired type could be found.
>
> OutOfStreamsResources
>
> :   The buffer could not be allocated due to insufficient STREAMs
>     memory resources.
>
> NotAStream
>
> :   A STREAM is not associeted with the specified file descriptor.
>
> ValueTooLarge
>
> :   A numerical result of a function was too large to be stored in the
>     caller provided space.
>
> ProtocolError
>
> :   Some protocol error occured (This error is device-specyfic, but is
>     generaly not related to hardware faliure. For more information
>     refer to the manufacturer\'s manual.
>
> TimerExpired
>
> :   A timer set for an I/O operation expired.
>
> OperationCanceled
>
> :   An ansychronous operation was canceled before it was completed.
>
> OwnerDied
>
> :   The last owner of a robust mutex died while holding it.
>
> MutexStateNotRecoverable
>
> :   The last owner of a robust mutex died while holding it, and the
>     new owner had unlocked the mutex without making it\'s state
>     consistent.
>
> TruncatedString
>
> :   A string copy or concatenation resulted in a truncated string.
>
> UnexpectedError
>
> :   An error happend, but the error code passed is invalid.
>
> CodeAbuse
>
> :   A function or API is being abused in a way which could only be
>     detected at run-time
>
> BadCPUType
>
> :   The executable in question does not support the current CPU
>
> MalformedExecutableOrSharedLibrary
>
> :   The executable or shared library in question was malformed.
>
> MalformedMachObject
>
> :   The Mach Object file in question was malformed.
>
> DeviceError
>
> :   A device error has occured.
>
> NoSuchPolicy
>
> :   No such policy registered.
>
> DevicePowerIsOff
>
> :   The device power is off.
>
> FullInterfaceOutputQueue
>
> :   Interface output queue is full.
>
> SharedLibraryVersionMismatch
>
> :   The version of the shared library on the system does not match the
>     version which was expected.
>
> IPSecProcessingFailure
>
> :   IPsec subsystem error.
>
> NotPermittedInCapabilityMode
>
> :   The system call or operation is not permitted for capability mode
>     processes.
>
> IntegrityCheckFailed
>
> :   An integrity check failed and detected inconsistencies in data
>     questioned.
>
> CapabilitiesInsufficient
>
> :   An operation requires greater privilege than the capability
>     allows.
>
> InterruptedSyscallShouldBeRestarted
>
> :   Interrupted system call should be restarted.
>
> ChannelNumberOutOfRange
>
> :   Channel number out of range.
>
> Level2NotSynchronized
>
> :   Level 2 not synchronized.
>
> Level3Halted
>
> :   Level 3 halted.
>
> Level3Reset
>
> :   Level 3 reset.
>
> LinkNumberOutOfRange
>
> :   Link number out of range.
>
> ProtocolDriverNotAttached
>
> :   Protocol driver not attached.
>
> NoCSIStructure
>
> :   No CSI structure available.
>
> Level2Halted
>
> :   Level 2 halted.
>
> InvalidExchange
>
> :   Invalid exchange.
>
> InvalidRequestDescriptor
>
> :   Invalid request descriptor.
>
> ExchangeFull
>
> :   Exchange full.
>
> NoAnode
>
> :   No anode.
>
> InvalidRequestCode
>
> :   Invalid request code.
>
> InvalidSlot
>
> :   Invalid slot.
>
> FileLockingDeadlock
>
> :   File locking deadlock.
>
> BadFontFileFormat
>
> :   Bad font file format.
>
> MachineIsNotOnTheNetwork
>
> :   Machine is not on the network.
>
> PackageNotInstalled
>
> :   Package not installed.
>
> AdvertiseError
>
> :   Advertise error.
>
> SrmountError
>
> :   Srmount error.
>
> CommunicationErrorOnSend
>
> :   Communication error on send.
>
> RFSError
>
> :   RFS specyfic error.
>
> NameNotUniqueOnNetwork
>
> :   Name not unique on network.
>
> FileDescriptorInBadState
>
> :   File descriptor in bad state.
>
> RemoteAddressChanged
>
> :   Remote address changed.
>
> CannotAccessANeededSharedLibrary
>
> :   Cannot access a needed shared library.
>
> AccessingACorruptedSharedLibrary
>
> :   Accessing a corrupted shared library.
>
> DotLibSectionCorrupted
>
> :   .lib section corrupted in a.out.
>
> TooManySharedLibraries
>
> :   An attempt was made to link too many shared libraries.
>
> StreamsPipeError
>
> :   STREAMs pipe error.
>
> StructureNeedsCleaning
>
> :   Structure needs cleaning.
>
> NotXENIXNamedTypeFile
>
> :   Not a XENIX named type file.
>
> NoXENIXSemaphoresAvailable
>
> :   No XENIX Semaphores available.
>
> IsANamedTypeFile
>
> :   Is a named type file.
>
> RemoteIOError
>
> :   Remote I/O error.
>
> NoMediumFound
>
> :   No medium found.
>
> WrongMediumType
>
> :   Wrong medium type.
>
> RequiredKeyNotAvailable
>
> :   Required key not available.
>
> KeyHasExpired
>
> :   Key has expired.
>
> KeyHasBeenRevoked
>
> :   Key has been revoked.
>
> KeyWasRejectedByService
>
> :   Key was rejected by service.
>
> OperationPreventedByRFKILL
>
> :   Operation not possible due to RF-kill.
>
> MemoryPageHasHardwareError
>
> :   Memory page has hardware error.
>
> Async
>
> :   Async
>
> UnknownError
>
> :   Unknown error occured.

# AUTHORS

Mariusz Łapkowski, based on the Rust\'s std::result::Result type.
