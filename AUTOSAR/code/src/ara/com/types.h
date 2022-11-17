#ifndef TYPES_H
#define TYPES_H

//The Types header file shall include the data type definitions according to
//[SWS_CM_00301], [SWS_CM_00302], [SWS_CM_00303], [SWS_CM_00304],
//[SWS_CM_00383], [SWS_CM_00306], [SWS_CM_00308], [SWS_CM_00309],
//[SWS_CM_00310], and [SWS_CM_00311].c(RS_CM_00001)

namespace ara
{
    namespace com
    {
        enum class MethodCallProcessingMode:std::uint8_t {
            kPoll,
            kEvent,
            kEventSingleThread
        }; // [SWS_CM_00301]

        class InstanceIdentifier {
        public:
            static ara::core::Result<InstanceIdentifier> Create(StringView
            serializedFormat) noexcept;
            explicit InstanceIdentifier( ara::core::StringView serializedFormat);
            ara::core::StringView ToString() const;
            bool operator==(const InstanceIdentifier& other) const;
            bool operator<(const InstanceIdentifier& other) const;
            InstanceIdentifier& operator=(const InstanceIdentifier& other);
        }; // [SWS_CM_00302]

        struct FindServiceHandle {
            internal::ServiceId serviceIdentifier;
            internal::InstanceId instanceIdentifier;
            std::uint32_t uid;
            bool operator==(const FindServiceHandle& other) const;
            bool operator<(const FindServiceHandle& other) const;
            FindServiceHandle& operator=(const FindServiceHandle& other);
        }; // [SWS_CM_00303]

        template <typename T> 
        using ServiceHandleContainer = ara::core::Vector<T>; // [SWS_CM_00304]

        template <typename T>
        using FindServiceHandler = std::function<void(ServiceHandleContainer<T>, FindServiceHandle)>; // [SWS_CM_00383]

        template< typename T >
        class SamplePtr {
            // Default constructor
            constexpr SamplePtr() noexcept;
            // semantically equivalent to Default constructor
            constexpr SamplePtr(std::nullptr_t) noexcept;
            // Copy constructor is deleted
            SamplePtr ( const SamplePtr& ) = delete;
            // Move constructor
            SamplePtr( SamplePtr&& ) noexcept;
            // Destructor
            ~SamplePtr() noexcept;
            // Default copy assignment operator is deleted
            SamplePtr& operator=( const SamplePtr& ) = delete;
            // Assignment of nullptr_t
            SamplePtr& operator=(std::nullptr_t) noexcept;
            // Move assignment operator
            SamplePtr& operator=( SamplePtr&& ) noexcept;
            // Dereferences the stored pointer
            T& operator*() const noexcept;
            T* operator->() const noexcept;
            //Checks if the stored pointer is null
            explicit operator bool () const noexept;
            // Swaps the managed object
            void Swap ( SamplePtr& ) noexcept;
            //Replaces the managed object
            void Reset (std::nullptr_t) noexcept;
            //Returns the stored object
            T* Get () const noexcept;
            // Returns the end 2 end protection check result
            ara::com::e2e::ProfileCheckStatus GetProfileCheckStatus() const noexcept;
        }; // [SWS_CM_00306]

        template <typename T>
        using SampleAllocateePtr = std::unique_ptr<T>; // [SWS_CM_00308]

        using EventReceiveHandler = std::function<void()>; // [SWS_CM_00309]

        enum class SubscriptionState : std::uint8_t {
            kSubscribed,
            kNotSubscribed,
            kSubscriptionPending
        }; // [SWS_CM_00310]

        using SubscriptionStateChangeHandler = std::function<void(SubscriptionState)>; // [SWS_CM_00311]


        // RS_CM_00001 ...




    } // namespace com
} // namespace ara

#endif

