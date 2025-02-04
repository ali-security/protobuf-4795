// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: google/protobuf/timestamp.proto
// Protobuf C++ Version: 6.30.0-rc1

#include "google/protobuf/timestamp.pb.h"

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
namespace google {
namespace protobuf {

inline constexpr Timestamp::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        seconds_{::int64_t{0}},
        nanos_{0} {}

template <typename>
PROTOBUF_CONSTEXPR Timestamp::Timestamp(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(Timestamp_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
      _impl_(::_pbi::ConstantInitialized()) {
}
struct TimestampDefaultTypeInternal {
  PROTOBUF_CONSTEXPR TimestampDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~TimestampDefaultTypeInternal() {}
  union {
    Timestamp _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_EXPORT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 TimestampDefaultTypeInternal _Timestamp_default_instance_;
}  // namespace protobuf
}  // namespace google
static constexpr const ::_pb::EnumDescriptor *PROTOBUF_NONNULL *PROTOBUF_NULLABLE
    file_level_enum_descriptors_google_2fprotobuf_2ftimestamp_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor *PROTOBUF_NONNULL *PROTOBUF_NULLABLE
    file_level_service_descriptors_google_2fprotobuf_2ftimestamp_2eproto = nullptr;
const ::uint32_t
    TableStruct_google_2fprotobuf_2ftimestamp_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        PROTOBUF_FIELD_OFFSET(::google::protobuf::Timestamp, _impl_._has_bits_),
        PROTOBUF_FIELD_OFFSET(::google::protobuf::Timestamp, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::google::protobuf::Timestamp, _impl_.seconds_),
        PROTOBUF_FIELD_OFFSET(::google::protobuf::Timestamp, _impl_.nanos_),
        0,
        1,
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, 10, -1, sizeof(::google::protobuf::Timestamp)},
};
static const ::_pb::Message* PROTOBUF_NONNULL const file_default_instances[] = {
    &::google::protobuf::_Timestamp_default_instance_._instance,
};
const char descriptor_table_protodef_google_2fprotobuf_2ftimestamp_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\037google/protobuf/timestamp.proto\022\017googl"
    "e.protobuf\"+\n\tTimestamp\022\017\n\007seconds\030\001 \001(\003"
    "\022\r\n\005nanos\030\002 \001(\005B\205\001\n\023com.google.protobufB"
    "\016TimestampProtoP\001Z2google.golang.org/pro"
    "tobuf/types/known/timestamppb\370\001\001\242\002\003GPB\252\002"
    "\036Google.Protobuf.WellKnownTypesb\006proto3"
};
static ::absl::once_flag descriptor_table_google_2fprotobuf_2ftimestamp_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_google_2fprotobuf_2ftimestamp_2eproto = {
    false,
    false,
    239,
    descriptor_table_protodef_google_2fprotobuf_2ftimestamp_2eproto,
    "google/protobuf/timestamp.proto",
    &descriptor_table_google_2fprotobuf_2ftimestamp_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_google_2fprotobuf_2ftimestamp_2eproto::offsets,
    file_level_enum_descriptors_google_2fprotobuf_2ftimestamp_2eproto,
    file_level_service_descriptors_google_2fprotobuf_2ftimestamp_2eproto,
};
namespace google {
namespace protobuf {
// ===================================================================

class Timestamp::_Internal {
 public:
  using HasBits =
      decltype(std::declval<Timestamp>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
      8 * PROTOBUF_FIELD_OFFSET(Timestamp, _impl_._has_bits_);
};

Timestamp::Timestamp(::google::protobuf::Arena* PROTOBUF_NULLABLE arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, Timestamp_class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:google.protobuf.Timestamp)
}
Timestamp::Timestamp(
    ::google::protobuf::Arena* PROTOBUF_NULLABLE arena, const Timestamp& from)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, Timestamp_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena),
#endif  // PROTOBUF_CUSTOM_VTABLE
      _impl_(from._impl_) {
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
}
PROTOBUF_NDEBUG_INLINE Timestamp::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* PROTOBUF_NULLABLE arena)
      : _cached_size_{0} {}

inline void Timestamp::SharedCtor(::_pb::Arena* PROTOBUF_NULLABLE arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, seconds_),
           0,
           offsetof(Impl_, nanos_) -
               offsetof(Impl_, seconds_) +
               sizeof(Impl_::nanos_));
}
Timestamp::~Timestamp() {
  // @@protoc_insertion_point(destructor:google.protobuf.Timestamp)
  SharedDtor(*this);
}
inline void Timestamp::SharedDtor(MessageLite& self) {
  Timestamp& this_ = static_cast<Timestamp&>(self);
  this_._internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  ABSL_DCHECK(this_.GetArena() == nullptr);
  this_._impl_.~Impl_();
}

inline void* PROTOBUF_NONNULL Timestamp::PlacementNew_(
    const void* PROTOBUF_NONNULL, void* PROTOBUF_NONNULL mem,
    ::google::protobuf::Arena* PROTOBUF_NULLABLE arena) {
  return ::new (mem) Timestamp(arena);
}
constexpr auto Timestamp::InternalNewImpl_() {
  return ::google::protobuf::internal::MessageCreator::ZeroInit(sizeof(Timestamp),
                                            alignof(Timestamp));
}
constexpr auto Timestamp::InternalGenerateClassData_() {
  return ::google::protobuf::internal::ClassDataFull{
      ::google::protobuf::internal::ClassData{
          &_Timestamp_default_instance_._instance,
          &_table_.header,
          nullptr,  // OnDemandRegisterArenaDtor
          nullptr,  // IsInitialized
          &Timestamp::MergeImpl,
          ::google::protobuf::Message::GetNewImpl<Timestamp>(),
#if defined(PROTOBUF_CUSTOM_VTABLE)
          &Timestamp::SharedDtor,
          ::google::protobuf::Message::GetClearImpl<Timestamp>(), &Timestamp::ByteSizeLong,
              &Timestamp::_InternalSerialize,
#endif  // PROTOBUF_CUSTOM_VTABLE
          PROTOBUF_FIELD_OFFSET(Timestamp, _impl_._cached_size_),
          false,
      },
      &Timestamp::kDescriptorMethods,
      &descriptor_table_google_2fprotobuf_2ftimestamp_2eproto,
      nullptr,  // tracker
  };
}

PROTOBUF_CONSTINIT PROTOBUF_EXPORT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 const ::google::protobuf::internal::ClassDataFull
        Timestamp_class_data_ =
            Timestamp::InternalGenerateClassData_();

const ::google::protobuf::internal::ClassData* PROTOBUF_NONNULL Timestamp::GetClassData() const {
  ::google::protobuf::internal::PrefetchToLocalCache(&Timestamp_class_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(Timestamp_class_data_.tc_table);
  return Timestamp_class_data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<1, 2, 0, 0, 2>
Timestamp::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(Timestamp, _impl_._has_bits_),
    0, // no _extensions_
    2, 8,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967292,  // skipmap
    offsetof(decltype(_table_), field_entries),
    2,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    Timestamp_class_data_.base(),
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::google::protobuf::Timestamp>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // int32 nanos = 2;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(Timestamp, _impl_.nanos_), 1>(),
     {16, 1, 0, PROTOBUF_FIELD_OFFSET(Timestamp, _impl_.nanos_)}},
    // int64 seconds = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint64_t, offsetof(Timestamp, _impl_.seconds_), 0>(),
     {8, 0, 0, PROTOBUF_FIELD_OFFSET(Timestamp, _impl_.seconds_)}},
  }}, {{
    65535, 65535
  }}, {{
    // int64 seconds = 1;
    {PROTOBUF_FIELD_OFFSET(Timestamp, _impl_.seconds_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt64)},
    // int32 nanos = 2;
    {PROTOBUF_FIELD_OFFSET(Timestamp, _impl_.nanos_), _Internal::kHasBitsOffset + 1, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt32)},
  }},
  // no aux_entries
  {{
  }},
};
PROTOBUF_NOINLINE void Timestamp::Clear() {
// @@protoc_insertion_point(message_clear_start:google.protobuf.Timestamp)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if ((cached_has_bits & 0x00000003u) != 0) {
    ::memset(&_impl_.seconds_, 0, static_cast<::size_t>(
        reinterpret_cast<char*>(&_impl_.nanos_) -
        reinterpret_cast<char*>(&_impl_.seconds_)) + sizeof(_impl_.nanos_));
  }
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
::uint8_t* PROTOBUF_NONNULL Timestamp::_InternalSerialize(
    const ::google::protobuf::MessageLite& base, ::uint8_t* PROTOBUF_NONNULL target,
    ::google::protobuf::io::EpsCopyOutputStream* PROTOBUF_NONNULL stream) {
  const Timestamp& this_ = static_cast<const Timestamp&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
::uint8_t* PROTOBUF_NONNULL Timestamp::_InternalSerialize(
    ::uint8_t* PROTOBUF_NONNULL target,
    ::google::protobuf::io::EpsCopyOutputStream* PROTOBUF_NONNULL stream) const {
  const Timestamp& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
  // @@protoc_insertion_point(serialize_to_array_start:google.protobuf.Timestamp)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // int64 seconds = 1;
  if ((this_._impl_._has_bits_[0] & 0x00000001u) != 0) {
    if (this_._internal_seconds() != 0) {
      target =
          ::google::protobuf::internal::WireFormatLite::WriteInt64ToArrayWithField<1>(
              stream, this_._internal_seconds(), target);
    }
  }

  // int32 nanos = 2;
  if ((this_._impl_._has_bits_[0] & 0x00000002u) != 0) {
    if (this_._internal_nanos() != 0) {
      target =
          ::google::protobuf::internal::WireFormatLite::WriteInt32ToArrayWithField<2>(
              stream, this_._internal_nanos(), target);
    }
  }

  if (ABSL_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:google.protobuf.Timestamp)
  return target;
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
::size_t Timestamp::ByteSizeLong(const MessageLite& base) {
  const Timestamp& this_ = static_cast<const Timestamp&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
::size_t Timestamp::ByteSizeLong() const {
  const Timestamp& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
  // @@protoc_insertion_point(message_byte_size_start:google.protobuf.Timestamp)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void)cached_has_bits;

  ::_pbi::Prefetch5LinesFrom7Lines(&this_);
  cached_has_bits = this_._impl_._has_bits_[0];
  if ((cached_has_bits & 0x00000003u) != 0) {
    // int64 seconds = 1;
    if ((cached_has_bits & 0x00000001u) != 0) {
      if (this_._internal_seconds() != 0) {
        total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(
            this_._internal_seconds());
      }
    }
    // int32 nanos = 2;
    if ((cached_has_bits & 0x00000002u) != 0) {
      if (this_._internal_nanos() != 0) {
        total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
            this_._internal_nanos());
      }
    }
  }
  return this_.MaybeComputeUnknownFieldsSize(total_size,
                                             &this_._impl_._cached_size_);
}

void Timestamp::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<Timestamp*>(&to_msg);
  auto& from = static_cast<const Timestamp&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:google.protobuf.Timestamp)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._impl_._has_bits_[0];
  if ((cached_has_bits & 0x00000003u) != 0) {
    if ((cached_has_bits & 0x00000001u) != 0) {
      if (from._internal_seconds() != 0) {
        _this->_impl_.seconds_ = from._impl_.seconds_;
      }
    }
    if ((cached_has_bits & 0x00000002u) != 0) {
      if (from._internal_nanos() != 0) {
        _this->_impl_.nanos_ = from._impl_.nanos_;
      }
    }
  }
  _this->_impl_._has_bits_[0] |= cached_has_bits;
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Timestamp::CopyFrom(const Timestamp& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:google.protobuf.Timestamp)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void Timestamp::InternalSwap(Timestamp* PROTOBUF_RESTRICT PROTOBUF_NONNULL other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Timestamp, _impl_.nanos_)
      + sizeof(Timestamp::_impl_.nanos_)
      - PROTOBUF_FIELD_OFFSET(Timestamp, _impl_.seconds_)>(
          reinterpret_cast<char*>(&_impl_.seconds_),
          reinterpret_cast<char*>(&other->_impl_.seconds_));
}

::google::protobuf::Metadata Timestamp::GetMetadata() const {
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
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::std::false_type
    _static_init2_ [[maybe_unused]] =
        (::_pbi::AddDescriptors(&descriptor_table_google_2fprotobuf_2ftimestamp_2eproto),
         ::std::false_type{});
#include "google/protobuf/port_undef.inc"
