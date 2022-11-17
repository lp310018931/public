#ifndef VARIANT_H
#define VARIANT_H

// 8.1.2.5.3 Variant Data Types
namespace ara
{
    namespace com
    {
        template< class... Types >
        class Variant {
            // Default constructor
            Variant() noexcept;
            // Move constructor
            Variant( Variant&& ) noexcept;
            // Copy constructor
            Variant( const Variant& );
            // Converting constructor
            template< class T >
            Variant ( T&& ) noexcept;
            // Explicit converting constructors
            template< class T, class... Args >
            explicit Variant ( std::in_place_type_t<T> , Arg&&... );
            template< class T, class U, class... Args >
            explicit Variant ( std::in_place_type_t<T> , std::initializer_list<U>, Arg&&... );
            template< std::size_t I, class... Args >
            explicit Variant ( std::in_place_index_t<I> , Arg&&... );
            template< std::size_t I, class U, class... Args >
            explicit Variant ( std::in_place_index_t<I> , std::initializer_list<U>,Arg&&... );
            // Destructor
            ~Variant() noexcept;
            // Move assignment operator
            Variant& operator=( Variant&& ) noexcept;
            // Default copy assignment operator
            Variant& operator=( const Variant& );
            // Converting assignment operator
            template < class T >
            Variant& operator=( T&& ) noexcept;
            // Returns the zero-based index of the alternative
            std::size_t index();
            // Checks if the Variant is an invalid state
            bool valueless_by_exception() const noexcept;
            // Modifiers
            template < class T, class... Args >
            void emplace( Args&&... );
            template < class T, class U, class... Args >
            void emplace( std::initializer_list<U> , Args&&... );
            template < std::size_t I, class... Args >
            void emplace( Args&&... );
            template <std::size_t I, class U, class... Args>
            void emplace( initializer_list<U> , Args&&... );
            // Swap
            void swap( Variant& ) noexcept;
        };






    } // namespace com
} // namespace ara

#endif

