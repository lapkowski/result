/*
    PORTS/ERRORS.H - Error defines for the errno constants on diffrent targets

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

#ifndef ___RESULT__ERRORS___
#define ___RESULT__ERRORS___

#ifndef RESULT_DISABLE_PORTS

#include <errno.h>

#include <error.h>

#define FileOperationFailedExitCode -1
#define InvalidRequestExitCode -2
#define PermissionErrorExitCode -3
#define MemoryRelatedErrorExitCode -4
#define MathRelatedErrorExitCode -5
#define NetworkConectionErrorExitCode -6
#define OtherErrorExitCode -7

ERROR_DECLARE(PermissionNotPermitted)
ERROR_DECLARE(FileDoesNotExist)
ERROR_DECLARE(ProcessNotFound)
ERROR_DECLARE(InterruptedSysCall)
ERROR_DECLARE(IOError)
ERROR_DECLARE(DeviceNotFoundOrAddress)
ERROR_DECLARE(ArgumentListTooBig)
ERROR_DECLARE(ExecFormatError)
ERROR_DECLARE(BadFileDescriptor)
ERROR_DECLARE(NoChildProcesses)
ERROR_DECLARE(ResourceDeadlockAvoided)
ERROR_DECLARE(NotEnoughMemory)
ERROR_DECLARE(PermissionDenied)
ERROR_DECLARE(BadAddress)
ERROR_DECLARE(NotABlockDevice)
ERROR_DECLARE(DeviceOrResourceBusy)
ERROR_DECLARE(FileExists)
ERROR_DECLARE(InvalidCrossDeviceLink)
ERROR_DECLARE(UnsupportedDeviceOperation)
ERROR_DECLARE(NotADirectory)
ERROR_DECLARE(IsADirectory)
ERROR_DECLARE(InvalidArgument)
ERROR_DECLARE(TooManyOpenedFiles)
ERROR_DECLARE(TooManyOpenedFilesInSystem)
ERROR_DECLARE(InappropriateIoctlForDevice)
ERROR_DECLARE(TextSegmentBusy)
ERROR_DECLARE(FileTooLarge)
ERROR_DECLARE(NoSpaceLeftOnDevice)
ERROR_DECLARE(IllegalSeek)
ERROR_DECLARE(ReadOnlyFileSystem)
ERROR_DECLARE(TooManyLinks)
ERROR_DECLARE(BrokenPipe)
ERROR_DECLARE(DeviceNotFound)
ERROR_DECLARE(NumericalArgumentOutOfDomain)
ERROR_DECLARE(NumericalArgumentOutOfRange)
ERROR_DECLARE(ResourceUnavailable)
ERROR_DECLARE(InProgress)
ERROR_DECLARE(AlreadyInProgress)
ERROR_DECLARE(SocketOperationOnNonSocket)
ERROR_DECLARE(MessageTooLong)
ERROR_DECLARE(WrongProtocolForSocket)
ERROR_DECLARE(ProtocolNotAvailable)
ERROR_DECLARE(SocketTypeNotSupported)
ERROR_DECLARE(NotSupported)
ERROR_DECLARE(ProtocolFamilyNotSupported)
ERROR_DECLARE(ProtocolNotSupported)
ERROR_DECLARE(AddressFamilyNotSupportedByProtocol)
ERROR_DECLARE(AddressAlreadyInUse)
ERROR_DECLARE(CannotAssignRequestedAddress)
ERROR_DECLARE(NetworkIsDown)
ERROR_DECLARE(NetworkIsUnreachable)
ERROR_DECLARE(NetworkDroppedConnectionOnReset)
ERROR_DECLARE(SoftwareCausedConnectionAbort)
ERROR_DECLARE(ConnectionResetByPeer)
ERROR_DECLARE(NoBufferSpaceAvailable)
ERROR_DECLARE(SocketIsAlreadyConnected)
ERROR_DECLARE(SocketIsNotConnected)
ERROR_DECLARE(CannotSendAfterSocketShutdown)
ERROR_DECLARE(DestinationAddressRequired)
ERROR_DECLARE(TooManyReferences)
ERROR_DECLARE(ConnectionTimedOut)
ERROR_DECLARE(ConnectionRefused)
ERROR_DECLARE(TooManyLevelsOfSymbolicLinks)
ERROR_DECLARE(FileNameTooLong)
ERROR_DECLARE(HostIsDown)
ERROR_DECLARE(NoRouteToHost)
ERROR_DECLARE(DirectoryNotEmpty)
ERROR_DECLARE(TooManyProceses)
ERROR_DECLARE(TooManyUsers)
ERROR_DECLARE(DiskQuotaExceeded)
ERROR_DECLARE(StaleNFSFileHandle)
ERROR_DECLARE(NFSObjectIsRemote)
ERROR_DECLARE(RPCStructIsBad)
ERROR_DECLARE(RPCVersionWrong)
ERROR_DECLARE(RPCProgramNotAvailable)
ERROR_DECLARE(RPCProgramVersionWrong)
ERROR_DECLARE(BadRPCProcedureForProgram)
ERROR_DECLARE(NoLocksAvailable)
ERROR_DECLARE(InappropriateFileTypeOrFormat)
ERROR_DECLARE(AuthenticationError)
ERROR_DECLARE(NeedAuthenticator)
ERROR_DECLARE(FunctionNotImplemented)
ERROR_DECLARE(CannotExecASharedLibrary)
ERROR_DECLARE(WrongOrIncompleteMultibyteOrWideChar)
ERROR_DECLARE(InappropriateOperationForBgProcess)
ERROR_DECLARE(TranslatorDied)
ERROR_DECLARE(BadMessage)
ERROR_DECLARE(IdentifierRemoved)
ERROR_DECLARE(MultihopAttempted)
ERROR_DECLARE(NoDataAvailable)
ERROR_DECLARE(LinkHasBeenServed)
ERROR_DECLARE(NoMessageOfDesiredType)
ERROR_DECLARE(OutOfStreamsResources)
ERROR_DECLARE(NotAStream)
ERROR_DECLARE(ValueTooLarge)
ERROR_DECLARE(ProtocolError)
ERROR_DECLARE(TimerExpired)
ERROR_DECLARE(OperationCanceled)
ERROR_DECLARE(OwnerDied)
ERROR_DECLARE(MutexStateNotRecoverable)
ERROR_DECLARE(TruncatedString)
ERROR_DECLARE(UnexpectedError)
ERROR_DECLARE(CodeAbuse)
ERROR_DECLARE(BadCPUType)
ERROR_DECLARE(MalformedExecutableOrSharedLibrary)
ERROR_DECLARE(MalformedMachObject)
ERROR_DECLARE(DeviceError)
ERROR_DECLARE(NoSuchPolicy)
ERROR_DECLARE(DevicePowerIsOff)
ERROR_DECLARE(FullInterfaceOutputQueue)
ERROR_DECLARE(SharedLibraryVersionMismatch)
ERROR_DECLARE(IPSecProcessingFailure)
ERROR_DECLARE(NotPermittedInCapabilityMode)
ERROR_DECLARE(IntegrityCheckFailed)
ERROR_DECLARE(CapabilitiesInsufficient)
ERROR_DECLARE(InterruptedSyscallShouldBeRestarted)
ERROR_DECLARE(ChannelNumberOutOfRange)
ERROR_DECLARE(Level2NotSynchronized)
ERROR_DECLARE(Level3Halted)
ERROR_DECLARE(Level3Reset)
ERROR_DECLARE(LinkNumberOutOfRange)
ERROR_DECLARE(ProtocolDriverNotAttached)
ERROR_DECLARE(NoCSIStructure)
ERROR_DECLARE(Level2Halted)
ERROR_DECLARE(InvalidExchange)
ERROR_DECLARE(InvalidRequestDescriptor)
ERROR_DECLARE(ExchangeFull)
ERROR_DECLARE(NoAnode)
ERROR_DECLARE(InvalidRequestCode)
ERROR_DECLARE(InvalidSlot)
ERROR_DECLARE(FileLockingDeadlock)
ERROR_DECLARE(BadFontFileFormat)
ERROR_DECLARE(MachineIsNotOnTheNetwork)
ERROR_DECLARE(PackageNotInstalled)
ERROR_DECLARE(AdvertiseError)
ERROR_DECLARE(SrmountError)
ERROR_DECLARE(CommunicationErrorOnSend)
ERROR_DECLARE(RFSError)
ERROR_DECLARE(NameNotUniqueOnNetwork)
ERROR_DECLARE(FileDescriptorInBadState)
ERROR_DECLARE(RemoteAddressChanged)
ERROR_DECLARE(CannotAccessANeededSharedLibrary)
ERROR_DECLARE(AccessingACorruptedSharedLibrary)
ERROR_DECLARE(DotLibSectionCorrupted)
ERROR_DECLARE(TooManySharedLibraries)
ERROR_DECLARE(StreamsPipeError)
ERROR_DECLARE(StructureNeedsCleaning)
ERROR_DECLARE(NotXENIXNamedTypeFile)
ERROR_DECLARE(NoXENIXSemaphoresAvailable)
ERROR_DECLARE(IsANamedTypeFile)
ERROR_DECLARE(RemoteIOError)
ERROR_DECLARE(NoMediumFound)
ERROR_DECLARE(WrongMediumType)
ERROR_DECLARE(RequiredKeyNotAvailable)
ERROR_DECLARE(KeyHasExpired)
ERROR_DECLARE(KeyHasBeenRevoked)
ERROR_DECLARE(KeyWasRejectedByService)
ERROR_DECLARE(OperationPreventedByRFKILL)
ERROR_DECLARE(MemoryPageHasHardwareError)
ERROR_DECLARE(Async)
ERROR_DECLARE(UnknownError)

typedef struct {
    int c_errno;
    const Error* error;
} ___ERRNO_BIND;

extern const int ___errno_binds_size;
extern const ___ERRNO_BIND ___errno_binds[];

#endif /* !RESULT_DISABLE_PORTS */

#endif
