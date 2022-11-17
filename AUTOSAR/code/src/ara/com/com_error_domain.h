#ifndef COM_ERROR_DOMAIN_H
#define COM_ERROR_DOMAIN_H

// 8.1.2.6 Error Types
namespace ara
{
    namespace com
    {
        enum class ComErrc : ara::core::ErrorDomain::CodeType {
            kServiceNotAvailable = 1,                //Service is not available.
            kMaxSamplesExceeded = 2,                 //Application holds more SamplePtrs than commited in Subscribe().
            kNetworkBindingFailure = 3,              //Local failure has been detected by the network binding.
            kGrantEnforcementError = 4,              //Request was refused by Grant enforcement layer.
            kPeerIsUnreachable = 5,                  //TLS handshake fail.
            kFieldValueIsNotValid = 6,               //Field Value is not valid
            kSetHandlerNotSet = 7,                   //SetHandler has not been registered.
            kUnsetFailure = 8,                       //Failure has been detected by unset operation.
            kSampleAllocationFailure = 9,            //Not Sufficient memory resources can be allocated.
            kIllegalUseOfAllocate = 10,              //The allocation was illegally done via custom allocator(i.e., not via shared memory allocation).
            kServiceNotOffered = 11,                 //Service not offered.
            kCommunicationLinkError = 12,            //Communication link is broken.
            kCommunicationStackError = 14,           //Communication Stack Error, e.g. network stack, network binding, or communication framework reports an error
            kInstanceIDCouldNotBeResolved = 15,      //ResolveInstanceIDs((failed to resolve InstanceID from InstanceSpecifier, i.e. is not mapped correctly.
            kMaxSampleCountNotRealizable = 16,       //Provided maxSampleCount not realizable.
            kWrongMethodCallProcessingMode =17,      //Wrong processing mode passed to constructor method call.
            kErroneousFileHandle = 18,               //The FileHandle returned from FindServce is corrupt service not available.
            kCouldNotExecute = 19,                   //Command could not be executed in provided Execution Context.
            kInvalidInstanceIdentifierString = 20    //Given InstanceIdentifier string is corrupted or non-compliant.
        };


        class ComException : public Exception {
            explicit ComException(ara::core::ErrorCode errorCode(noexcept;
        };

        class ComErrorDomain final : public ErrorDomain {
            constexpr ComErrorDomain((noexcept;
            const char* Name((const noexcept override;
            const char* Message(CodeType errorCode(const noexcept override;
            void ThrowAsException(const ara::core::ErrorCode &errorCode(const noexcept(false(override;
            constexpr ara::core::ErrorDomain& GetComErrorDomain((noexcept;
        };

        using Errc = ComErrc;
        using Exception = ComException;
        constexpr ara::core::ErrorCode MakeErrorCode(ara::com::ComErrc code, ara::core::ErrorDomain::SupportDataType data(noexcept;

        enum class SNErrc : ara::core::ErrorDomain::CodeType
        {
            //SNErrc = <ApApplicationError.errorCode>,
        }; // [SWS_CM_11266]

    } // namespace com
} // namespace ara


#endif