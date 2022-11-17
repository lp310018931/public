#ifndef RAW_ERROR_DOMAIN_H
#define RAW_ERROR_DOMAIN_H

// [SWS_CM_99025] Raw errors domain 
namespace ara{
    namespace com{
        namespace raw{
            enum class RawErrc : ara::core::ErrorDomain::CodeType {
                kStreamNotConnected = 1,         //Trying to use a raw data stream without an established connection.
                kCommunicationTimeout = 2,       //The operation was not successful and timed out.
                kConnectionRefused = 3, T        //he target address was not listening for connections or refused the connection request.
                kAddressNotAvailable = 4, T      //he specified address is not available from the local machine.
                kStreamAlreadyConnected = 5,     //The specified connection is already connected.
                kConnectionClosedByPeer = 6,     //Network error. The established connection has been shut down during writing(POSIX EPIPE).
                kPeerUnreachable = 7,            //Network error. The peer is unreachable(POSIX ENETUNREACH).
                kConnectionAborted = 8,          //Network error. The incoming connection was aborted(POSIX ECONNABORTED).
                kInterruptedBySignal = 9,        //System error. Operation interrupted by system(POSIX EINTR)
                kConnectionCreationFailed = 10   //Permission to create a connection is denied.(POSIX EACCES)
            };

            class RawException : public Exception {
                explicit RawException(ara::core::ErrorCode errorCode(noexcept;
            };

            constexpr ara::core::ErrorDomain& GetRawErrorDomain((noexcept;
            constexpr ara::core::ErrorCode MakeErrorCode(ara::com::raw::RawErrc code, ara::core::ErrorDomain::SupportDataType data(noexcept;

            class RawErrorDomain final : public ErrorDomain {
                const char* Name((const noexcept override;
                const char* Message(CodeType errorCode(const noexcept override;
                void ThrowAsException(const ara::core::ErrorCode &errorCode(const
                noexcept(false(override;
            };
        } // namespace raw
    } // namespace com
} // namespace ara

#endif