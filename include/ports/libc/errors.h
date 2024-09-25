/*
    PORTS/ERRORTYPES.H - Error defines for the errno constants on diffrent targets

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

#ifndef ___RESULT__ERRORTYPES___
#define ___RESULT__ERRORTYPES___

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

ERRORTYPE_DECLARE(PermissionNotPermitted)
ERRORTYPE_DECLARE(FileDoesNotExist)
ERRORTYPE_DECLARE(ProcessNotFound)
ERRORTYPE_DECLARE(InterruptedSysCall)
ERRORTYPE_DECLARE(IOError)
ERRORTYPE_DECLARE(DeviceNotFoundOrAddress)
ERRORTYPE_DECLARE(ArgumentListTooBig)
ERRORTYPE_DECLARE(ExecFormatError)
ERRORTYPE_DECLARE(BadFileDescriptor)
ERRORTYPE_DECLARE(NoChildProcesses)
ERRORTYPE_DECLARE(ResourceDeadlockAvoided)
ERRORTYPE_DECLARE(NotEnoughMemory)
ERRORTYPE_DECLARE(PermissionDenied)
ERRORTYPE_DECLARE(BadAddress)
ERRORTYPE_DECLARE(NotABlockDevice)
ERRORTYPE_DECLARE(DeviceOrResourceBusy)
ERRORTYPE_DECLARE(FileExists)
ERRORTYPE_DECLARE(InvalidCrossDeviceLink)
ERRORTYPE_DECLARE(UnsupportedDeviceOperation)
ERRORTYPE_DECLARE(NotADirectory)
ERRORTYPE_DECLARE(IsADirectory)
ERRORTYPE_DECLARE(InvalidArgument)
ERRORTYPE_DECLARE(TooManyOpenedFiles)
ERRORTYPE_DECLARE(TooManyOpenedFilesInSystem)
ERRORTYPE_DECLARE(InappropriateIoctlForDevice)
ERRORTYPE_DECLARE(TextSegmentBusy)
ERRORTYPE_DECLARE(FileTooLarge)
ERRORTYPE_DECLARE(NoSpaceLeftOnDevice)
ERRORTYPE_DECLARE(IllegalSeek)
ERRORTYPE_DECLARE(ReadOnlyFileSystem)
ERRORTYPE_DECLARE(TooManyLinks)
ERRORTYPE_DECLARE(BrokenPipe)
ERRORTYPE_DECLARE(DeviceNotFound)
ERRORTYPE_DECLARE(NumericalArgumentOutOfDomain)
ERRORTYPE_DECLARE(NumericalArgumentOutOfRange)
ERRORTYPE_DECLARE(ResourceUnavailable)
ERRORTYPE_DECLARE(InProgress)
ERRORTYPE_DECLARE(AlreadyInProgress)
ERRORTYPE_DECLARE(SocketOperationOnNonSocket)
ERRORTYPE_DECLARE(MessageTooLong)
ERRORTYPE_DECLARE(WrongProtocolForSocket)
ERRORTYPE_DECLARE(ProtocolNotAvailable)
ERRORTYPE_DECLARE(SocketTypeNotSupported)
ERRORTYPE_DECLARE(NotSupported)
ERRORTYPE_DECLARE(ProtocolFamilyNotSupported)
ERRORTYPE_DECLARE(ProtocolNotSupported)
ERRORTYPE_DECLARE(AddressFamilyNotSupportedByProtocol)
ERRORTYPE_DECLARE(AddressAlreadyInUse)
ERRORTYPE_DECLARE(CannotAssignRequestedAddress)
ERRORTYPE_DECLARE(NetworkIsDown)
ERRORTYPE_DECLARE(NetworkIsUnreachable)
ERRORTYPE_DECLARE(NetworkDroppedConnectionOnReset)
ERRORTYPE_DECLARE(SoftwareCausedConnectionAbort)
ERRORTYPE_DECLARE(ConnectionResetByPeer)
ERRORTYPE_DECLARE(NoBufferSpaceAvailable)
ERRORTYPE_DECLARE(SocketIsAlreadyConnected)
ERRORTYPE_DECLARE(SocketIsNotConnected)
ERRORTYPE_DECLARE(CannotSendAfterSocketShutdown)
ERRORTYPE_DECLARE(DestinationAddressRequired)
ERRORTYPE_DECLARE(TooManyReferences)
ERRORTYPE_DECLARE(ConnectionTimedOut)
ERRORTYPE_DECLARE(ConnectionRefused)
ERRORTYPE_DECLARE(TooManyLevelsOfSymbolicLinks)
ERRORTYPE_DECLARE(FileNameTooLong)
ERRORTYPE_DECLARE(HostIsDown)
ERRORTYPE_DECLARE(NoRouteToHost)
ERRORTYPE_DECLARE(DirectoryNotEmpty)
ERRORTYPE_DECLARE(TooManyProceses)
ERRORTYPE_DECLARE(TooManyUsers)
ERRORTYPE_DECLARE(DiskQuotaExceeded)
ERRORTYPE_DECLARE(StaleNFSFileHandle)
ERRORTYPE_DECLARE(NFSObjectIsRemote)
ERRORTYPE_DECLARE(RPCStructIsBad)
ERRORTYPE_DECLARE(RPCVersionWrong)
ERRORTYPE_DECLARE(RPCProgramNotAvailable)
ERRORTYPE_DECLARE(RPCProgramVersionWrong)
ERRORTYPE_DECLARE(BadRPCProcedureForProgram)
ERRORTYPE_DECLARE(NoLocksAvailable)
ERRORTYPE_DECLARE(InappropriateFileTypeOrFormat)
ERRORTYPE_DECLARE(AuthenticationError)
ERRORTYPE_DECLARE(NeedAuthenticator)
ERRORTYPE_DECLARE(FunctionNotImplemented)
ERRORTYPE_DECLARE(CannotExecASharedLibrary)
ERRORTYPE_DECLARE(WrongOrIncompleteMultibyteOrWideChar)
ERRORTYPE_DECLARE(InappropriateOperationForBgProcess)
ERRORTYPE_DECLARE(TranslatorDied)
ERRORTYPE_DECLARE(BadMessage)
ERRORTYPE_DECLARE(IdentifierRemoved)
ERRORTYPE_DECLARE(MultihopAttempted)
ERRORTYPE_DECLARE(NoDataAvailable)
ERRORTYPE_DECLARE(LinkHasBeenServed)
ERRORTYPE_DECLARE(NoMessageOfDesiredType)
ERRORTYPE_DECLARE(OutOfStreamsResources)
ERRORTYPE_DECLARE(NotAStream)
ERRORTYPE_DECLARE(ValueTooLarge)
ERRORTYPE_DECLARE(ProtocolError)
ERRORTYPE_DECLARE(TimerExpired)
ERRORTYPE_DECLARE(OperationCanceled)
ERRORTYPE_DECLARE(OwnerDied)
ERRORTYPE_DECLARE(MutexStateNotRecoverable)
ERRORTYPE_DECLARE(TruncatedString)
ERRORTYPE_DECLARE(UnexpectedError)
ERRORTYPE_DECLARE(CodeAbuse)
ERRORTYPE_DECLARE(BadCPUType)
ERRORTYPE_DECLARE(MalformedExecutableOrSharedLibrary)
ERRORTYPE_DECLARE(MalformedMachObject)
ERRORTYPE_DECLARE(DeviceError)
ERRORTYPE_DECLARE(NoSuchPolicy)
ERRORTYPE_DECLARE(DevicePowerIsOff)
ERRORTYPE_DECLARE(FullInterfaceOutputQueue)
ERRORTYPE_DECLARE(SharedLibraryVersionMismatch)
ERRORTYPE_DECLARE(IPSecProcessingFailure)
ERRORTYPE_DECLARE(NotPermittedInCapabilityMode)
ERRORTYPE_DECLARE(IntegrityCheckFailed)
ERRORTYPE_DECLARE(CapabilitiesInsufficient)
ERRORTYPE_DECLARE(InterruptedSyscallShouldBeRestarted)
ERRORTYPE_DECLARE(ChannelNumberOutOfRange)
ERRORTYPE_DECLARE(Level2NotSynchronized)
ERRORTYPE_DECLARE(Level3Halted)
ERRORTYPE_DECLARE(Level3Reset)
ERRORTYPE_DECLARE(LinkNumberOutOfRange)
ERRORTYPE_DECLARE(ProtocolDriverNotAttached)
ERRORTYPE_DECLARE(NoCSIStructure)
ERRORTYPE_DECLARE(Level2Halted)
ERRORTYPE_DECLARE(InvalidExchange)
ERRORTYPE_DECLARE(InvalidRequestDescriptor)
ERRORTYPE_DECLARE(ExchangeFull)
ERRORTYPE_DECLARE(NoAnode)
ERRORTYPE_DECLARE(InvalidRequestCode)
ERRORTYPE_DECLARE(InvalidSlot)
ERRORTYPE_DECLARE(FileLockingDeadlock)
ERRORTYPE_DECLARE(BadFontFileFormat)
ERRORTYPE_DECLARE(MachineIsNotOnTheNetwork)
ERRORTYPE_DECLARE(PackageNotInstalled)
ERRORTYPE_DECLARE(AdvertiseError)
ERRORTYPE_DECLARE(SrmountError)
ERRORTYPE_DECLARE(CommunicationErrorOnSend)
ERRORTYPE_DECLARE(RFSError)
ERRORTYPE_DECLARE(NameNotUniqueOnNetwork)
ERRORTYPE_DECLARE(FileDescriptorInBadState)
ERRORTYPE_DECLARE(RemoteAddressChanged)
ERRORTYPE_DECLARE(CannotAccessANeededSharedLibrary)
ERRORTYPE_DECLARE(AccessingACorruptedSharedLibrary)
ERRORTYPE_DECLARE(DotLibSectionCorrupted)
ERRORTYPE_DECLARE(TooManySharedLibraries)
ERRORTYPE_DECLARE(StreamsPipeError)
ERRORTYPE_DECLARE(StructureNeedsCleaning)
ERRORTYPE_DECLARE(NotXENIXNamedTypeFile)
ERRORTYPE_DECLARE(NoXENIXSemaphoresAvailable)
ERRORTYPE_DECLARE(IsANamedTypeFile)
ERRORTYPE_DECLARE(RemoteIOError)
ERRORTYPE_DECLARE(NoMediumFound)
ERRORTYPE_DECLARE(WrongMediumType)
ERRORTYPE_DECLARE(RequiredKeyNotAvailable)
ERRORTYPE_DECLARE(KeyHasExpired)
ERRORTYPE_DECLARE(KeyHasBeenRevoked)
ERRORTYPE_DECLARE(KeyWasRejectedByService)
ERRORTYPE_DECLARE(OperationPreventedByRFKILL)
ERRORTYPE_DECLARE(MemoryPageHasHardwareError)
ERRORTYPE_DECLARE(Async)
ERRORTYPE_DECLARE(UnknownError)

typedef struct {
    int c_errno;
    const ErrorType* error;
} ___ERRNO_BIND;

extern const int ___errno_binds_size;
extern const ___ERRNO_BIND ___errno_binds[];

#endif /* !RESULT_DISABLE_PORTS */

#endif
