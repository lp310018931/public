#ifndef RAW_DATA_STREAM_H
#define RAW_DATA_STREAM_H

//8.1.1.5 Raw Data Stream header file
//The Raw data stream header file shall include the class definitions according
//to [SWS_CM_10481], [SWS_CM_10482], [SWS_CM_10483], [SWS_CM_10484],
//[SWS_CM_10485], [SWS_CM_10486] and [SWS_CM_10487].c(RS_CM_00001)

namespace ara
{
    namespace com
    {
        namespace raw
        {
            class RawDataStreamClient final 
            {
                ara::core::Result<RawDataStreamClient> Create(const ara::core::InstanceSpecifier &instance) noexcept;
                ~RawDataStreamClient() noexcept;
                RawDataStreamClient(const RawDataStreamClient &)=delete;
                RawDataStreamClient& operator=(const RawDataStreamClient &)=delete;
                RawDataStreamClient(RawDataStreamClient &&other) noexcept;
                RawDataStreamClient& operator=(RawDataStreamClient &&other) noexcept;
                ara::core::Result<void> Connect() noexcept;
                ara::core::Result<void> Connect(std::chrono::milliseconds timeout) noexcept;
                ara::core::Result<void> Shutdown() noexcept;
                ara::core::Result<ReadDataResult> ReadData(std::size_t maxLength)noexcept;
                ara::core::Result<ReadDataResult> ReadData(std::size_t maxLength, std::chrono::milliseconds timeout) noexcept;
                ara::core::Result<std::size_t> WriteData(ara::com::SamplePtr<std::uint8_t> data, std::size_t maxLength) noexcept;

                ara::core::Result<std::size_t> WriteData(ara::com::SamplePtr<std::uint8_t> data, std::size_t maxLength, std::chrono::millisecondstimeout) noexcept;
            };  // [SWS_CM_10481]


            class RawDataStreamServer final
            {
                ara::core::Result<RawDataStreamServer> Create(constara::core::InstanceSpecifier &instance) noexcept;
                ~RawDataStreamServer() noexcept;
                RawDataStreamServer(const RawDataStreamServer &)=delete;
                RawDataStreamServer& operator=(const RawDataStreamServer &)=delete;
                RawDataStreamServer(RawDataStreamServer &&other) noexcept;
                RawDataStreamServer& operator=(RawDataStreamServer &&other)noexcept;
                ara::core::Result<void> WaitForConnection() noexcept;
                ara::core::Result<void> WaitForConnection(std::chrono::millisecondstimeout) noexcept;
                ara::core::Result<void> Shutdown() noexcept;
                ara::core::Result<ReadDataResult> ReadData(std::size_t maxLength)noexcept;
                ara::core::Result<ReadDataResult> ReadData(std::size_t maxLength, std::chrono::milliseconds timeout) noexcept;
                ara::core::Result<std::size_t> WriteData(ara::com::SamplePtr<std::uint8_t> data, std::size_t maxLength) noexcept;
                ara::core::Result<std::size_t> WriteData(ara::com::SamplePtr<std::uint8_t> data, std::size_t maxLength, std::chrono::millisecondstimeout) noexcept;
            }; // [SWS_CM_10482]


            // [SWS_CM_10483]


            //[SWS_CM_10484]
        

            //[SWS_CM_10485]

            
            //[SWS_CM_10486]

            
            //[SWS_CM_10487]
            
            
            //(RS_CM_00001)




        } // namespace raw
    } // namespace com
} // namespace ara

#endif

