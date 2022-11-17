#ifndef E2E_ERROR_DOMAIN_H
#define E2E_ERROR_DOMAIN_H

// [SWS_CM_99026] E2E errors domain
namespace ara{
    namespace com{
        namespace e2e{
            enum class E2EErrc : ara::core::ErrorDomain::CodeType {
                kRepeated = 1,       //Data has a repeated counter.
                kWrongSequence = 2,  //The checks of the Data in this cycle were successful, with the exception of counter jump,which changed more than the allowed delta.
                kError = 3,          //Error not related to counters occurred(e.g. wrongcrc, wrong length, wrong Data ID(or the return of the check function was not OK.
                kNotAvailable = 4,   //No value has been received yet(e.g. during initialization). This is used as the initialization value for the buffer, it is not returned by any E2E profile.
                kNoNewData = 5       //No new data is available.
            };

            enum class ProfileCheckStatus : std::uint8_t
            {
                kOk,            //OK
                kRepeated,      //REPEATED
                kWrongSequence, //WRONGSEQUENCE
                kError,         //WRONGCRC
                kCheckDisabled  //n/a
            };

            enum class SMState : std::uint8_t
            {
                kValid,         //VALID
                kNoData,        //NODATA, DEINIT
                kInit,          //INIT
                kInvalid,       //INVALID
                kStateMDisabled //n/a
            };

        } // namespace e2e
    } // namespace com
} // namespace ara

#endif