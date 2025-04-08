// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: google/protobuf/any.proto
// Protobuf C++ Version: 6.31.0-dev

#include "google/protobuf/any.pb.h"

#include <algorithm>
#include <type_traits>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/generated_message_tctable_impl.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
#if defined(__llvm__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wuninitialized"
#endif  // __llvm__
namespace google {
namespace protobuf {

inline constexpr Any::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        type_url_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        value_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()) {}

template <typename>
PROTOBUF_CONSTEXPR Any::Any(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(Any_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
      _impl_(::_pbi::ConstantInitialized()) {
}
struct AnyDefaultTypeInternal {
  PROTOBUF_CONSTEXPR AnyDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~AnyDefaultTypeInternal() {}
  union {
    Any _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_EXPORT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 AnyDefaultTypeInternal _Any_default_instance_;
}  // namespace protobuf
}  // namespace google
static constexpr const ::_pb::EnumDescriptor *PROTOBUF_NONNULL *PROTOBUF_NULLABLE
    file_level_enum_descriptors_google_2fprotobuf_2fany_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor *PROTOBUF_NONNULL *PROTOBUF_NULLABLE
    file_level_service_descriptors_google_2fprotobuf_2fany_2eproto = nullptr;
const ::uint32_t
    TableStruct_google_2fprotobuf_2fany_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        0x081, // bitmap
        PROTOBUF_FIELD_OFFSET(::google::protobuf::Any, _impl_._has_bits_),
        5, // hasbit index offset
        PROTOBUF_FIELD_OFFSET(::google::protobuf::Any, _impl_.type_url_),
        PROTOBUF_FIELD_OFFSET(::google::protobuf::Any, _impl_.value_),
        0,
        1,
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, sizeof(::google::protobuf::Any)},
};
static const ::_pb::Message* PROTOBUF_NONNULL const file_default_instances[] = {
    &::google::protobuf::_Any_default_instance_._instance,
};
const char descriptor_table_protodef_google_2fprotobuf_2fany_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\031google/protobuf/any.proto\022\017google.prot"
    "obuf\"&\n\003Any\022\020\n\010type_url\030\001 \001(\t\022\r\n\005value\030\002"
    " \001(\014Bv\n\023com.google.protobufB\010AnyProtoP\001Z"
    ",google.golang.org/protobuf/types/known/"
    "anypb\242\002\003GPB\252\002\036Google.Protobuf.WellKnownT"
    "ypesb\006proto3"
};
static ::absl::once_flag descriptor_table_google_2fprotobuf_2fany_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_google_2fprotobuf_2fany_2eproto = {
    false,
    false,
    212,
    descriptor_table_protodef_google_2fprotobuf_2fany_2eproto,
    "google/protobuf/any.proto",
    &descriptor_table_google_2fprotobuf_2fany_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_google_2fprotobuf_2fany_2eproto::offsets,
    file_level_enum_descriptors_google_2fprotobuf_2fany_2eproto,
    file_level_service_descriptors_google_2fprotobuf_2fany_2eproto,
};
namespace google {
namespace protobuf {
// ===================================================================

bool Any::GetAnyFieldDescriptors(
    const ::google::protobuf::Message& message,
    const ::google::protobuf::FieldDescriptor** type_url_field,
    const ::google::protobuf::FieldDescriptor** value_field) {
  return ::_pbi::GetAnyFieldDescriptors(message, type_url_field, value_field);
}
bool Any::ParseAnyTypeUrl(
    ::absl::string_view type_url,
    std::string* PROTOBUF_NONNULL full_type_name) {
  return ::_pbi::ParseAnyTypeUrl(type_url, full_type_name);
}
class Any::_Internal {
 public:
  using HasBits =
      decltype(::std::declval<Any>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
      8 * PROTOBUF_FIELD_OFFSET(Any, _impl_._has_bits_);
};

Any::Any(::google::protobuf::Arena* PROTOBUF_NULLABLE arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, Any_class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:google.protobuf.Any)
}
PROTOBUF_NDEBUG_INLINE Any::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* PROTOBUF_NULLABLE arena, const Impl_& from,
    const ::google::protobuf::Any& from_msg)
      : _has_bits_{from._has_bits_},
        _cached_size_{0},
        type_url_(arena, from.type_url_),
        value_(arena, from.value_) {}

Any::Any(
    ::google::protobuf::Arena* PROTOBUF_NULLABLE arena,
    const Any& from)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, Any_class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  Any* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);

  // @@protoc_insertion_point(copy_constructor:google.protobuf.Any)
}
PROTOBUF_NDEBUG_INLINE Any::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* PROTOBUF_NULLABLE arena)
      : _cached_size_{0},
        type_url_(arena),
        value_(arena) {}

inline void Any::SharedCtor(::_pb::Arena* PROTOBUF_NULLABLE arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
Any::~Any() {
  // @@protoc_insertion_point(destructor:google.protobuf.Any)
  SharedDtor(*this);
}
inline void Any::SharedDtor(MessageLite& self) {
  Any& this_ = static_cast<Any&>(self);
  this_._internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  ABSL_DCHECK(this_.GetArena() == nullptr);
  this_._impl_.type_url_.Destroy();
  this_._impl_.value_.Destroy();
  this_._impl_.~Impl_();
}

inline void* PROTOBUF_NONNULL Any::PlacementNew_(
    const void* PROTOBUF_NONNULL, void* PROTOBUF_NONNULL mem,
    ::google::protobuf::Arena* PROTOBUF_NULLABLE arena) {
  return ::new (mem) Any(arena);
}
constexpr auto Any::InternalNewImpl_() {
  return ::google::protobuf::internal::MessageCreator::CopyInit(sizeof(Any),
                                            alignof(Any));
}
constexpr auto Any::InternalGenerateClassData_() {
  return ::google::protobuf::internal::ClassDataFull{
      ::google::protobuf::internal::ClassData{
          &_Any_default_instance_._instance,
          &_table_.header,
          nullptr,  // OnDemandRegisterArenaDtor
          nullptr,  // IsInitialized
          &Any::MergeImpl,
          ::google::protobuf::Message::GetNewImpl<Any>(),
#if defined(PROTOBUF_CUSTOM_VTABLE)
          &Any::SharedDtor,
          ::google::protobuf::Message::GetClearImpl<Any>(), &Any::ByteSizeLong,
              &Any::_InternalSerialize,
#endif  // PROTOBUF_CUSTOM_VTABLE
          PROTOBUF_FIELD_OFFSET(Any, _impl_._cached_size_),
          false,
      },
      &Any::kDescriptorMethods,
      &descriptor_table_google_2fprotobuf_2fany_2eproto,
      nullptr,  // tracker
  };
}

PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 const
    ::google::protobuf::internal::ClassDataFull Any_class_data_ =
        Any::InternalGenerateClassData_();

const ::google::protobuf::internal::ClassData* PROTOBUF_NONNULL Any::GetClassData() const {
  ::google::protobuf::internal::PrefetchToLocalCache(&Any_class_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(Any_class_data_.tc_table);
  return Any_class_data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<1, 2, 0, 36, 2>
Any::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(Any, _impl_._has_bits_),
    0, // no _extensions_
    2, 8,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967292,  // skipmap
    offsetof(decltype(_table_), field_entries),
    2,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    Any_class_data_.base(),
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::google::protobuf::Any>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // bytes value = 2;
    {::_pbi::TcParser::FastBS1,
     {18, 1, 0, PROTOBUF_FIELD_OFFSET(Any, _impl_.value_)}},
    // string type_url = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 0, 0, PROTOBUF_FIELD_OFFSET(Any, _impl_.type_url_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string type_url = 1;
    {PROTOBUF_FIELD_OFFSET(Any, _impl_.type_url_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // bytes value = 2;
    {PROTOBUF_FIELD_OFFSET(Any, _impl_.value_), _Internal::kHasBitsOffset + 1, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kBytes | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\23\10\0\0\0\0\0\0"
    "google.protobuf.Any"
    "type_url"
  }},
};
PROTOBUF_NOINLINE void Any::Clear() {
// @@protoc_insertion_point(message_clear_start:google.protobuf.Any)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if ((cached_has_bits & 0x00000003u) != 0) {
    if ((cached_has_bits & 0x00000001u) != 0) {
      _impl_.type_url_.ClearNonDefaultToEmpty();
    }
    if ((cached_has_bits & 0x00000002u) != 0) {
      _impl_.value_.ClearNonDefaultToEmpty();
    }
  }
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
::uint8_t* PROTOBUF_NONNULL Any::_InternalSerialize(
    const ::google::protobuf::MessageLite& base, ::uint8_t* PROTOBUF_NONNULL target,
    ::google::protobuf::io::EpsCopyOutputStream* PROTOBUF_NONNULL stream) {
  const Any& this_ = static_cast<const Any&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
::uint8_t* PROTOBUF_NONNULL Any::_InternalSerialize(
    ::uint8_t* PROTOBUF_NONNULL target,
    ::google::protobuf::io::EpsCopyOutputStream* PROTOBUF_NONNULL stream) const {
  const Any& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
  // @@protoc_insertion_point(serialize_to_array_start:google.protobuf.Any)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // string type_url = 1;
  if ((this_._impl_._has_bits_[0] & 0x00000001u) != 0) {
    if (!this_._internal_type_url().empty()) {
      const ::std::string& _s = this_._internal_type_url();
      ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
          _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "google.protobuf.Any.type_url");
      target = stream->WriteStringMaybeAliased(1, _s, target);
    }
  }

  // bytes value = 2;
  if ((this_._impl_._has_bits_[0] & 0x00000002u) != 0) {
    if (!this_._internal_value().empty()) {
      const ::std::string& _s = this_._internal_value();
      target = stream->WriteBytesMaybeAliased(2, _s, target);
    }
  }

  if (ABSL_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:google.protobuf.Any)
  return target;
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
::size_t Any::ByteSizeLong(const MessageLite& base) {
  const Any& this_ = static_cast<const Any&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
::size_t Any::ByteSizeLong() const {
  const Any& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
  // @@protoc_insertion_point(message_byte_size_start:google.protobuf.Any)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void)cached_has_bits;

  ::_pbi::Prefetch5LinesFrom7Lines(&this_);
  cached_has_bits = this_._impl_._has_bits_[0];
  if ((cached_has_bits & 0x00000003u) != 0) {
    // string type_url = 1;
    if ((cached_has_bits & 0x00000001u) != 0) {
      if (!this_._internal_type_url().empty()) {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                        this_._internal_type_url());
      }
    }
    // bytes value = 2;
    if ((cached_has_bits & 0x00000002u) != 0) {
      if (!this_._internal_value().empty()) {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::BytesSize(
                                        this_._internal_value());
      }
    }
  }
  return this_.MaybeComputeUnknownFieldsSize(total_size,
                                             &this_._impl_._cached_size_);
}

void Any::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<Any*>(&to_msg);
  auto& from = static_cast<const Any&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:google.protobuf.Any)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._impl_._has_bits_[0];
  if ((cached_has_bits & 0x00000003u) != 0) {
    if ((cached_has_bits & 0x00000001u) != 0) {
      if (!from._internal_type_url().empty()) {
        _this->_internal_set_type_url(from._internal_type_url());
      } else {
        if (_this->_impl_.type_url_.IsDefault()) {
          _this->_internal_set_type_url("");
        }
      }
    }
    if ((cached_has_bits & 0x00000002u) != 0) {
      if (!from._internal_value().empty()) {
        _this->_internal_set_value(from._internal_value());
      } else {
        if (_this->_impl_.value_.IsDefault()) {
          _this->_internal_set_value("");
        }
      }
    }
  }
  _this->_impl_._has_bits_[0] |= cached_has_bits;
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Any::CopyFrom(const Any& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:google.protobuf.Any)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void Any::InternalSwap(Any* PROTOBUF_RESTRICT PROTOBUF_NONNULL other) {
  using ::std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.type_url_, &other->_impl_.type_url_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.value_, &other->_impl_.value_, arena);
}

::google::protobuf::Metadata Any::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace protobuf
}  // namespace google
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
#if defined(__llvm__)
#pragma clang diagnostic pop
#endif  // __llvm__
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::std::false_type
    _static_init2_ [[maybe_unused]] =
        (::_pbi::AddDescriptors(&descriptor_table_google_2fprotobuf_2fany_2eproto),
         ::std::false_type{});
#include "google/protobuf/port_undef.inc"
