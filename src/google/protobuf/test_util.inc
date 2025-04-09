// -*- c++ -*-
// Protocol Buffers - Google's data interchange format
// Copyright 2008 Google Inc.  All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

// Author: kenton@google.com (Kenton Varda)
//  Based on original Protocol Buffers design by
//  Sanjay Ghemawat, Jeff Dean, and others.
//
// This file needs to be included as .inc as it depends on the namespaces
// (unittest and unittest_import) being set up properly. It is also included
// within an enclosing namespace and requires header files to be included
// out of this file.

#include <gtest/gtest.h>
#include "absl/log/absl_check.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/message.h"
#include "google/protobuf/test_util.h"
#include "google/protobuf/unittest_import.pb.h"

namespace google {
namespace protobuf {
namespace TestUtil {

// Set every field in the message to a unique value.
inline void SetAllExtensions(UNITTEST::TestAllExtensions* message);
inline void SetOneofFields(UNITTEST::TestAllExtensions* message);
inline void SetAllFieldsAndExtensions(UNITTEST::TestFieldOrderings* message);
inline void SetPackedExtensions(UNITTEST::TestPackedExtensions* message);

// Use the repeated versions of the set_*() accessors to modify all the
// repeated fields of the message (which should already have been
// initialized with Set*Fields()).  Set*Fields() itself only tests
// the add_*() accessors.
inline void ModifyRepeatedExtensions(UNITTEST::TestAllExtensions* message);

// Check that all fields have the values that they should have after
// Set*Fields() is called.
inline void ExpectAllExtensionsSet(const UNITTEST::TestAllExtensions& message);
inline void ExpectPackedExtensionsSet(
    const UNITTEST::TestPackedExtensions& message);
inline void ExpectUnpackedExtensionsSet(
    const UNITTEST::TestUnpackedExtensions& message);

// Expect that the message is modified as would be expected from
// Modify*Fields().
inline void ExpectRepeatedExtensionsModified(
    const UNITTEST::TestAllExtensions& message);

// Check that all fields have their default values.
inline void ExpectExtensionsClear(const UNITTEST::TestAllExtensions& message);

// Check that all repeated fields have had their last elements removed.
inline void ExpectLastRepeatedExtensionsRemoved(
    const UNITTEST::TestAllExtensions& message);
inline void ExpectLastRepeatedExtensionsRemoved(
    const UNITTEST::TestPackedExtensions& message);
inline void ExpectLastRepeatedsReleased(const UNITTEST::TestAllTypes& message);
inline void ExpectLastRepeatedExtensionsReleased(
    const UNITTEST::TestAllExtensions& message);

// Check that all repeated fields have had their first and last elements
// swapped.
inline void ExpectRepeatedExtensionsSwapped(
    const UNITTEST::TestAllExtensions& message);

}  // namespace TestUtil


// ===================================================================
// Extensions
//
// All this code is exactly equivalent to the above code except that it's
// manipulating extension fields instead of normal ones.

inline void TestUtil::SetAllExtensions(UNITTEST::TestAllExtensions* message) {
  message->SetExtension(UNITTEST::optional_int32_extension, 101);
  message->SetExtension(UNITTEST::optional_int64_extension, 102);
  message->SetExtension(UNITTEST::optional_uint32_extension, 103);
  message->SetExtension(UNITTEST::optional_uint64_extension, 104);
  message->SetExtension(UNITTEST::optional_sint32_extension, 105);
  message->SetExtension(UNITTEST::optional_sint64_extension, 106);
  message->SetExtension(UNITTEST::optional_fixed32_extension, 107);
  message->SetExtension(UNITTEST::optional_fixed64_extension, 108);
  message->SetExtension(UNITTEST::optional_sfixed32_extension, 109);
  message->SetExtension(UNITTEST::optional_sfixed64_extension, 110);
  message->SetExtension(UNITTEST::optional_float_extension, 111);
  message->SetExtension(UNITTEST::optional_double_extension, 112);
  message->SetExtension(UNITTEST::optional_bool_extension, true);
  message->SetExtension(UNITTEST::optional_string_extension, "115");
  message->SetExtension(UNITTEST::optional_bytes_extension, "116");

  message->MutableExtension(UNITTEST::optionalgroup_extension)->set_a(117);
  message->MutableExtension(UNITTEST::optional_nested_message_extension)
      ->set_bb(118);
  message->MutableExtension(UNITTEST::optional_foreign_message_extension)
      ->set_c(119);
  message->MutableExtension(UNITTEST::optional_import_message_extension)
      ->set_d(120);

  message->SetExtension(UNITTEST::optional_nested_enum_extension,
                        UNITTEST::TestAllTypes::BAZ);
  message->SetExtension(UNITTEST::optional_foreign_enum_extension,
                        UNITTEST::FOREIGN_BAZ);
  message->SetExtension(UNITTEST::optional_import_enum_extension,
                        UNITTEST_IMPORT::IMPORT_BAZ);

  message->SetExtension(UNITTEST::optional_string_piece_extension, "124");
  message->SetExtension(UNITTEST::optional_cord_extension, "125");
  message->SetExtension(UNITTEST::optional_bytes_cord_extension,
                        "optional bytes cord");

  message->MutableExtension(UNITTEST::optional_public_import_message_extension)
      ->set_e(126);
  message->MutableExtension(UNITTEST::optional_lazy_message_extension)
      ->set_bb(127);
  message
      ->MutableExtension(UNITTEST::optional_unverified_lazy_message_extension)
      ->set_bb(128);

  // -----------------------------------------------------------------

  message->AddExtension(UNITTEST::repeated_int32_extension, 201);
  message->AddExtension(UNITTEST::repeated_int64_extension, 202);
  message->AddExtension(UNITTEST::repeated_uint32_extension, 203);
  message->AddExtension(UNITTEST::repeated_uint64_extension, 204);
  message->AddExtension(UNITTEST::repeated_sint32_extension, 205);
  message->AddExtension(UNITTEST::repeated_sint64_extension, 206);
  message->AddExtension(UNITTEST::repeated_fixed32_extension, 207);
  message->AddExtension(UNITTEST::repeated_fixed64_extension, 208);
  message->AddExtension(UNITTEST::repeated_sfixed32_extension, 209);
  message->AddExtension(UNITTEST::repeated_sfixed64_extension, 210);
  message->AddExtension(UNITTEST::repeated_float_extension, 211);
  message->AddExtension(UNITTEST::repeated_double_extension, 212);
  message->AddExtension(UNITTEST::repeated_bool_extension, true);
  message->AddExtension(UNITTEST::repeated_string_extension, "215");
  message->AddExtension(UNITTEST::repeated_bytes_extension, "216");

  message->AddExtension(UNITTEST::repeatedgroup_extension)->set_a(217);
  message->AddExtension(UNITTEST::repeated_nested_message_extension)
      ->set_bb(218);
  message->AddExtension(UNITTEST::repeated_foreign_message_extension)
      ->set_c(219);
  message->AddExtension(UNITTEST::repeated_import_message_extension)
      ->set_d(220);
  message->AddExtension(UNITTEST::repeated_lazy_message_extension)->set_bb(227);

  message->AddExtension(UNITTEST::repeated_nested_enum_extension,
                        UNITTEST::TestAllTypes::BAR);
  message->AddExtension(UNITTEST::repeated_foreign_enum_extension,
                        UNITTEST::FOREIGN_BAR);
  message->AddExtension(UNITTEST::repeated_import_enum_extension,
                        UNITTEST_IMPORT::IMPORT_BAR);

  message->AddExtension(UNITTEST::repeated_string_piece_extension, "224");
  message->AddExtension(UNITTEST::repeated_cord_extension, "225");

  // Add a second one of each field.
  message->AddExtension(UNITTEST::repeated_int32_extension, 301);
  message->AddExtension(UNITTEST::repeated_int64_extension, 302);
  message->AddExtension(UNITTEST::repeated_uint32_extension, 303);
  message->AddExtension(UNITTEST::repeated_uint64_extension, 304);
  message->AddExtension(UNITTEST::repeated_sint32_extension, 305);
  message->AddExtension(UNITTEST::repeated_sint64_extension, 306);
  message->AddExtension(UNITTEST::repeated_fixed32_extension, 307);
  message->AddExtension(UNITTEST::repeated_fixed64_extension, 308);
  message->AddExtension(UNITTEST::repeated_sfixed32_extension, 309);
  message->AddExtension(UNITTEST::repeated_sfixed64_extension, 310);
  message->AddExtension(UNITTEST::repeated_float_extension, 311);
  message->AddExtension(UNITTEST::repeated_double_extension, 312);
  message->AddExtension(UNITTEST::repeated_bool_extension, false);
  message->AddExtension(UNITTEST::repeated_string_extension, "315");
  message->AddExtension(UNITTEST::repeated_bytes_extension, "316");

  message->AddExtension(UNITTEST::repeatedgroup_extension)->set_a(317);
  message->AddExtension(UNITTEST::repeated_nested_message_extension)
      ->set_bb(318);
  message->AddExtension(UNITTEST::repeated_foreign_message_extension)
      ->set_c(319);
  message->AddExtension(UNITTEST::repeated_import_message_extension)
      ->set_d(320);
  message->AddExtension(UNITTEST::repeated_lazy_message_extension)->set_bb(327);

  message->AddExtension(UNITTEST::repeated_nested_enum_extension,
                        UNITTEST::TestAllTypes::BAZ);
  message->AddExtension(UNITTEST::repeated_foreign_enum_extension,
                        UNITTEST::FOREIGN_BAZ);
  message->AddExtension(UNITTEST::repeated_import_enum_extension,
                        UNITTEST_IMPORT::IMPORT_BAZ);

  message->AddExtension(UNITTEST::repeated_string_piece_extension, "324");
  message->AddExtension(UNITTEST::repeated_cord_extension, "325");

  // -----------------------------------------------------------------

  message->SetExtension(UNITTEST::default_int32_extension, 401);
  message->SetExtension(UNITTEST::default_int64_extension, 402);
  message->SetExtension(UNITTEST::default_uint32_extension, 403);
  message->SetExtension(UNITTEST::default_uint64_extension, 404);
  message->SetExtension(UNITTEST::default_sint32_extension, 405);
  message->SetExtension(UNITTEST::default_sint64_extension, 406);
  message->SetExtension(UNITTEST::default_fixed32_extension, 407);
  message->SetExtension(UNITTEST::default_fixed64_extension, 408);
  message->SetExtension(UNITTEST::default_sfixed32_extension, 409);
  message->SetExtension(UNITTEST::default_sfixed64_extension, 410);
  message->SetExtension(UNITTEST::default_float_extension, 411);
  message->SetExtension(UNITTEST::default_double_extension, 412);
  message->SetExtension(UNITTEST::default_bool_extension, false);
  message->SetExtension(UNITTEST::default_string_extension, "415");
  message->SetExtension(UNITTEST::default_bytes_extension, "416");

  message->SetExtension(UNITTEST::default_nested_enum_extension,
                        UNITTEST::TestAllTypes::FOO);
  message->SetExtension(UNITTEST::default_foreign_enum_extension,
                        UNITTEST::FOREIGN_FOO);
  message->SetExtension(UNITTEST::default_import_enum_extension,
                        UNITTEST_IMPORT::IMPORT_FOO);

  message->SetExtension(UNITTEST::default_string_piece_extension, "424");
  message->SetExtension(UNITTEST::default_cord_extension, "425");

  SetOneofFields(message);
}

inline void TestUtil::SetOneofFields(UNITTEST::TestAllExtensions* message) {
  message->SetExtension(UNITTEST::oneof_uint32_extension, 601);
  message->MutableExtension(UNITTEST::oneof_nested_message_extension)
      ->set_bb(602);
  message->SetExtension(UNITTEST::oneof_string_extension, "603");
  message->SetExtension(UNITTEST::oneof_bytes_extension, "604");
}

// -------------------------------------------------------------------

inline void TestUtil::SetAllFieldsAndExtensions(
    UNITTEST::TestFieldOrderings* message) {
  ABSL_CHECK(message);
  message->set_my_int(1);
  message->set_my_string("foo");
  message->set_my_float(1.0);
  message->SetExtension(UNITTEST::my_extension_int, 23);
  message->SetExtension(UNITTEST::my_extension_string, "bar");
}

// -------------------------------------------------------------------

inline void TestUtil::ModifyRepeatedExtensions(
    UNITTEST::TestAllExtensions* message) {
  message->SetExtension(UNITTEST::repeated_int32_extension, 1, 501);
  message->SetExtension(UNITTEST::repeated_int64_extension, 1, 502);
  message->SetExtension(UNITTEST::repeated_uint32_extension, 1, 503);
  message->SetExtension(UNITTEST::repeated_uint64_extension, 1, 504);
  message->SetExtension(UNITTEST::repeated_sint32_extension, 1, 505);
  message->SetExtension(UNITTEST::repeated_sint64_extension, 1, 506);
  message->SetExtension(UNITTEST::repeated_fixed32_extension, 1, 507);
  message->SetExtension(UNITTEST::repeated_fixed64_extension, 1, 508);
  message->SetExtension(UNITTEST::repeated_sfixed32_extension, 1, 509);
  message->SetExtension(UNITTEST::repeated_sfixed64_extension, 1, 510);
  message->SetExtension(UNITTEST::repeated_float_extension, 1, 511);
  message->SetExtension(UNITTEST::repeated_double_extension, 1, 512);
  message->SetExtension(UNITTEST::repeated_bool_extension, 1, true);
  message->SetExtension(UNITTEST::repeated_string_extension, 1, "515");
  message->SetExtension(UNITTEST::repeated_bytes_extension, 1, "516");

  message->MutableExtension(UNITTEST::repeatedgroup_extension, 1)->set_a(517);
  message->MutableExtension(UNITTEST::repeated_nested_message_extension, 1)
      ->set_bb(518);
  message->MutableExtension(UNITTEST::repeated_foreign_message_extension, 1)
      ->set_c(519);
  message->MutableExtension(UNITTEST::repeated_import_message_extension, 1)
      ->set_d(520);
  message->MutableExtension(UNITTEST::repeated_lazy_message_extension, 1)
      ->set_bb(527);

  message->SetExtension(UNITTEST::repeated_nested_enum_extension, 1,
                        UNITTEST::TestAllTypes::FOO);
  message->SetExtension(UNITTEST::repeated_foreign_enum_extension, 1,
                        UNITTEST::FOREIGN_FOO);
  message->SetExtension(UNITTEST::repeated_import_enum_extension, 1,
                        UNITTEST_IMPORT::IMPORT_FOO);

  message->SetExtension(UNITTEST::repeated_string_piece_extension, 1, "524");
  message->SetExtension(UNITTEST::repeated_cord_extension, 1, "525");
}

// -------------------------------------------------------------------

inline void TestUtil::ExpectAllExtensionsSet(
    const UNITTEST::TestAllExtensions& message) {
  EXPECT_TRUE(message.HasExtension(UNITTEST::optional_int32_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::optional_int64_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::optional_uint32_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::optional_uint64_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::optional_sint32_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::optional_sint64_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::optional_fixed32_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::optional_fixed64_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::optional_sfixed32_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::optional_sfixed64_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::optional_float_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::optional_double_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::optional_bool_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::optional_string_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::optional_bytes_extension));

  EXPECT_TRUE(message.HasExtension(UNITTEST::optionalgroup_extension));
  EXPECT_TRUE(
      message.HasExtension(UNITTEST::optional_nested_message_extension));
  EXPECT_TRUE(
      message.HasExtension(UNITTEST::optional_foreign_message_extension));
  EXPECT_TRUE(
      message.HasExtension(UNITTEST::optional_import_message_extension));
  EXPECT_TRUE(
      message.HasExtension(UNITTEST::optional_public_import_message_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::optional_lazy_message_extension));
  EXPECT_TRUE(message.HasExtension(
      UNITTEST::optional_unverified_lazy_message_extension));

  EXPECT_TRUE(message.GetExtension(UNITTEST::optionalgroup_extension).has_a());
  EXPECT_TRUE(message.GetExtension(UNITTEST::optional_nested_message_extension)
                  .has_bb());
  EXPECT_TRUE(message.GetExtension(UNITTEST::optional_foreign_message_extension)
                  .has_c());
  EXPECT_TRUE(message.GetExtension(UNITTEST::optional_import_message_extension)
                  .has_d());
  EXPECT_TRUE(
      message.GetExtension(UNITTEST::optional_public_import_message_extension)
          .has_e());
  EXPECT_TRUE(
      message.GetExtension(UNITTEST::optional_lazy_message_extension).has_bb());
  EXPECT_TRUE(
      message.GetExtension(UNITTEST::optional_unverified_lazy_message_extension)
          .has_bb());

  EXPECT_TRUE(message.HasExtension(UNITTEST::optional_nested_enum_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::optional_foreign_enum_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::optional_import_enum_extension));

  EXPECT_TRUE(message.HasExtension(UNITTEST::optional_string_piece_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::optional_cord_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::optional_bytes_cord_extension));

  EXPECT_EQ(101, message.GetExtension(UNITTEST::optional_int32_extension));
  EXPECT_EQ(102, message.GetExtension(UNITTEST::optional_int64_extension));
  EXPECT_EQ(103, message.GetExtension(UNITTEST::optional_uint32_extension));
  EXPECT_EQ(104, message.GetExtension(UNITTEST::optional_uint64_extension));
  EXPECT_EQ(105, message.GetExtension(UNITTEST::optional_sint32_extension));
  EXPECT_EQ(106, message.GetExtension(UNITTEST::optional_sint64_extension));
  EXPECT_EQ(107, message.GetExtension(UNITTEST::optional_fixed32_extension));
  EXPECT_EQ(108, message.GetExtension(UNITTEST::optional_fixed64_extension));
  EXPECT_EQ(109, message.GetExtension(UNITTEST::optional_sfixed32_extension));
  EXPECT_EQ(110, message.GetExtension(UNITTEST::optional_sfixed64_extension));
  EXPECT_EQ(111, message.GetExtension(UNITTEST::optional_float_extension));
  EXPECT_EQ(112, message.GetExtension(UNITTEST::optional_double_extension));
  EXPECT_TRUE(message.GetExtension(UNITTEST::optional_bool_extension));
  EXPECT_EQ("115", message.GetExtension(UNITTEST::optional_string_extension));
  EXPECT_EQ("116", message.GetExtension(UNITTEST::optional_bytes_extension));

  EXPECT_EQ(117, message.GetExtension(UNITTEST::optionalgroup_extension).a());
  EXPECT_EQ(
      118,
      message.GetExtension(UNITTEST::optional_nested_message_extension).bb());
  EXPECT_EQ(
      119,
      message.GetExtension(UNITTEST::optional_foreign_message_extension).c());
  EXPECT_EQ(
      120,
      message.GetExtension(UNITTEST::optional_import_message_extension).d());

  EXPECT_EQ(UNITTEST::TestAllTypes::BAZ,
            message.GetExtension(UNITTEST::optional_nested_enum_extension));
  EXPECT_EQ(UNITTEST::FOREIGN_BAZ,
            message.GetExtension(UNITTEST::optional_foreign_enum_extension));
  EXPECT_EQ(UNITTEST_IMPORT::IMPORT_BAZ,
            message.GetExtension(UNITTEST::optional_import_enum_extension));

  EXPECT_EQ("124",
            message.GetExtension(UNITTEST::optional_string_piece_extension));
  EXPECT_EQ("125", message.GetExtension(UNITTEST::optional_cord_extension));
  EXPECT_EQ("optional bytes cord",
            message.GetExtension(UNITTEST::optional_bytes_cord_extension));
  EXPECT_EQ(
      126,
      message.GetExtension(UNITTEST::optional_public_import_message_extension)
          .e());
  EXPECT_EQ(
      127,
      message.GetExtension(UNITTEST::optional_lazy_message_extension).bb());
  EXPECT_EQ(
      128,
      message.GetExtension(UNITTEST::optional_unverified_lazy_message_extension)
          .bb());

  // -----------------------------------------------------------------

  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_int32_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_int64_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_uint32_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_uint64_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_sint32_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_sint64_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_fixed32_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_fixed64_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_sfixed32_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_sfixed64_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_float_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_double_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_bool_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_string_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_bytes_extension));

  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeatedgroup_extension));
  ASSERT_EQ(2,
            message.ExtensionSize(UNITTEST::repeated_nested_message_extension));
  ASSERT_EQ(
      2, message.ExtensionSize(UNITTEST::repeated_foreign_message_extension));
  ASSERT_EQ(2,
            message.ExtensionSize(UNITTEST::repeated_import_message_extension));
  ASSERT_EQ(2,
            message.ExtensionSize(UNITTEST::repeated_lazy_message_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_nested_enum_extension));
  ASSERT_EQ(2,
            message.ExtensionSize(UNITTEST::repeated_foreign_enum_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_import_enum_extension));

  ASSERT_EQ(2,
            message.ExtensionSize(UNITTEST::repeated_string_piece_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_cord_extension));

  EXPECT_EQ(201, message.GetExtension(UNITTEST::repeated_int32_extension, 0));
  EXPECT_EQ(202, message.GetExtension(UNITTEST::repeated_int64_extension, 0));
  EXPECT_EQ(203, message.GetExtension(UNITTEST::repeated_uint32_extension, 0));
  EXPECT_EQ(204, message.GetExtension(UNITTEST::repeated_uint64_extension, 0));
  EXPECT_EQ(205, message.GetExtension(UNITTEST::repeated_sint32_extension, 0));
  EXPECT_EQ(206, message.GetExtension(UNITTEST::repeated_sint64_extension, 0));
  EXPECT_EQ(207, message.GetExtension(UNITTEST::repeated_fixed32_extension, 0));
  EXPECT_EQ(208, message.GetExtension(UNITTEST::repeated_fixed64_extension, 0));
  EXPECT_EQ(209,
            message.GetExtension(UNITTEST::repeated_sfixed32_extension, 0));
  EXPECT_EQ(210,
            message.GetExtension(UNITTEST::repeated_sfixed64_extension, 0));
  EXPECT_EQ(211, message.GetExtension(UNITTEST::repeated_float_extension, 0));
  EXPECT_EQ(212, message.GetExtension(UNITTEST::repeated_double_extension, 0));
  EXPECT_TRUE(message.GetExtension(UNITTEST::repeated_bool_extension, 0));
  EXPECT_EQ("215",
            message.GetExtension(UNITTEST::repeated_string_extension, 0));
  EXPECT_EQ("216", message.GetExtension(UNITTEST::repeated_bytes_extension, 0));

  EXPECT_EQ(217,
            message.GetExtension(UNITTEST::repeatedgroup_extension, 0).a());
  EXPECT_EQ(218,
            message.GetExtension(UNITTEST::repeated_nested_message_extension, 0)
                .bb());
  EXPECT_EQ(
      219, message.GetExtension(UNITTEST::repeated_foreign_message_extension, 0)
               .c());
  EXPECT_EQ(
      220,
      message.GetExtension(UNITTEST::repeated_import_message_extension, 0).d());
  EXPECT_EQ(
      227,
      message.GetExtension(UNITTEST::repeated_lazy_message_extension, 0).bb());

  EXPECT_EQ(UNITTEST::TestAllTypes::BAR,
            message.GetExtension(UNITTEST::repeated_nested_enum_extension, 0));
  EXPECT_EQ(UNITTEST::FOREIGN_BAR,
            message.GetExtension(UNITTEST::repeated_foreign_enum_extension, 0));
  EXPECT_EQ(UNITTEST_IMPORT::IMPORT_BAR,
            message.GetExtension(UNITTEST::repeated_import_enum_extension, 0));

  EXPECT_EQ("224",
            message.GetExtension(UNITTEST::repeated_string_piece_extension, 0));
  EXPECT_EQ("225", message.GetExtension(UNITTEST::repeated_cord_extension, 0));

  EXPECT_EQ(301, message.GetExtension(UNITTEST::repeated_int32_extension, 1));
  EXPECT_EQ(302, message.GetExtension(UNITTEST::repeated_int64_extension, 1));
  EXPECT_EQ(303, message.GetExtension(UNITTEST::repeated_uint32_extension, 1));
  EXPECT_EQ(304, message.GetExtension(UNITTEST::repeated_uint64_extension, 1));
  EXPECT_EQ(305, message.GetExtension(UNITTEST::repeated_sint32_extension, 1));
  EXPECT_EQ(306, message.GetExtension(UNITTEST::repeated_sint64_extension, 1));
  EXPECT_EQ(307, message.GetExtension(UNITTEST::repeated_fixed32_extension, 1));
  EXPECT_EQ(308, message.GetExtension(UNITTEST::repeated_fixed64_extension, 1));
  EXPECT_EQ(309,
            message.GetExtension(UNITTEST::repeated_sfixed32_extension, 1));
  EXPECT_EQ(310,
            message.GetExtension(UNITTEST::repeated_sfixed64_extension, 1));
  EXPECT_EQ(311, message.GetExtension(UNITTEST::repeated_float_extension, 1));
  EXPECT_EQ(312, message.GetExtension(UNITTEST::repeated_double_extension, 1));
  EXPECT_FALSE(message.GetExtension(UNITTEST::repeated_bool_extension, 1));
  EXPECT_EQ("315",
            message.GetExtension(UNITTEST::repeated_string_extension, 1));
  EXPECT_EQ("316", message.GetExtension(UNITTEST::repeated_bytes_extension, 1));

  EXPECT_EQ(317,
            message.GetExtension(UNITTEST::repeatedgroup_extension, 1).a());
  EXPECT_EQ(318,
            message.GetExtension(UNITTEST::repeated_nested_message_extension, 1)
                .bb());
  EXPECT_EQ(
      319, message.GetExtension(UNITTEST::repeated_foreign_message_extension, 1)
               .c());
  EXPECT_EQ(
      320,
      message.GetExtension(UNITTEST::repeated_import_message_extension, 1).d());
  EXPECT_EQ(
      327,
      message.GetExtension(UNITTEST::repeated_lazy_message_extension, 1).bb());

  EXPECT_EQ(UNITTEST::TestAllTypes::BAZ,
            message.GetExtension(UNITTEST::repeated_nested_enum_extension, 1));
  EXPECT_EQ(UNITTEST::FOREIGN_BAZ,
            message.GetExtension(UNITTEST::repeated_foreign_enum_extension, 1));
  EXPECT_EQ(UNITTEST_IMPORT::IMPORT_BAZ,
            message.GetExtension(UNITTEST::repeated_import_enum_extension, 1));

  EXPECT_EQ("324",
            message.GetExtension(UNITTEST::repeated_string_piece_extension, 1));
  EXPECT_EQ("325", message.GetExtension(UNITTEST::repeated_cord_extension, 1));

  // -----------------------------------------------------------------

  EXPECT_TRUE(message.HasExtension(UNITTEST::default_int32_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::default_int64_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::default_uint32_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::default_uint64_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::default_sint32_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::default_sint64_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::default_fixed32_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::default_fixed64_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::default_sfixed32_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::default_sfixed64_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::default_float_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::default_double_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::default_bool_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::default_string_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::default_bytes_extension));

  EXPECT_TRUE(message.HasExtension(UNITTEST::default_nested_enum_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::default_foreign_enum_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::default_import_enum_extension));

  EXPECT_TRUE(message.HasExtension(UNITTEST::default_string_piece_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::default_cord_extension));

  EXPECT_EQ(401, message.GetExtension(UNITTEST::default_int32_extension));
  EXPECT_EQ(402, message.GetExtension(UNITTEST::default_int64_extension));
  EXPECT_EQ(403, message.GetExtension(UNITTEST::default_uint32_extension));
  EXPECT_EQ(404, message.GetExtension(UNITTEST::default_uint64_extension));
  EXPECT_EQ(405, message.GetExtension(UNITTEST::default_sint32_extension));
  EXPECT_EQ(406, message.GetExtension(UNITTEST::default_sint64_extension));
  EXPECT_EQ(407, message.GetExtension(UNITTEST::default_fixed32_extension));
  EXPECT_EQ(408, message.GetExtension(UNITTEST::default_fixed64_extension));
  EXPECT_EQ(409, message.GetExtension(UNITTEST::default_sfixed32_extension));
  EXPECT_EQ(410, message.GetExtension(UNITTEST::default_sfixed64_extension));
  EXPECT_EQ(411, message.GetExtension(UNITTEST::default_float_extension));
  EXPECT_EQ(412, message.GetExtension(UNITTEST::default_double_extension));
  EXPECT_FALSE(message.GetExtension(UNITTEST::default_bool_extension));
  EXPECT_EQ("415", message.GetExtension(UNITTEST::default_string_extension));
  EXPECT_EQ("416", message.GetExtension(UNITTEST::default_bytes_extension));

  EXPECT_EQ(UNITTEST::TestAllTypes::FOO,
            message.GetExtension(UNITTEST::default_nested_enum_extension));
  EXPECT_EQ(UNITTEST::FOREIGN_FOO,
            message.GetExtension(UNITTEST::default_foreign_enum_extension));
  EXPECT_EQ(UNITTEST_IMPORT::IMPORT_FOO,
            message.GetExtension(UNITTEST::default_import_enum_extension));

  EXPECT_EQ("424",
            message.GetExtension(UNITTEST::default_string_piece_extension));
  EXPECT_EQ("425", message.GetExtension(UNITTEST::default_cord_extension));

  EXPECT_TRUE(message.HasExtension(UNITTEST::oneof_uint32_extension));
  EXPECT_TRUE(
      message.GetExtension(UNITTEST::oneof_nested_message_extension).has_bb());
  EXPECT_TRUE(message.HasExtension(UNITTEST::oneof_string_extension));
  EXPECT_TRUE(message.HasExtension(UNITTEST::oneof_bytes_extension));

  EXPECT_EQ(601, message.GetExtension(UNITTEST::oneof_uint32_extension));
  EXPECT_EQ(
      602, message.GetExtension(UNITTEST::oneof_nested_message_extension).bb());
  EXPECT_EQ("603", message.GetExtension(UNITTEST::oneof_string_extension));
  EXPECT_EQ("604", message.GetExtension(UNITTEST::oneof_bytes_extension));
}

// -------------------------------------------------------------------

inline void TestUtil::ExpectExtensionsClear(
    const UNITTEST::TestAllExtensions& message) {
  std::string serialized;
  ASSERT_TRUE(message.SerializeToString(&serialized));
  EXPECT_EQ("", serialized);
  EXPECT_EQ(0, message.ByteSizeLong());

  // has_blah() should initially be false for all optional fields.
  EXPECT_FALSE(message.HasExtension(UNITTEST::optional_int32_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::optional_int64_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::optional_uint32_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::optional_uint64_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::optional_sint32_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::optional_sint64_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::optional_fixed32_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::optional_fixed64_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::optional_sfixed32_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::optional_sfixed64_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::optional_float_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::optional_double_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::optional_bool_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::optional_string_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::optional_bytes_extension));

  EXPECT_FALSE(message.HasExtension(UNITTEST::optionalgroup_extension));
  EXPECT_FALSE(
      message.HasExtension(UNITTEST::optional_nested_message_extension));
  EXPECT_FALSE(
      message.HasExtension(UNITTEST::optional_foreign_message_extension));
  EXPECT_FALSE(
      message.HasExtension(UNITTEST::optional_import_message_extension));
  EXPECT_FALSE(
      message.HasExtension(UNITTEST::optional_public_import_message_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::optional_lazy_message_extension));
  EXPECT_FALSE(message.HasExtension(
      UNITTEST::optional_unverified_lazy_message_extension));

  EXPECT_FALSE(message.HasExtension(UNITTEST::optional_nested_enum_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::optional_foreign_enum_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::optional_import_enum_extension));

  EXPECT_FALSE(message.HasExtension(UNITTEST::optional_string_piece_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::optional_cord_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::optional_bytes_cord_extension));

  // Optional fields without defaults are set to zero or something like it.
  EXPECT_EQ(0, message.GetExtension(UNITTEST::optional_int32_extension));
  EXPECT_EQ(0, message.GetExtension(UNITTEST::optional_int64_extension));
  EXPECT_EQ(0, message.GetExtension(UNITTEST::optional_uint32_extension));
  EXPECT_EQ(0, message.GetExtension(UNITTEST::optional_uint64_extension));
  EXPECT_EQ(0, message.GetExtension(UNITTEST::optional_sint32_extension));
  EXPECT_EQ(0, message.GetExtension(UNITTEST::optional_sint64_extension));
  EXPECT_EQ(0, message.GetExtension(UNITTEST::optional_fixed32_extension));
  EXPECT_EQ(0, message.GetExtension(UNITTEST::optional_fixed64_extension));
  EXPECT_EQ(0, message.GetExtension(UNITTEST::optional_sfixed32_extension));
  EXPECT_EQ(0, message.GetExtension(UNITTEST::optional_sfixed64_extension));
  EXPECT_EQ(0, message.GetExtension(UNITTEST::optional_float_extension));
  EXPECT_EQ(0, message.GetExtension(UNITTEST::optional_double_extension));
  EXPECT_FALSE(message.GetExtension(UNITTEST::optional_bool_extension));
  EXPECT_EQ("", message.GetExtension(UNITTEST::optional_string_extension));
  EXPECT_EQ("", message.GetExtension(UNITTEST::optional_bytes_extension));

  // Embedded messages should also be clear.
  EXPECT_FALSE(message.GetExtension(UNITTEST::optionalgroup_extension).has_a());
  EXPECT_FALSE(message.GetExtension(UNITTEST::optional_nested_message_extension)
                   .has_bb());
  EXPECT_FALSE(
      message.GetExtension(UNITTEST::optional_foreign_message_extension)
          .has_c());
  EXPECT_FALSE(message.GetExtension(UNITTEST::optional_import_message_extension)
                   .has_d());
  EXPECT_FALSE(
      message.GetExtension(UNITTEST::optional_public_import_message_extension)
          .has_e());
  EXPECT_FALSE(
      message.GetExtension(UNITTEST::optional_lazy_message_extension).has_bb());
  EXPECT_FALSE(
      message.GetExtension(UNITTEST::optional_unverified_lazy_message_extension)
          .has_bb());

  EXPECT_EQ(0, message.GetExtension(UNITTEST::optionalgroup_extension).a());
  EXPECT_EQ(
      0,
      message.GetExtension(UNITTEST::optional_nested_message_extension).bb());
  EXPECT_EQ(
      0,
      message.GetExtension(UNITTEST::optional_foreign_message_extension).c());
  EXPECT_EQ(
      0, message.GetExtension(UNITTEST::optional_import_message_extension).d());
  EXPECT_EQ(
      0,
      message.GetExtension(UNITTEST::optional_public_import_message_extension)
          .e());
  EXPECT_EQ(
      0, message.GetExtension(UNITTEST::optional_lazy_message_extension).bb());
  EXPECT_EQ(
      0,
      message.GetExtension(UNITTEST::optional_unverified_lazy_message_extension)
          .bb());

  // Enums without defaults are set to the first value in the enum.
  EXPECT_EQ(UNITTEST::TestAllTypes::FOO,
            message.GetExtension(UNITTEST::optional_nested_enum_extension));
  EXPECT_EQ(UNITTEST::FOREIGN_FOO,
            message.GetExtension(UNITTEST::optional_foreign_enum_extension));
  EXPECT_EQ(UNITTEST_IMPORT::IMPORT_FOO,
            message.GetExtension(UNITTEST::optional_import_enum_extension));

  EXPECT_EQ("",
            message.GetExtension(UNITTEST::optional_string_piece_extension));
  EXPECT_EQ("", message.GetExtension(UNITTEST::optional_cord_extension));
  EXPECT_EQ("", message.GetExtension(UNITTEST::optional_bytes_cord_extension));

  // Repeated fields are empty.
  EXPECT_EQ(0, message.ExtensionSize(UNITTEST::repeated_int32_extension));
  EXPECT_EQ(0, message.ExtensionSize(UNITTEST::repeated_int64_extension));
  EXPECT_EQ(0, message.ExtensionSize(UNITTEST::repeated_uint32_extension));
  EXPECT_EQ(0, message.ExtensionSize(UNITTEST::repeated_uint64_extension));
  EXPECT_EQ(0, message.ExtensionSize(UNITTEST::repeated_sint32_extension));
  EXPECT_EQ(0, message.ExtensionSize(UNITTEST::repeated_sint64_extension));
  EXPECT_EQ(0, message.ExtensionSize(UNITTEST::repeated_fixed32_extension));
  EXPECT_EQ(0, message.ExtensionSize(UNITTEST::repeated_fixed64_extension));
  EXPECT_EQ(0, message.ExtensionSize(UNITTEST::repeated_sfixed32_extension));
  EXPECT_EQ(0, message.ExtensionSize(UNITTEST::repeated_sfixed64_extension));
  EXPECT_EQ(0, message.ExtensionSize(UNITTEST::repeated_float_extension));
  EXPECT_EQ(0, message.ExtensionSize(UNITTEST::repeated_double_extension));
  EXPECT_EQ(0, message.ExtensionSize(UNITTEST::repeated_bool_extension));
  EXPECT_EQ(0, message.ExtensionSize(UNITTEST::repeated_string_extension));
  EXPECT_EQ(0, message.ExtensionSize(UNITTEST::repeated_bytes_extension));

  EXPECT_EQ(0, message.ExtensionSize(UNITTEST::repeatedgroup_extension));
  EXPECT_EQ(0,
            message.ExtensionSize(UNITTEST::repeated_nested_message_extension));
  EXPECT_EQ(
      0, message.ExtensionSize(UNITTEST::repeated_foreign_message_extension));
  EXPECT_EQ(0,
            message.ExtensionSize(UNITTEST::repeated_import_message_extension));
  EXPECT_EQ(0,
            message.ExtensionSize(UNITTEST::repeated_lazy_message_extension));
  EXPECT_EQ(0, message.ExtensionSize(UNITTEST::repeated_nested_enum_extension));
  EXPECT_EQ(0,
            message.ExtensionSize(UNITTEST::repeated_foreign_enum_extension));
  EXPECT_EQ(0, message.ExtensionSize(UNITTEST::repeated_import_enum_extension));

  EXPECT_EQ(0,
            message.ExtensionSize(UNITTEST::repeated_string_piece_extension));
  EXPECT_EQ(0, message.ExtensionSize(UNITTEST::repeated_cord_extension));

  // has_blah() should also be false for all default fields.
  EXPECT_FALSE(message.HasExtension(UNITTEST::default_int32_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::default_int64_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::default_uint32_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::default_uint64_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::default_sint32_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::default_sint64_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::default_fixed32_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::default_fixed64_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::default_sfixed32_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::default_sfixed64_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::default_float_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::default_double_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::default_bool_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::default_string_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::default_bytes_extension));

  EXPECT_FALSE(message.HasExtension(UNITTEST::default_nested_enum_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::default_foreign_enum_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::default_import_enum_extension));

  EXPECT_FALSE(message.HasExtension(UNITTEST::default_string_piece_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::default_cord_extension));

  // Fields with defaults have their default values (duh).
  EXPECT_EQ(41, message.GetExtension(UNITTEST::default_int32_extension));
  EXPECT_EQ(42, message.GetExtension(UNITTEST::default_int64_extension));
  EXPECT_EQ(43, message.GetExtension(UNITTEST::default_uint32_extension));
  EXPECT_EQ(44, message.GetExtension(UNITTEST::default_uint64_extension));
  EXPECT_EQ(-45, message.GetExtension(UNITTEST::default_sint32_extension));
  EXPECT_EQ(46, message.GetExtension(UNITTEST::default_sint64_extension));
  EXPECT_EQ(47, message.GetExtension(UNITTEST::default_fixed32_extension));
  EXPECT_EQ(48, message.GetExtension(UNITTEST::default_fixed64_extension));
  EXPECT_EQ(49, message.GetExtension(UNITTEST::default_sfixed32_extension));
  EXPECT_EQ(-50, message.GetExtension(UNITTEST::default_sfixed64_extension));
  EXPECT_EQ(51.5, message.GetExtension(UNITTEST::default_float_extension));
  EXPECT_EQ(52e3, message.GetExtension(UNITTEST::default_double_extension));
  EXPECT_TRUE(message.GetExtension(UNITTEST::default_bool_extension));
  EXPECT_EQ("hello", message.GetExtension(UNITTEST::default_string_extension));
  EXPECT_EQ("world", message.GetExtension(UNITTEST::default_bytes_extension));

  EXPECT_EQ(UNITTEST::TestAllTypes::BAR,
            message.GetExtension(UNITTEST::default_nested_enum_extension));
  EXPECT_EQ(UNITTEST::FOREIGN_BAR,
            message.GetExtension(UNITTEST::default_foreign_enum_extension));
  EXPECT_EQ(UNITTEST_IMPORT::IMPORT_BAR,
            message.GetExtension(UNITTEST::default_import_enum_extension));

  EXPECT_EQ("abc",
            message.GetExtension(UNITTEST::default_string_piece_extension));
  EXPECT_EQ("123", message.GetExtension(UNITTEST::default_cord_extension));

  EXPECT_FALSE(message.HasExtension(UNITTEST::oneof_uint32_extension));
  EXPECT_FALSE(
      message.GetExtension(UNITTEST::oneof_nested_message_extension).has_bb());
  EXPECT_FALSE(message.HasExtension(UNITTEST::oneof_string_extension));
  EXPECT_FALSE(message.HasExtension(UNITTEST::oneof_bytes_extension));
}

// -------------------------------------------------------------------

inline void TestUtil::ExpectRepeatedExtensionsModified(
    const UNITTEST::TestAllExtensions& message) {
  // ModifyRepeatedFields only sets the second repeated element of each
  // field.  In addition to verifying this, we also verify that the first
  // element and size were *not* modified.
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_int32_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_int64_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_uint32_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_uint64_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_sint32_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_sint64_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_fixed32_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_fixed64_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_sfixed32_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_sfixed64_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_float_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_double_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_bool_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_string_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_bytes_extension));

  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeatedgroup_extension));
  ASSERT_EQ(2,
            message.ExtensionSize(UNITTEST::repeated_nested_message_extension));
  ASSERT_EQ(
      2, message.ExtensionSize(UNITTEST::repeated_foreign_message_extension));
  ASSERT_EQ(2,
            message.ExtensionSize(UNITTEST::repeated_import_message_extension));
  ASSERT_EQ(2,
            message.ExtensionSize(UNITTEST::repeated_lazy_message_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_nested_enum_extension));
  ASSERT_EQ(2,
            message.ExtensionSize(UNITTEST::repeated_foreign_enum_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_import_enum_extension));

  ASSERT_EQ(2,
            message.ExtensionSize(UNITTEST::repeated_string_piece_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_cord_extension));

  EXPECT_EQ(201, message.GetExtension(UNITTEST::repeated_int32_extension, 0));
  EXPECT_EQ(202, message.GetExtension(UNITTEST::repeated_int64_extension, 0));
  EXPECT_EQ(203, message.GetExtension(UNITTEST::repeated_uint32_extension, 0));
  EXPECT_EQ(204, message.GetExtension(UNITTEST::repeated_uint64_extension, 0));
  EXPECT_EQ(205, message.GetExtension(UNITTEST::repeated_sint32_extension, 0));
  EXPECT_EQ(206, message.GetExtension(UNITTEST::repeated_sint64_extension, 0));
  EXPECT_EQ(207, message.GetExtension(UNITTEST::repeated_fixed32_extension, 0));
  EXPECT_EQ(208, message.GetExtension(UNITTEST::repeated_fixed64_extension, 0));
  EXPECT_EQ(209,
            message.GetExtension(UNITTEST::repeated_sfixed32_extension, 0));
  EXPECT_EQ(210,
            message.GetExtension(UNITTEST::repeated_sfixed64_extension, 0));
  EXPECT_EQ(211, message.GetExtension(UNITTEST::repeated_float_extension, 0));
  EXPECT_EQ(212, message.GetExtension(UNITTEST::repeated_double_extension, 0));
  EXPECT_TRUE(message.GetExtension(UNITTEST::repeated_bool_extension, 0));
  EXPECT_EQ("215",
            message.GetExtension(UNITTEST::repeated_string_extension, 0));
  EXPECT_EQ("216", message.GetExtension(UNITTEST::repeated_bytes_extension, 0));

  EXPECT_EQ(217,
            message.GetExtension(UNITTEST::repeatedgroup_extension, 0).a());
  EXPECT_EQ(218,
            message.GetExtension(UNITTEST::repeated_nested_message_extension, 0)
                .bb());
  EXPECT_EQ(
      219, message.GetExtension(UNITTEST::repeated_foreign_message_extension, 0)
               .c());
  EXPECT_EQ(
      220,
      message.GetExtension(UNITTEST::repeated_import_message_extension, 0).d());
  EXPECT_EQ(
      227,
      message.GetExtension(UNITTEST::repeated_lazy_message_extension, 0).bb());

  EXPECT_EQ(UNITTEST::TestAllTypes::BAR,
            message.GetExtension(UNITTEST::repeated_nested_enum_extension, 0));
  EXPECT_EQ(UNITTEST::FOREIGN_BAR,
            message.GetExtension(UNITTEST::repeated_foreign_enum_extension, 0));
  EXPECT_EQ(UNITTEST_IMPORT::IMPORT_BAR,
            message.GetExtension(UNITTEST::repeated_import_enum_extension, 0));

  EXPECT_EQ("224",
            message.GetExtension(UNITTEST::repeated_string_piece_extension, 0));
  EXPECT_EQ("225", message.GetExtension(UNITTEST::repeated_cord_extension, 0));

  // Actually verify the second (modified) elements now.
  EXPECT_EQ(501, message.GetExtension(UNITTEST::repeated_int32_extension, 1));
  EXPECT_EQ(502, message.GetExtension(UNITTEST::repeated_int64_extension, 1));
  EXPECT_EQ(503, message.GetExtension(UNITTEST::repeated_uint32_extension, 1));
  EXPECT_EQ(504, message.GetExtension(UNITTEST::repeated_uint64_extension, 1));
  EXPECT_EQ(505, message.GetExtension(UNITTEST::repeated_sint32_extension, 1));
  EXPECT_EQ(506, message.GetExtension(UNITTEST::repeated_sint64_extension, 1));
  EXPECT_EQ(507, message.GetExtension(UNITTEST::repeated_fixed32_extension, 1));
  EXPECT_EQ(508, message.GetExtension(UNITTEST::repeated_fixed64_extension, 1));
  EXPECT_EQ(509,
            message.GetExtension(UNITTEST::repeated_sfixed32_extension, 1));
  EXPECT_EQ(510,
            message.GetExtension(UNITTEST::repeated_sfixed64_extension, 1));
  EXPECT_EQ(511, message.GetExtension(UNITTEST::repeated_float_extension, 1));
  EXPECT_EQ(512, message.GetExtension(UNITTEST::repeated_double_extension, 1));
  EXPECT_TRUE(message.GetExtension(UNITTEST::repeated_bool_extension, 1));
  EXPECT_EQ("515",
            message.GetExtension(UNITTEST::repeated_string_extension, 1));
  EXPECT_EQ("516", message.GetExtension(UNITTEST::repeated_bytes_extension, 1));

  EXPECT_EQ(517,
            message.GetExtension(UNITTEST::repeatedgroup_extension, 1).a());
  EXPECT_EQ(518,
            message.GetExtension(UNITTEST::repeated_nested_message_extension, 1)
                .bb());
  EXPECT_EQ(
      519, message.GetExtension(UNITTEST::repeated_foreign_message_extension, 1)
               .c());
  EXPECT_EQ(
      520,
      message.GetExtension(UNITTEST::repeated_import_message_extension, 1).d());
  EXPECT_EQ(
      527,
      message.GetExtension(UNITTEST::repeated_lazy_message_extension, 1).bb());

  EXPECT_EQ(UNITTEST::TestAllTypes::FOO,
            message.GetExtension(UNITTEST::repeated_nested_enum_extension, 1));
  EXPECT_EQ(UNITTEST::FOREIGN_FOO,
            message.GetExtension(UNITTEST::repeated_foreign_enum_extension, 1));
  EXPECT_EQ(UNITTEST_IMPORT::IMPORT_FOO,
            message.GetExtension(UNITTEST::repeated_import_enum_extension, 1));

  EXPECT_EQ("524",
            message.GetExtension(UNITTEST::repeated_string_piece_extension, 1));
  EXPECT_EQ("525", message.GetExtension(UNITTEST::repeated_cord_extension, 1));
}

// -------------------------------------------------------------------

inline void TestUtil::SetPackedExtensions(
    UNITTEST::TestPackedExtensions* message) {
  message->AddExtension(UNITTEST::packed_int32_extension, 601);
  message->AddExtension(UNITTEST::packed_int64_extension, 602);
  message->AddExtension(UNITTEST::packed_uint32_extension, 603);
  message->AddExtension(UNITTEST::packed_uint64_extension, 604);
  message->AddExtension(UNITTEST::packed_sint32_extension, 605);
  message->AddExtension(UNITTEST::packed_sint64_extension, 606);
  message->AddExtension(UNITTEST::packed_fixed32_extension, 607);
  message->AddExtension(UNITTEST::packed_fixed64_extension, 608);
  message->AddExtension(UNITTEST::packed_sfixed32_extension, 609);
  message->AddExtension(UNITTEST::packed_sfixed64_extension, 610);
  message->AddExtension(UNITTEST::packed_float_extension, 611);
  message->AddExtension(UNITTEST::packed_double_extension, 612);
  message->AddExtension(UNITTEST::packed_bool_extension, true);
  message->AddExtension(UNITTEST::packed_enum_extension, UNITTEST::FOREIGN_BAR);
  // add a second one of each field
  message->AddExtension(UNITTEST::packed_int32_extension, 701);
  message->AddExtension(UNITTEST::packed_int64_extension, 702);
  message->AddExtension(UNITTEST::packed_uint32_extension, 703);
  message->AddExtension(UNITTEST::packed_uint64_extension, 704);
  message->AddExtension(UNITTEST::packed_sint32_extension, 705);
  message->AddExtension(UNITTEST::packed_sint64_extension, 706);
  message->AddExtension(UNITTEST::packed_fixed32_extension, 707);
  message->AddExtension(UNITTEST::packed_fixed64_extension, 708);
  message->AddExtension(UNITTEST::packed_sfixed32_extension, 709);
  message->AddExtension(UNITTEST::packed_sfixed64_extension, 710);
  message->AddExtension(UNITTEST::packed_float_extension, 711);
  message->AddExtension(UNITTEST::packed_double_extension, 712);
  message->AddExtension(UNITTEST::packed_bool_extension, false);
  message->AddExtension(UNITTEST::packed_enum_extension, UNITTEST::FOREIGN_BAZ);
}

// -------------------------------------------------------------------

inline void TestUtil::ExpectPackedExtensionsSet(
    const UNITTEST::TestPackedExtensions& message) {
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::packed_int32_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::packed_int64_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::packed_uint32_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::packed_uint64_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::packed_sint32_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::packed_sint64_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::packed_fixed32_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::packed_fixed64_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::packed_sfixed32_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::packed_sfixed64_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::packed_float_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::packed_double_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::packed_bool_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::packed_enum_extension));

  EXPECT_EQ(601, message.GetExtension(UNITTEST::packed_int32_extension, 0));
  EXPECT_EQ(602, message.GetExtension(UNITTEST::packed_int64_extension, 0));
  EXPECT_EQ(603, message.GetExtension(UNITTEST::packed_uint32_extension, 0));
  EXPECT_EQ(604, message.GetExtension(UNITTEST::packed_uint64_extension, 0));
  EXPECT_EQ(605, message.GetExtension(UNITTEST::packed_sint32_extension, 0));
  EXPECT_EQ(606, message.GetExtension(UNITTEST::packed_sint64_extension, 0));
  EXPECT_EQ(607, message.GetExtension(UNITTEST::packed_fixed32_extension, 0));
  EXPECT_EQ(608, message.GetExtension(UNITTEST::packed_fixed64_extension, 0));
  EXPECT_EQ(609, message.GetExtension(UNITTEST::packed_sfixed32_extension, 0));
  EXPECT_EQ(610, message.GetExtension(UNITTEST::packed_sfixed64_extension, 0));
  EXPECT_EQ(611, message.GetExtension(UNITTEST::packed_float_extension, 0));
  EXPECT_EQ(612, message.GetExtension(UNITTEST::packed_double_extension, 0));
  EXPECT_TRUE(message.GetExtension(UNITTEST::packed_bool_extension, 0));
  EXPECT_EQ(UNITTEST::FOREIGN_BAR,
            message.GetExtension(UNITTEST::packed_enum_extension, 0));
  EXPECT_EQ(701, message.GetExtension(UNITTEST::packed_int32_extension, 1));
  EXPECT_EQ(702, message.GetExtension(UNITTEST::packed_int64_extension, 1));
  EXPECT_EQ(703, message.GetExtension(UNITTEST::packed_uint32_extension, 1));
  EXPECT_EQ(704, message.GetExtension(UNITTEST::packed_uint64_extension, 1));
  EXPECT_EQ(705, message.GetExtension(UNITTEST::packed_sint32_extension, 1));
  EXPECT_EQ(706, message.GetExtension(UNITTEST::packed_sint64_extension, 1));
  EXPECT_EQ(707, message.GetExtension(UNITTEST::packed_fixed32_extension, 1));
  EXPECT_EQ(708, message.GetExtension(UNITTEST::packed_fixed64_extension, 1));
  EXPECT_EQ(709, message.GetExtension(UNITTEST::packed_sfixed32_extension, 1));
  EXPECT_EQ(710, message.GetExtension(UNITTEST::packed_sfixed64_extension, 1));
  EXPECT_EQ(711, message.GetExtension(UNITTEST::packed_float_extension, 1));
  EXPECT_EQ(712, message.GetExtension(UNITTEST::packed_double_extension, 1));
  EXPECT_FALSE(message.GetExtension(UNITTEST::packed_bool_extension, 1));
  EXPECT_EQ(UNITTEST::FOREIGN_BAZ,
            message.GetExtension(UNITTEST::packed_enum_extension, 1));
}

// -------------------------------------------------------------------

inline void TestUtil::ExpectUnpackedExtensionsSet(
    const UNITTEST::TestUnpackedExtensions& message) {
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::unpacked_int32_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::unpacked_int64_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::unpacked_uint32_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::unpacked_uint64_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::unpacked_sint32_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::unpacked_sint64_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::unpacked_fixed32_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::unpacked_fixed64_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::unpacked_sfixed32_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::unpacked_sfixed64_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::unpacked_float_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::unpacked_double_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::unpacked_bool_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::unpacked_enum_extension));

  EXPECT_EQ(601, message.GetExtension(UNITTEST::unpacked_int32_extension, 0));
  EXPECT_EQ(602, message.GetExtension(UNITTEST::unpacked_int64_extension, 0));
  EXPECT_EQ(603, message.GetExtension(UNITTEST::unpacked_uint32_extension, 0));
  EXPECT_EQ(604, message.GetExtension(UNITTEST::unpacked_uint64_extension, 0));
  EXPECT_EQ(605, message.GetExtension(UNITTEST::unpacked_sint32_extension, 0));
  EXPECT_EQ(606, message.GetExtension(UNITTEST::unpacked_sint64_extension, 0));
  EXPECT_EQ(607, message.GetExtension(UNITTEST::unpacked_fixed32_extension, 0));
  EXPECT_EQ(608, message.GetExtension(UNITTEST::unpacked_fixed64_extension, 0));
  EXPECT_EQ(609,
            message.GetExtension(UNITTEST::unpacked_sfixed32_extension, 0));
  EXPECT_EQ(610,
            message.GetExtension(UNITTEST::unpacked_sfixed64_extension, 0));
  EXPECT_EQ(611, message.GetExtension(UNITTEST::unpacked_float_extension, 0));
  EXPECT_EQ(612, message.GetExtension(UNITTEST::unpacked_double_extension, 0));
  EXPECT_EQ(true, message.GetExtension(UNITTEST::unpacked_bool_extension, 0));
  EXPECT_EQ(UNITTEST::FOREIGN_BAR,
            message.GetExtension(UNITTEST::unpacked_enum_extension, 0));
  EXPECT_EQ(701, message.GetExtension(UNITTEST::unpacked_int32_extension, 1));
  EXPECT_EQ(702, message.GetExtension(UNITTEST::unpacked_int64_extension, 1));
  EXPECT_EQ(703, message.GetExtension(UNITTEST::unpacked_uint32_extension, 1));
  EXPECT_EQ(704, message.GetExtension(UNITTEST::unpacked_uint64_extension, 1));
  EXPECT_EQ(705, message.GetExtension(UNITTEST::unpacked_sint32_extension, 1));
  EXPECT_EQ(706, message.GetExtension(UNITTEST::unpacked_sint64_extension, 1));
  EXPECT_EQ(707, message.GetExtension(UNITTEST::unpacked_fixed32_extension, 1));
  EXPECT_EQ(708, message.GetExtension(UNITTEST::unpacked_fixed64_extension, 1));
  EXPECT_EQ(709,
            message.GetExtension(UNITTEST::unpacked_sfixed32_extension, 1));
  EXPECT_EQ(710,
            message.GetExtension(UNITTEST::unpacked_sfixed64_extension, 1));
  EXPECT_EQ(711, message.GetExtension(UNITTEST::unpacked_float_extension, 1));
  EXPECT_EQ(712, message.GetExtension(UNITTEST::unpacked_double_extension, 1));
  EXPECT_FALSE(message.GetExtension(UNITTEST::unpacked_bool_extension, 1));
  EXPECT_EQ(UNITTEST::FOREIGN_BAZ,
            message.GetExtension(UNITTEST::unpacked_enum_extension, 1));
}

// -------------------------------------------------------------------

inline void TestUtil::ExpectLastRepeatedExtensionsRemoved(
    const UNITTEST::TestAllExtensions& message) {
  // Test that one element was removed.
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::repeated_int32_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::repeated_int64_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::repeated_uint32_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::repeated_uint64_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::repeated_sint32_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::repeated_sint64_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::repeated_fixed32_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::repeated_fixed64_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::repeated_sfixed32_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::repeated_sfixed64_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::repeated_float_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::repeated_double_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::repeated_bool_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::repeated_string_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::repeated_bytes_extension));

  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::repeatedgroup_extension));
  ASSERT_EQ(1,
            message.ExtensionSize(UNITTEST::repeated_nested_message_extension));
  ASSERT_EQ(
      1, message.ExtensionSize(UNITTEST::repeated_foreign_message_extension));
  ASSERT_EQ(1,
            message.ExtensionSize(UNITTEST::repeated_import_message_extension));
  ASSERT_EQ(1,
            message.ExtensionSize(UNITTEST::repeated_lazy_message_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::repeated_nested_enum_extension));
  ASSERT_EQ(1,
            message.ExtensionSize(UNITTEST::repeated_foreign_enum_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::repeated_import_enum_extension));

  ASSERT_EQ(1,
            message.ExtensionSize(UNITTEST::repeated_string_piece_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::repeated_cord_extension));

  // Test that the remaining element is the correct one.
  EXPECT_EQ(201, message.GetExtension(UNITTEST::repeated_int32_extension, 0));
  EXPECT_EQ(202, message.GetExtension(UNITTEST::repeated_int64_extension, 0));
  EXPECT_EQ(203, message.GetExtension(UNITTEST::repeated_uint32_extension, 0));
  EXPECT_EQ(204, message.GetExtension(UNITTEST::repeated_uint64_extension, 0));
  EXPECT_EQ(205, message.GetExtension(UNITTEST::repeated_sint32_extension, 0));
  EXPECT_EQ(206, message.GetExtension(UNITTEST::repeated_sint64_extension, 0));
  EXPECT_EQ(207, message.GetExtension(UNITTEST::repeated_fixed32_extension, 0));
  EXPECT_EQ(208, message.GetExtension(UNITTEST::repeated_fixed64_extension, 0));
  EXPECT_EQ(209,
            message.GetExtension(UNITTEST::repeated_sfixed32_extension, 0));
  EXPECT_EQ(210,
            message.GetExtension(UNITTEST::repeated_sfixed64_extension, 0));
  EXPECT_EQ(211, message.GetExtension(UNITTEST::repeated_float_extension, 0));
  EXPECT_EQ(212, message.GetExtension(UNITTEST::repeated_double_extension, 0));
  EXPECT_TRUE(message.GetExtension(UNITTEST::repeated_bool_extension, 0));
  EXPECT_EQ("215",
            message.GetExtension(UNITTEST::repeated_string_extension, 0));
  EXPECT_EQ("216", message.GetExtension(UNITTEST::repeated_bytes_extension, 0));

  EXPECT_EQ(217,
            message.GetExtension(UNITTEST::repeatedgroup_extension, 0).a());
  EXPECT_EQ(218,
            message.GetExtension(UNITTEST::repeated_nested_message_extension, 0)
                .bb());
  EXPECT_EQ(
      219, message.GetExtension(UNITTEST::repeated_foreign_message_extension, 0)
               .c());
  EXPECT_EQ(
      220,
      message.GetExtension(UNITTEST::repeated_import_message_extension, 0).d());
  EXPECT_EQ(
      227,
      message.GetExtension(UNITTEST::repeated_lazy_message_extension, 0).bb());

  EXPECT_EQ(UNITTEST::TestAllTypes::BAR,
            message.GetExtension(UNITTEST::repeated_nested_enum_extension, 0));
  EXPECT_EQ(UNITTEST::FOREIGN_BAR,
            message.GetExtension(UNITTEST::repeated_foreign_enum_extension, 0));
  EXPECT_EQ(UNITTEST_IMPORT::IMPORT_BAR,
            message.GetExtension(UNITTEST::repeated_import_enum_extension, 0));

  EXPECT_EQ("224",
            message.GetExtension(UNITTEST::repeated_string_piece_extension, 0));
  EXPECT_EQ("225", message.GetExtension(UNITTEST::repeated_cord_extension, 0));
}

inline void TestUtil::ExpectLastRepeatedExtensionsRemoved(
    const UNITTEST::TestPackedExtensions& message) {
  // Test that one element was removed.
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::packed_int32_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::packed_int64_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::packed_uint32_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::packed_uint64_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::packed_sint32_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::packed_sint64_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::packed_fixed32_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::packed_fixed64_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::packed_sfixed32_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::packed_sfixed64_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::packed_float_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::packed_double_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::packed_bool_extension));
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::packed_enum_extension));

  // Test that the remaining element is the correct one.
  EXPECT_EQ(601, message.GetExtension(UNITTEST::packed_int32_extension, 0));
  EXPECT_EQ(602, message.GetExtension(UNITTEST::packed_int64_extension, 0));
  EXPECT_EQ(603, message.GetExtension(UNITTEST::packed_uint32_extension, 0));
  EXPECT_EQ(604, message.GetExtension(UNITTEST::packed_uint64_extension, 0));
  EXPECT_EQ(605, message.GetExtension(UNITTEST::packed_sint32_extension, 0));
  EXPECT_EQ(606, message.GetExtension(UNITTEST::packed_sint64_extension, 0));
  EXPECT_EQ(607, message.GetExtension(UNITTEST::packed_fixed32_extension, 0));
  EXPECT_EQ(608, message.GetExtension(UNITTEST::packed_fixed64_extension, 0));
  EXPECT_EQ(609, message.GetExtension(UNITTEST::packed_sfixed32_extension, 0));
  EXPECT_EQ(610, message.GetExtension(UNITTEST::packed_sfixed64_extension, 0));
  EXPECT_EQ(611, message.GetExtension(UNITTEST::packed_float_extension, 0));
  EXPECT_EQ(612, message.GetExtension(UNITTEST::packed_double_extension, 0));
  EXPECT_TRUE(message.GetExtension(UNITTEST::packed_bool_extension, 0));
  EXPECT_EQ(UNITTEST::FOREIGN_BAR,
            message.GetExtension(UNITTEST::packed_enum_extension, 0));
}

inline void TestUtil::ExpectLastRepeatedsReleased(
    const UNITTEST::TestAllTypes& message) {
  ASSERT_EQ(1, message.repeatedgroup_size());
  ASSERT_EQ(1, message.repeated_nested_message_size());
  ASSERT_EQ(1, message.repeated_foreign_message_size());
  ASSERT_EQ(1, message.repeated_import_message_size());
  ASSERT_EQ(1, message.repeated_import_message_size());

  EXPECT_EQ(217, message.repeatedgroup(0).a());
  EXPECT_EQ(218, message.repeated_nested_message(0).bb());
  EXPECT_EQ(219, message.repeated_foreign_message(0).c());
  EXPECT_EQ(220, message.repeated_import_message(0).d());
  EXPECT_EQ(220, message.repeated_import_message(0).d());
}

inline void TestUtil::ExpectLastRepeatedExtensionsReleased(
    const UNITTEST::TestAllExtensions& message) {
  ASSERT_EQ(1, message.ExtensionSize(UNITTEST::repeatedgroup_extension));
  ASSERT_EQ(1,
            message.ExtensionSize(UNITTEST::repeated_nested_message_extension));
  ASSERT_EQ(
      1, message.ExtensionSize(UNITTEST::repeated_foreign_message_extension));
  ASSERT_EQ(1,
            message.ExtensionSize(UNITTEST::repeated_import_message_extension));
  ASSERT_EQ(1,
            message.ExtensionSize(UNITTEST::repeated_lazy_message_extension));

  EXPECT_EQ(217,
            message.GetExtension(UNITTEST::repeatedgroup_extension, 0).a());
  EXPECT_EQ(218,
            message.GetExtension(UNITTEST::repeated_nested_message_extension, 0)
                .bb());
  EXPECT_EQ(
      219, message.GetExtension(UNITTEST::repeated_foreign_message_extension, 0)
               .c());
  EXPECT_EQ(
      220,
      message.GetExtension(UNITTEST::repeated_import_message_extension, 0).d());
  EXPECT_EQ(
      227,
      message.GetExtension(UNITTEST::repeated_lazy_message_extension, 0).bb());
}

inline void TestUtil::ExpectRepeatedExtensionsSwapped(
    const UNITTEST::TestAllExtensions& message) {
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_int32_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_int64_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_uint32_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_uint64_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_sint32_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_sint64_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_fixed32_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_fixed64_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_sfixed32_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_sfixed64_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_float_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_double_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_bool_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_string_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_bytes_extension));

  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeatedgroup_extension));
  ASSERT_EQ(2,
            message.ExtensionSize(UNITTEST::repeated_nested_message_extension));
  ASSERT_EQ(
      2, message.ExtensionSize(UNITTEST::repeated_foreign_message_extension));
  ASSERT_EQ(2,
            message.ExtensionSize(UNITTEST::repeated_import_message_extension));
  ASSERT_EQ(2,
            message.ExtensionSize(UNITTEST::repeated_lazy_message_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_nested_enum_extension));
  ASSERT_EQ(2,
            message.ExtensionSize(UNITTEST::repeated_foreign_enum_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_import_enum_extension));

  ASSERT_EQ(2,
            message.ExtensionSize(UNITTEST::repeated_string_piece_extension));
  ASSERT_EQ(2, message.ExtensionSize(UNITTEST::repeated_cord_extension));

  EXPECT_EQ(201, message.GetExtension(UNITTEST::repeated_int32_extension, 1));
  EXPECT_EQ(202, message.GetExtension(UNITTEST::repeated_int64_extension, 1));
  EXPECT_EQ(203, message.GetExtension(UNITTEST::repeated_uint32_extension, 1));
  EXPECT_EQ(204, message.GetExtension(UNITTEST::repeated_uint64_extension, 1));
  EXPECT_EQ(205, message.GetExtension(UNITTEST::repeated_sint32_extension, 1));
  EXPECT_EQ(206, message.GetExtension(UNITTEST::repeated_sint64_extension, 1));
  EXPECT_EQ(207, message.GetExtension(UNITTEST::repeated_fixed32_extension, 1));
  EXPECT_EQ(208, message.GetExtension(UNITTEST::repeated_fixed64_extension, 1));
  EXPECT_EQ(209,
            message.GetExtension(UNITTEST::repeated_sfixed32_extension, 1));
  EXPECT_EQ(210,
            message.GetExtension(UNITTEST::repeated_sfixed64_extension, 1));
  EXPECT_EQ(211, message.GetExtension(UNITTEST::repeated_float_extension, 1));
  EXPECT_EQ(212, message.GetExtension(UNITTEST::repeated_double_extension, 1));
  EXPECT_TRUE(message.GetExtension(UNITTEST::repeated_bool_extension, 1));
  EXPECT_EQ("215",
            message.GetExtension(UNITTEST::repeated_string_extension, 1));
  EXPECT_EQ("216", message.GetExtension(UNITTEST::repeated_bytes_extension, 1));

  EXPECT_EQ(217,
            message.GetExtension(UNITTEST::repeatedgroup_extension, 1).a());
  EXPECT_EQ(218,
            message.GetExtension(UNITTEST::repeated_nested_message_extension, 1)
                .bb());
  EXPECT_EQ(
      219, message.GetExtension(UNITTEST::repeated_foreign_message_extension, 1)
               .c());
  EXPECT_EQ(
      220,
      message.GetExtension(UNITTEST::repeated_import_message_extension, 1).d());
  EXPECT_EQ(
      227,
      message.GetExtension(UNITTEST::repeated_lazy_message_extension, 1).bb());

  EXPECT_EQ(UNITTEST::TestAllTypes::BAR,
            message.GetExtension(UNITTEST::repeated_nested_enum_extension, 1));
  EXPECT_EQ(UNITTEST::FOREIGN_BAR,
            message.GetExtension(UNITTEST::repeated_foreign_enum_extension, 1));
  EXPECT_EQ(UNITTEST_IMPORT::IMPORT_BAR,
            message.GetExtension(UNITTEST::repeated_import_enum_extension, 1));

  EXPECT_EQ("224",
            message.GetExtension(UNITTEST::repeated_string_piece_extension, 1));
  EXPECT_EQ("225", message.GetExtension(UNITTEST::repeated_cord_extension, 1));

  EXPECT_EQ(301, message.GetExtension(UNITTEST::repeated_int32_extension, 0));
  EXPECT_EQ(302, message.GetExtension(UNITTEST::repeated_int64_extension, 0));
  EXPECT_EQ(303, message.GetExtension(UNITTEST::repeated_uint32_extension, 0));
  EXPECT_EQ(304, message.GetExtension(UNITTEST::repeated_uint64_extension, 0));
  EXPECT_EQ(305, message.GetExtension(UNITTEST::repeated_sint32_extension, 0));
  EXPECT_EQ(306, message.GetExtension(UNITTEST::repeated_sint64_extension, 0));
  EXPECT_EQ(307, message.GetExtension(UNITTEST::repeated_fixed32_extension, 0));
  EXPECT_EQ(308, message.GetExtension(UNITTEST::repeated_fixed64_extension, 0));
  EXPECT_EQ(309,
            message.GetExtension(UNITTEST::repeated_sfixed32_extension, 0));
  EXPECT_EQ(310,
            message.GetExtension(UNITTEST::repeated_sfixed64_extension, 0));
  EXPECT_EQ(311, message.GetExtension(UNITTEST::repeated_float_extension, 0));
  EXPECT_EQ(312, message.GetExtension(UNITTEST::repeated_double_extension, 0));
  EXPECT_FALSE(message.GetExtension(UNITTEST::repeated_bool_extension, 0));
  EXPECT_EQ("315",
            message.GetExtension(UNITTEST::repeated_string_extension, 0));
  EXPECT_EQ("316", message.GetExtension(UNITTEST::repeated_bytes_extension, 0));

  EXPECT_EQ(317,
            message.GetExtension(UNITTEST::repeatedgroup_extension, 0).a());
  EXPECT_EQ(318,
            message.GetExtension(UNITTEST::repeated_nested_message_extension, 0)
                .bb());
  EXPECT_EQ(
      319, message.GetExtension(UNITTEST::repeated_foreign_message_extension, 0)
               .c());
  EXPECT_EQ(
      320,
      message.GetExtension(UNITTEST::repeated_import_message_extension, 0).d());
  EXPECT_EQ(
      327,
      message.GetExtension(UNITTEST::repeated_lazy_message_extension, 0).bb());

  EXPECT_EQ(UNITTEST::TestAllTypes::BAZ,
            message.GetExtension(UNITTEST::repeated_nested_enum_extension, 0));
  EXPECT_EQ(UNITTEST::FOREIGN_BAZ,
            message.GetExtension(UNITTEST::repeated_foreign_enum_extension, 0));
  EXPECT_EQ(UNITTEST_IMPORT::IMPORT_BAZ,
            message.GetExtension(UNITTEST::repeated_import_enum_extension, 0));

  EXPECT_EQ("324",
            message.GetExtension(UNITTEST::repeated_string_piece_extension, 0));
  EXPECT_EQ("325", message.GetExtension(UNITTEST::repeated_cord_extension, 0));
}

// ===================================================================

}  // namespace protobuf
}  // namespace google
