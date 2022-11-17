#ifndef FVM_H
#define FVM_H

// B Platform Extension API(normative)
namespace ara{
    namespace com{
        namespace secoc{
            class FVM {
                ara::core::Result<FVContainer, SecOcFvmErrc> GetRxFreshness(std::uint16_t SecOCFreshnessValueID, 
                const FVContainer &SecOCTruncatedFreshnessValue, std::uint16_t SecOCAuthVerifyAttempts(noexcept;
                ara::core::Result<FVContainer, SecOcFvmErrc> GetTxFreshness(std::uint16_t SecOCFreshnessValueID(noexcept;
                ara::core::Result<void> Initialize((noexcept;
            };

            struct FVContainer {
                std::uint64_t length;
                ara::core::Vector<std::uint8_t> value;
            };
                
            enum class SecOcFvmErrc : ara::core::ErrorDomain::CodeType {
                kFVNotAvailable = 1,      //Recoverable Error meaning the Freshness Value not available.
                kFVInitializeFailed = 2,  //Unrecoverable Error meaning the
            };

        } // namespace secoc
    } // namespace com
} // namespace ara

#endif