#ifndef SOMEIP_H
#define SOMEIP_H

//8.1.2.1 Service Identifier Data Types
namespace ara
{
    namespace com
    {
        class someip{
        public:
            static const serviceIdentifierType serviceIdentifier;
            static std::uint32_t serviceContractVersionMajor;
            static std::uint32_t serviceContractVersionMinor;
        };

        class serviceIdentifierType {
            bool operator==(const serviceIdentifierType& other(const;
            bool operator<(const serviceIdentifierType& other(const;
            serviceIdentifierType& operator=(const serviceIdentifierType& other);
            ara::core::StringView ToString((const;
        };

        class InstanceIdentifier {
        public:
            static ara::core::Result<InstanceIdentifier> Create(StringViewserializedFormat(noexcept;
            explicit InstanceIdentifier(ara::core::StringView serializedFormat);
            ara::core::StringView ToString((const;
            bool operator==(const InstanceIdentifier& other(const;
            bool operator<(const InstanceIdentifier& other(const;
            InstanceIdentifier& operator=(const InstanceIdentifier& other);
        };

        using InstanceIdentifierContainer = ara::core::Vector<InstanceIdentifier>;

        struct FindServiceHandle {
            internal::ServiceId serviceIdentifier;
            internal::InstanceId instanceIdentifier;
            std::uint32_t uid;
            bool operator==(const FindServiceHandle& other(const;
            bool operator<(const FindServiceHandle& other(const;
            FindServiceHandle& operator=(const FindServiceHandle& other);
        };

        class HandleType {
        public:
            HandleType(const HandleType&);
            HandleType& operator=(const HandleType&);
            HandleType(HandleType &&);
            HandleType& operator=(HandleType &&);
            ~HandleType((noexcept;
            bool operator==(const HandleType& other(const;
            bool operator<(const HandleType& other(const;
            const ara::com::InstanceIdentifier& GetInstanceId((const;
        };

        template <typename T>
        using ServiceHandleContainer = ara::core::Vector<T>;

        template <typename T>
        using FindServiceHandler = std::function<void(ServiceHandleContainer<T>, FindServiceHandle)>;

        //[SWS_CM_00306]
        template< typename T >
        class SamplePtr {
            // Default constructor
            constexpr SamplePtr((noexcept;
            // semantically equivalent to Default constructor
            constexpr SamplePtr(std::nullptr_t(noexcept;
            // Copy constructor is deleted
            SamplePtr(const SamplePtr&(= delete;
            // Move constructor
            SamplePtr(SamplePtr&&(noexcept;
            // Destructor
            ~SamplePtr((noexcept;
            // Default copy assignment operator is deleted
            SamplePtr& operator=(const SamplePtr&(= delete;
            // Assignment of nullptr_t
            SamplePtr& operator=(std::nullptr_t(noexcept;
            // Move assignment operator
            SamplePtr& operator=(SamplePtr&&(noexcept;
            // Dereferences the stored pointer
            T& operator*((const noexcept;
            T* operator->((const noexcept;
            //Checks if the stored pointer is null
            explicit operator bool((const noexept;
            // Swaps the managed object
            void Swap(SamplePtr&(noexcept;
            //Replaces the managed object
            void Reset(std::nullptr_t(noexcept;
            //Returns the stored object
            T* Get((const noexcept;
            // Returns the end 2 end protection check result
            ara::com::e2e::ProfileCheckStatus GetProfileCheckStatus((const noexcept;
        };

        ara::com::e2e::ProfileCheckStatus GetProfileCheckStatus((const noexcept;

        template <typename T>
        using SampleAllocateePtr = std::unique_ptr<T>;
        using EventReceiveHandler = std::function<void()>;

        enum class SubscriptionState : std::uint8_t {
            kSubscribed,
            kNotSubscribed,
            kSubscriptionPending
        };

        using SubscriptionStateChangeHandler = std::function<void(SubscriptionState)>;
        using TriggerReceiveHandler = std::function<void()>;

        enum class MethodCallProcessingMode : std::uint8_t {
            kPoll,
            kEvent,
            kEventSingleThread
        };

    } // namespace com
} // namespace ara

#endif

