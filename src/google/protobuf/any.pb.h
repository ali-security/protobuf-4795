// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: google/protobuf/any.proto
// Protobuf C++ Version: 6.30.1

#ifndef google_2fprotobuf_2fany_2eproto_2epb_2eh
#define google_2fprotobuf_2fany_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/runtime_version.h"
#if PROTOBUF_VERSION != 6030001
#error "Protobuf C++ gencode is built with an incompatible version of"
#error "Protobuf C++ headers/runtime. See"
#error "https://protobuf.dev/support/cross-version-runtime-guarantee/#cpp"
#endif
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/message_lite.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_google_2fprotobuf_2fany_2eproto PROTOBUF_EXPORT

namespace google {
namespace protobuf {
namespace internal {
template <typename T>
::absl::string_view GetAnyMessageName();
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct PROTOBUF_EXPORT TableStruct_google_2fprotobuf_2fany_2eproto {
  static const ::uint32_t offsets[];
};
extern "C" {
PROTOBUF_EXPORT extern const ::google::protobuf::internal::DescriptorTable descriptor_table_google_2fprotobuf_2fany_2eproto;
}  // extern "C"
namespace google {
namespace protobuf {
class Any;
struct AnyDefaultTypeInternal;
PROTOBUF_EXPORT extern AnyDefaultTypeInternal _Any_default_instance_;
PROTOBUF_EXPORT extern const ::google::protobuf::internal::ClassDataFull Any_class_data_;
}  // namespace protobuf
}  // namespace google

namespace google {
namespace protobuf {

// ===================================================================


// -------------------------------------------------------------------

class PROTOBUF_EXPORT Any final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:google.protobuf.Any) */ {
 public:
  inline Any() : Any(nullptr) {}
  ~Any() PROTOBUF_FINAL;

#if defined(PROTOBUF_CUSTOM_VTABLE)
  void operator delete(Any* PROTOBUF_NONNULL msg, std::destroying_delete_t) {
    SharedDtor(*msg);
    ::google::protobuf::internal::SizedDelete(msg, sizeof(Any));
  }
#endif

  template <typename = void>
  explicit PROTOBUF_CONSTEXPR Any(::google::protobuf::internal::ConstantInitialized);

  inline Any(const Any& from) : Any(nullptr, from) {}
  inline Any(Any&& from) noexcept
      : Any(nullptr, std::move(from)) {}
  inline Any& operator=(const Any& from) {
    CopyFrom(from);
    return *this;
  }
  inline Any& operator=(Any&& from) noexcept {
    if (this == &from) return *this;
    if (::google::protobuf::internal::CanMoveWithInternalSwap(GetArena(), from.GetArena())) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* PROTOBUF_NONNULL mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* PROTOBUF_NONNULL descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* PROTOBUF_NONNULL GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* PROTOBUF_NONNULL GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Any& default_instance() {
    return *reinterpret_cast<const Any*>(
        &_Any_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  // implements Any
  // -----------------------------------------------

  bool PackFrom(const ::google::protobuf::Message& message) {
    ABSL_DCHECK_NE(&message, this);
    return ::google::protobuf::internal::InternalPackFrom(message, mutable_type_url(),
                                   _internal_mutable_value());
  }
  bool PackFrom(const ::google::protobuf::Message& message,
                ::absl::string_view type_url_prefix) {
    ABSL_DCHECK_NE(&message, this);
    return ::google::protobuf::internal::InternalPackFrom(message, type_url_prefix,
                                   mutable_type_url(),
                                   _internal_mutable_value());
  }
  bool UnpackTo(::google::protobuf::Message* PROTOBUF_NONNULL message) const {
    return ::google::protobuf::internal::InternalUnpackTo(_internal_type_url(),
                                   _internal_value(), message);
  }
  static bool GetAnyFieldDescriptors(
      const ::google::protobuf::Message& message,
      const ::google::protobuf::FieldDescriptor* PROTOBUF_NULLABLE* PROTOBUF_NONNULL
          type_url_field,
      const ::google::protobuf::FieldDescriptor* PROTOBUF_NULLABLE* PROTOBUF_NONNULL
          value_field);
  template <
      typename T,
      class = typename std::enable_if<!std::is_convertible<
          T, const ::google::protobuf::Message&>::value>::type>
  bool PackFrom(const T& message) {
    return ::google::protobuf::internal::InternalPackFrom<T>(
        message, mutable_type_url(), _internal_mutable_value());
  }
  template <
      typename T,
      class = typename std::enable_if<!std::is_convertible<
          T, const ::google::protobuf::Message&>::value>::type>
  bool PackFrom(const T& message,
                ::absl::string_view type_url_prefix) {
    return ::google::protobuf::internal::InternalPackFrom<T>(
        message, type_url_prefix, mutable_type_url(),
        _internal_mutable_value());
  }
  template <
      typename T,
      class = typename std::enable_if<!std::is_convertible<
          T, const ::google::protobuf::Message&>::value>::type>
  bool UnpackTo(T* PROTOBUF_NONNULL message) const {
    return ::google::protobuf::internal::InternalUnpackTo<T>(
        _internal_type_url(), _internal_value(), message);
  }

  template <typename T>
  bool Is() const {
    return ::google::protobuf::internal::InternalIs<T>(_internal_type_url());
  }
  static bool ParseAnyTypeUrl(
      ::absl::string_view type_url,
      std::string* PROTOBUF_NONNULL full_type_name);
  friend void swap(Any& a, Any& b) { a.Swap(&b); }
  inline void Swap(Any* PROTOBUF_NONNULL other) {
    if (other == this) return;
    if (::google::protobuf::internal::CanUseInternalSwap(GetArena(), other->GetArena())) {
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Any* PROTOBUF_NONNULL other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Any* PROTOBUF_NONNULL New(::google::protobuf::Arena* PROTOBUF_NULLABLE arena = nullptr) const {
    return ::google::protobuf::Message::DefaultConstruct<Any>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Any& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const Any& from) { Any::MergeImpl(*this, from); }

  private:
  static void MergeImpl(::google::protobuf::MessageLite& to_msg,
                        const ::google::protobuf::MessageLite& from_msg);

  public:
  bool IsInitialized() const {
    return true;
  }
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() PROTOBUF_FINAL;
  #if defined(PROTOBUF_CUSTOM_VTABLE)
  private:
  static ::size_t ByteSizeLong(const ::google::protobuf::MessageLite& msg);
  static ::uint8_t* PROTOBUF_NONNULL _InternalSerialize(
      const ::google::protobuf::MessageLite& msg, ::uint8_t* PROTOBUF_NONNULL target,
      ::google::protobuf::io::EpsCopyOutputStream* PROTOBUF_NONNULL stream);

  public:
  ::size_t ByteSizeLong() const { return ByteSizeLong(*this); }
  ::uint8_t* PROTOBUF_NONNULL _InternalSerialize(
      ::uint8_t* PROTOBUF_NONNULL target,
      ::google::protobuf::io::EpsCopyOutputStream* PROTOBUF_NONNULL stream) const {
    return _InternalSerialize(*this, target, stream);
  }
  #else   // PROTOBUF_CUSTOM_VTABLE
  ::size_t ByteSizeLong() const final;
  ::uint8_t* PROTOBUF_NONNULL _InternalSerialize(
      ::uint8_t* PROTOBUF_NONNULL target,
      ::google::protobuf::io::EpsCopyOutputStream* PROTOBUF_NONNULL stream) const final;
  #endif  // PROTOBUF_CUSTOM_VTABLE
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* PROTOBUF_NULLABLE arena);
  static void SharedDtor(MessageLite& self);
  void InternalSwap(Any* PROTOBUF_NONNULL other);
 private:
  template <typename T>
  friend ::absl::string_view(::google::protobuf::internal::GetAnyMessageName)();
  static ::absl::string_view FullMessageName() { return "google.protobuf.Any"; }

 protected:
  explicit Any(::google::protobuf::Arena* PROTOBUF_NULLABLE arena);
  Any(::google::protobuf::Arena* PROTOBUF_NULLABLE arena, const Any& from);
  Any(
      ::google::protobuf::Arena* PROTOBUF_NULLABLE arena, Any&& from) noexcept
      : Any(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::internal::ClassData* PROTOBUF_NONNULL GetClassData() const PROTOBUF_FINAL;
  static void* PROTOBUF_NONNULL PlacementNew_(
      const void* PROTOBUF_NONNULL, void* PROTOBUF_NONNULL mem,
      ::google::protobuf::Arena* PROTOBUF_NULLABLE arena);
  static constexpr auto InternalNewImpl_();

 public:
  static constexpr auto InternalGenerateClassData_();

  ::google::protobuf::Metadata GetMetadata() const;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kTypeUrlFieldNumber = 1,
    kValueFieldNumber = 2,
  };
  // string type_url = 1;
  void clear_type_url() ;
  const std::string& type_url() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_type_url(Arg_&& arg, Args_... args);
  std::string* PROTOBUF_NONNULL mutable_type_url();
  [[nodiscard]] std::string* PROTOBUF_NULLABLE release_type_url();
  void set_allocated_type_url(std::string* PROTOBUF_NULLABLE value);

  private:
  const std::string& _internal_type_url() const;
  PROTOBUF_ALWAYS_INLINE void _internal_set_type_url(const std::string& value);
  std::string* PROTOBUF_NONNULL _internal_mutable_type_url();

  public:
  // bytes value = 2;
  void clear_value() ;
  const std::string& value() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_value(Arg_&& arg, Args_... args);
  std::string* PROTOBUF_NONNULL mutable_value();
  [[nodiscard]] std::string* PROTOBUF_NULLABLE release_value();
  void set_allocated_value(std::string* PROTOBUF_NULLABLE value);

  private:
  const std::string& _internal_value() const;
  PROTOBUF_ALWAYS_INLINE void _internal_set_value(const std::string& value);
  std::string* PROTOBUF_NONNULL _internal_mutable_value();

  public:
  // @@protoc_insertion_point(class_scope:google.protobuf.Any)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<1, 2,
                                   0, 36,
                                   2>
      _table_;

  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(
        ::google::protobuf::internal::InternalVisibility visibility,
        ::google::protobuf::Arena* PROTOBUF_NULLABLE arena);
    inline explicit Impl_(
        ::google::protobuf::internal::InternalVisibility visibility,
        ::google::protobuf::Arena* PROTOBUF_NULLABLE arena, const Impl_& from,
        const Any& from_msg);
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    ::google::protobuf::internal::CachedSize _cached_size_;
    ::google::protobuf::internal::ArenaStringPtr type_url_;
    ::google::protobuf::internal::ArenaStringPtr value_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_google_2fprotobuf_2fany_2eproto;
};

PROTOBUF_EXPORT extern const ::google::protobuf::internal::ClassDataFull Any_class_data_;

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// Any

// string type_url = 1;
inline void Any::clear_type_url() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.type_url_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& Any::type_url() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:google.protobuf.Any.type_url)
  return _internal_type_url();
}
template <typename Arg_, typename... Args_>
PROTOBUF_ALWAYS_INLINE void Any::set_type_url(Arg_&& arg, Args_... args) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.type_url_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:google.protobuf.Any.type_url)
}
inline std::string* PROTOBUF_NONNULL Any::mutable_type_url()
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_type_url();
  // @@protoc_insertion_point(field_mutable:google.protobuf.Any.type_url)
  return _s;
}
inline const std::string& Any::_internal_type_url() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.type_url_.Get();
}
inline void Any::_internal_set_type_url(const std::string& value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.type_url_.Set(value, GetArena());
}
inline std::string* PROTOBUF_NONNULL Any::_internal_mutable_type_url() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.type_url_.Mutable( GetArena());
}
inline std::string* PROTOBUF_NULLABLE Any::release_type_url() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:google.protobuf.Any.type_url)
  if ((_impl_._has_bits_[0] & 0x00000001u) == 0) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* released = _impl_.type_url_.Release();
  if (::google::protobuf::internal::DebugHardenForceCopyDefaultString()) {
    _impl_.type_url_.Set("", GetArena());
  }
  return released;
}
inline void Any::set_allocated_type_url(std::string* PROTOBUF_NULLABLE value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.type_url_.SetAllocated(value, GetArena());
  if (::google::protobuf::internal::DebugHardenForceCopyDefaultString() && _impl_.type_url_.IsDefault()) {
    _impl_.type_url_.Set("", GetArena());
  }
  // @@protoc_insertion_point(field_set_allocated:google.protobuf.Any.type_url)
}

// bytes value = 2;
inline void Any::clear_value() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.value_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline const std::string& Any::value() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:google.protobuf.Any.value)
  return _internal_value();
}
template <typename Arg_, typename... Args_>
PROTOBUF_ALWAYS_INLINE void Any::set_value(Arg_&& arg, Args_... args) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.value_.SetBytes(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:google.protobuf.Any.value)
}
inline std::string* PROTOBUF_NONNULL Any::mutable_value()
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_value();
  // @@protoc_insertion_point(field_mutable:google.protobuf.Any.value)
  return _s;
}
inline const std::string& Any::_internal_value() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.value_.Get();
}
inline void Any::_internal_set_value(const std::string& value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.value_.Set(value, GetArena());
}
inline std::string* PROTOBUF_NONNULL Any::_internal_mutable_value() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_._has_bits_[0] |= 0x00000002u;
  return _impl_.value_.Mutable( GetArena());
}
inline std::string* PROTOBUF_NULLABLE Any::release_value() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:google.protobuf.Any.value)
  if ((_impl_._has_bits_[0] & 0x00000002u) == 0) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000002u;
  auto* released = _impl_.value_.Release();
  if (::google::protobuf::internal::DebugHardenForceCopyDefaultString()) {
    _impl_.value_.Set("", GetArena());
  }
  return released;
}
inline void Any::set_allocated_value(std::string* PROTOBUF_NULLABLE value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }
  _impl_.value_.SetAllocated(value, GetArena());
  if (::google::protobuf::internal::DebugHardenForceCopyDefaultString() && _impl_.value_.IsDefault()) {
    _impl_.value_.Set("", GetArena());
  }
  // @@protoc_insertion_point(field_set_allocated:google.protobuf.Any.value)
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace protobuf
}  // namespace google


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // google_2fprotobuf_2fany_2eproto_2epb_2eh
