begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"textdump.h"
end_include
begin_include
include|#
directive|include
file|<QTextStream>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_namespace
DECL|namespace|QtDiag
namespace|namespace
name|QtDiag
block|{
DECL|struct|EnumLookup
struct|struct
name|EnumLookup
block|{
DECL|member|value
name|int
name|value
decl_stmt|;
DECL|member|description
specifier|const
name|char
modifier|*
name|description
decl_stmt|;
block|}
struct|;
DECL|member|specialCharactersEnumLookup
specifier|static
specifier|const
name|EnumLookup
name|specialCharactersEnumLookup
index|[]
init|=
block|{
block|{
name|QChar
operator|::
name|Null
block|,
literal|"Null"
block|}
block|,
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
block|{
name|QChar
operator|::
name|Tabulation
block|,
literal|"Tabulation"
block|}
block|,
block|{
name|QChar
operator|::
name|LineFeed
block|,
literal|"LineFeed"
block|}
block|,
block|{
name|QChar
operator|::
name|CarriageReturn
block|,
literal|"CarriageReturn"
block|}
block|,
block|{
name|QChar
operator|::
name|Space
block|,
literal|"Space"
block|}
block|,
endif|#
directive|endif
block|{
name|QChar
operator|::
name|Nbsp
block|,
literal|"Nbsp"
block|}
block|,
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
block|{
name|QChar
operator|::
name|SoftHyphen
block|,
literal|"SoftHyphen"
block|}
block|,
endif|#
directive|endif
block|{
name|QChar
operator|::
name|ReplacementCharacter
block|,
literal|"ReplacementCharacter"
block|}
block|,
block|{
name|QChar
operator|::
name|ObjectReplacementCharacter
block|,
literal|"ObjectReplacementCharacter"
block|}
block|,
block|{
name|QChar
operator|::
name|ByteOrderMark
block|,
literal|"ByteOrderMark"
block|}
block|,
block|{
name|QChar
operator|::
name|ByteOrderSwapped
block|,
literal|"ByteOrderSwapped"
block|}
block|,
block|{
name|QChar
operator|::
name|ParagraphSeparator
block|,
literal|"ParagraphSeparator"
block|}
block|,
block|{
name|QChar
operator|::
name|LineSeparator
block|,
literal|"LineSeparator"
block|}
block|,
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
block|{
name|QChar
operator|::
name|LastValidCodePoint
block|,
literal|"LastValidCodePoint"
block|}
endif|#
directive|endif
block|}
decl_stmt|;
DECL|member|categoryEnumLookup
specifier|static
specifier|const
name|EnumLookup
name|categoryEnumLookup
index|[]
init|=
block|{
block|{
name|QChar
operator|::
name|Mark_NonSpacing
block|,
literal|"Mark_NonSpacing"
block|}
block|,
block|{
name|QChar
operator|::
name|Mark_SpacingCombining
block|,
literal|"Mark_SpacingCombining"
block|}
block|,
block|{
name|QChar
operator|::
name|Mark_Enclosing
block|,
literal|"Mark_Enclosing"
block|}
block|,
block|{
name|QChar
operator|::
name|Number_DecimalDigit
block|,
literal|"Number_DecimalDigit"
block|}
block|,
block|{
name|QChar
operator|::
name|Number_Letter
block|,
literal|"Number_Letter"
block|}
block|,
block|{
name|QChar
operator|::
name|Number_Other
block|,
literal|"Number_Other"
block|}
block|,
block|{
name|QChar
operator|::
name|Separator_Space
block|,
literal|"Separator_Space"
block|}
block|,
block|{
name|QChar
operator|::
name|Separator_Line
block|,
literal|"Separator_Line"
block|}
block|,
block|{
name|QChar
operator|::
name|Separator_Paragraph
block|,
literal|"Separator_Paragraph"
block|}
block|,
block|{
name|QChar
operator|::
name|Other_Control
block|,
literal|"Other_Control"
block|}
block|,
block|{
name|QChar
operator|::
name|Other_Format
block|,
literal|"Other_Format"
block|}
block|,
block|{
name|QChar
operator|::
name|Other_Surrogate
block|,
literal|"Other_Surrogate"
block|}
block|,
block|{
name|QChar
operator|::
name|Other_PrivateUse
block|,
literal|"Other_PrivateUse"
block|}
block|,
block|{
name|QChar
operator|::
name|Other_NotAssigned
block|,
literal|"Other_NotAssigned"
block|}
block|,
block|{
name|QChar
operator|::
name|Letter_Uppercase
block|,
literal|"Letter_Uppercase"
block|}
block|,
block|{
name|QChar
operator|::
name|Letter_Lowercase
block|,
literal|"Letter_Lowercase"
block|}
block|,
block|{
name|QChar
operator|::
name|Letter_Titlecase
block|,
literal|"Letter_Titlecase"
block|}
block|,
block|{
name|QChar
operator|::
name|Letter_Modifier
block|,
literal|"Letter_Modifier"
block|}
block|,
block|{
name|QChar
operator|::
name|Letter_Other
block|,
literal|"Letter_Other"
block|}
block|,
block|{
name|QChar
operator|::
name|Punctuation_Connector
block|,
literal|"Punctuation_Connector"
block|}
block|,
block|{
name|QChar
operator|::
name|Punctuation_Dash
block|,
literal|"Punctuation_Dash"
block|}
block|,
block|{
name|QChar
operator|::
name|Punctuation_Open
block|,
literal|"Punctuation_Open"
block|}
block|,
block|{
name|QChar
operator|::
name|Punctuation_Close
block|,
literal|"Punctuation_Close"
block|}
block|,
block|{
name|QChar
operator|::
name|Punctuation_InitialQuote
block|,
literal|"Punctuation_InitialQuote"
block|}
block|,
block|{
name|QChar
operator|::
name|Punctuation_FinalQuote
block|,
literal|"Punctuation_FinalQuote"
block|}
block|,
block|{
name|QChar
operator|::
name|Punctuation_Other
block|,
literal|"Punctuation_Other"
block|}
block|,
block|{
name|QChar
operator|::
name|Symbol_Math
block|,
literal|"Symbol_Math"
block|}
block|,
block|{
name|QChar
operator|::
name|Symbol_Currency
block|,
literal|"Symbol_Currency"
block|}
block|,
block|{
name|QChar
operator|::
name|Symbol_Modifier
block|,
literal|"Symbol_Modifier"
block|}
block|,
block|{
name|QChar
operator|::
name|Symbol_Other
block|,
literal|"Symbol_Other"
block|}
block|, }
decl_stmt|;
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050100
DECL|member|scriptEnumLookup
specifier|static
specifier|const
name|EnumLookup
name|scriptEnumLookup
index|[]
init|=
block|{
block|{
name|QChar
operator|::
name|Script_Unknown
block|,
literal|"Script_Unknown"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Inherited
block|,
literal|"Script_Inherited"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Common
block|,
literal|"Script_Common"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Latin
block|,
literal|"Script_Latin"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Greek
block|,
literal|"Script_Greek"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Cyrillic
block|,
literal|"Script_Cyrillic"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Armenian
block|,
literal|"Script_Armenian"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Hebrew
block|,
literal|"Script_Hebrew"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Arabic
block|,
literal|"Script_Arabic"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Syriac
block|,
literal|"Script_Syriac"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Thaana
block|,
literal|"Script_Thaana"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Devanagari
block|,
literal|"Script_Devanagari"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Bengali
block|,
literal|"Script_Bengali"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Gurmukhi
block|,
literal|"Script_Gurmukhi"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Gujarati
block|,
literal|"Script_Gujarati"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Oriya
block|,
literal|"Script_Oriya"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Tamil
block|,
literal|"Script_Tamil"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Telugu
block|,
literal|"Script_Telugu"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Kannada
block|,
literal|"Script_Kannada"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Malayalam
block|,
literal|"Script_Malayalam"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Sinhala
block|,
literal|"Script_Sinhala"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Thai
block|,
literal|"Script_Thai"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Lao
block|,
literal|"Script_Lao"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Tibetan
block|,
literal|"Script_Tibetan"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Myanmar
block|,
literal|"Script_Myanmar"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Georgian
block|,
literal|"Script_Georgian"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Hangul
block|,
literal|"Script_Hangul"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Ethiopic
block|,
literal|"Script_Ethiopic"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Cherokee
block|,
literal|"Script_Cherokee"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_CanadianAboriginal
block|,
literal|"Script_CanadianAboriginal"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Ogham
block|,
literal|"Script_Ogham"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Runic
block|,
literal|"Script_Runic"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Khmer
block|,
literal|"Script_Khmer"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Mongolian
block|,
literal|"Script_Mongolian"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Hiragana
block|,
literal|"Script_Hiragana"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Katakana
block|,
literal|"Script_Katakana"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Bopomofo
block|,
literal|"Script_Bopomofo"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Han
block|,
literal|"Script_Han"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Yi
block|,
literal|"Script_Yi"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_OldItalic
block|,
literal|"Script_OldItalic"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Gothic
block|,
literal|"Script_Gothic"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Deseret
block|,
literal|"Script_Deseret"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Tagalog
block|,
literal|"Script_Tagalog"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Hanunoo
block|,
literal|"Script_Hanunoo"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Buhid
block|,
literal|"Script_Buhid"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Tagbanwa
block|,
literal|"Script_Tagbanwa"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Coptic
block|,
literal|"Script_Coptic"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Limbu
block|,
literal|"Script_Limbu"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_TaiLe
block|,
literal|"Script_TaiLe"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_LinearB
block|,
literal|"Script_LinearB"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Ugaritic
block|,
literal|"Script_Ugaritic"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Shavian
block|,
literal|"Script_Shavian"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Osmanya
block|,
literal|"Script_Osmanya"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Cypriot
block|,
literal|"Script_Cypriot"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Braille
block|,
literal|"Script_Braille"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Buginese
block|,
literal|"Script_Buginese"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_NewTaiLue
block|,
literal|"Script_NewTaiLue"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Glagolitic
block|,
literal|"Script_Glagolitic"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Tifinagh
block|,
literal|"Script_Tifinagh"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_SylotiNagri
block|,
literal|"Script_SylotiNagri"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_OldPersian
block|,
literal|"Script_OldPersian"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Kharoshthi
block|,
literal|"Script_Kharoshthi"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Balinese
block|,
literal|"Script_Balinese"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Cuneiform
block|,
literal|"Script_Cuneiform"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Phoenician
block|,
literal|"Script_Phoenician"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_PhagsPa
block|,
literal|"Script_PhagsPa"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Nko
block|,
literal|"Script_Nko"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Sundanese
block|,
literal|"Script_Sundanese"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Lepcha
block|,
literal|"Script_Lepcha"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_OlChiki
block|,
literal|"Script_OlChiki"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Vai
block|,
literal|"Script_Vai"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Saurashtra
block|,
literal|"Script_Saurashtra"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_KayahLi
block|,
literal|"Script_KayahLi"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Rejang
block|,
literal|"Script_Rejang"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Lycian
block|,
literal|"Script_Lycian"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Carian
block|,
literal|"Script_Carian"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Lydian
block|,
literal|"Script_Lydian"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Cham
block|,
literal|"Script_Cham"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_TaiTham
block|,
literal|"Script_TaiTham"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_TaiViet
block|,
literal|"Script_TaiViet"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Avestan
block|,
literal|"Script_Avestan"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_EgyptianHieroglyphs
block|,
literal|"Script_EgyptianHieroglyphs"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Samaritan
block|,
literal|"Script_Samaritan"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Lisu
block|,
literal|"Script_Lisu"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Bamum
block|,
literal|"Script_Bamum"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Javanese
block|,
literal|"Script_Javanese"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_MeeteiMayek
block|,
literal|"Script_MeeteiMayek"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_ImperialAramaic
block|,
literal|"Script_ImperialAramaic"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_OldSouthArabian
block|,
literal|"Script_OldSouthArabian"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_InscriptionalParthian
block|,
literal|"Script_InscriptionalParthian"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_InscriptionalPahlavi
block|,
literal|"Script_InscriptionalPahlavi"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_OldTurkic
block|,
literal|"Script_OldTurkic"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Kaithi
block|,
literal|"Script_Kaithi"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Batak
block|,
literal|"Script_Batak"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Brahmi
block|,
literal|"Script_Brahmi"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Mandaic
block|,
literal|"Script_Mandaic"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Chakma
block|,
literal|"Script_Chakma"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_MeroiticCursive
block|,
literal|"Script_MeroiticCursive"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_MeroiticHieroglyphs
block|,
literal|"Script_MeroiticHieroglyphs"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Miao
block|,
literal|"Script_Miao"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Sharada
block|,
literal|"Script_Sharada"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_SoraSompeng
block|,
literal|"Script_SoraSompeng"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Takri
block|,
literal|"Script_Takri"
block|}
block|,
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050500
block|{
name|QChar
operator|::
name|Script_CaucasianAlbanian
block|,
literal|"Script_CaucasianAlbanian"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_BassaVah
block|,
literal|"Script_BassaVah"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Duployan
block|,
literal|"Script_Duployan"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Elbasan
block|,
literal|"Script_Elbasan"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Grantha
block|,
literal|"Script_Grantha"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_PahawhHmong
block|,
literal|"Script_PahawhHmong"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Khojki
block|,
literal|"Script_Khojki"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_LinearA
block|,
literal|"Script_LinearA"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Mahajani
block|,
literal|"Script_Mahajani"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Manichaean
block|,
literal|"Script_Manichaean"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_MendeKikakui
block|,
literal|"Script_MendeKikakui"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Modi
block|,
literal|"Script_Modi"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Mro
block|,
literal|"Script_Mro"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_OldNorthArabian
block|,
literal|"Script_OldNorthArabian"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Nabataean
block|,
literal|"Script_Nabataean"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Palmyrene
block|,
literal|"Script_Palmyrene"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_PauCinHau
block|,
literal|"Script_PauCinHau"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_OldPermic
block|,
literal|"Script_OldPermic"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_PsalterPahlavi
block|,
literal|"Script_PsalterPahlavi"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Siddham
block|,
literal|"Script_Siddham"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Khudawadi
block|,
literal|"Script_Khudawadi"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_Tirhuta
block|,
literal|"Script_Tirhuta"
block|}
block|,
block|{
name|QChar
operator|::
name|Script_WarangCiti
block|,
literal|"Script_WarangCiti"
block|}
block|,
endif|#
directive|endif
comment|// Qt 5.5
block|}
decl_stmt|;
endif|#
directive|endif
comment|// Qt 5.1
DECL|member|directionEnumLookup
specifier|static
specifier|const
name|EnumLookup
name|directionEnumLookup
index|[]
init|=
block|{
block|{
name|QChar
operator|::
name|DirL
block|,
literal|"DirL"
block|}
block|,
block|{
name|QChar
operator|::
name|DirR
block|,
literal|"DirR"
block|}
block|,
block|{
name|QChar
operator|::
name|DirEN
block|,
literal|"DirEN"
block|}
block|,
block|{
name|QChar
operator|::
name|DirES
block|,
literal|"DirES"
block|}
block|,
block|{
name|QChar
operator|::
name|DirET
block|,
literal|"DirET"
block|}
block|,
block|{
name|QChar
operator|::
name|DirAN
block|,
literal|"DirAN"
block|}
block|,
block|{
name|QChar
operator|::
name|DirCS
block|,
literal|"DirCS"
block|}
block|,
block|{
name|QChar
operator|::
name|DirB
block|,
literal|"DirB"
block|}
block|,
block|{
name|QChar
operator|::
name|DirS
block|,
literal|"DirS"
block|}
block|,
block|{
name|QChar
operator|::
name|DirWS
block|,
literal|"DirWS"
block|}
block|,
block|{
name|QChar
operator|::
name|DirON
block|,
literal|"DirON"
block|}
block|,
block|{
name|QChar
operator|::
name|DirLRE
block|,
literal|"DirLRE"
block|}
block|,
block|{
name|QChar
operator|::
name|DirLRO
block|,
literal|"DirLRO"
block|}
block|,
block|{
name|QChar
operator|::
name|DirAL
block|,
literal|"DirAL"
block|}
block|,
block|{
name|QChar
operator|::
name|DirRLE
block|,
literal|"DirRLE"
block|}
block|,
block|{
name|QChar
operator|::
name|DirRLO
block|,
literal|"DirRLO"
block|}
block|,
block|{
name|QChar
operator|::
name|DirPDF
block|,
literal|"DirPDF"
block|}
block|,
block|{
name|QChar
operator|::
name|DirNSM
block|,
literal|"DirNSM"
block|}
block|,
block|{
name|QChar
operator|::
name|DirBN
block|,
literal|"DirBN"
block|}
block|,
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
block|{
name|QChar
operator|::
name|DirLRI
block|,
literal|"DirLRI"
block|}
block|,
block|{
name|QChar
operator|::
name|DirRLI
block|,
literal|"DirRLI"
block|}
block|,
block|{
name|QChar
operator|::
name|DirFSI
block|,
literal|"DirFSI"
block|}
block|,
block|{
name|QChar
operator|::
name|DirPDI
block|,
literal|"DirPDI"
block|}
block|,
endif|#
directive|endif
block|}
decl_stmt|;
DECL|member|decompositionEnumLookup
specifier|static
specifier|const
name|EnumLookup
name|decompositionEnumLookup
index|[]
init|=
block|{
block|{
name|QChar
operator|::
name|NoDecomposition
block|,
literal|"NoDecomposition"
block|}
block|,
block|{
name|QChar
operator|::
name|Canonical
block|,
literal|"Canonical"
block|}
block|,
block|{
name|QChar
operator|::
name|Font
block|,
literal|"Font"
block|}
block|,
block|{
name|QChar
operator|::
name|NoBreak
block|,
literal|"NoBreak"
block|}
block|,
block|{
name|QChar
operator|::
name|Initial
block|,
literal|"Initial"
block|}
block|,
block|{
name|QChar
operator|::
name|Medial
block|,
literal|"Medial"
block|}
block|,
block|{
name|QChar
operator|::
name|Final
block|,
literal|"Final"
block|}
block|,
block|{
name|QChar
operator|::
name|Isolated
block|,
literal|"Isolated"
block|}
block|,
block|{
name|QChar
operator|::
name|Circle
block|,
literal|"Circle"
block|}
block|,
block|{
name|QChar
operator|::
name|Super
block|,
literal|"Super"
block|}
block|,
block|{
name|QChar
operator|::
name|Sub
block|,
literal|"Sub"
block|}
block|,
block|{
name|QChar
operator|::
name|Vertical
block|,
literal|"Vertical"
block|}
block|,
block|{
name|QChar
operator|::
name|Wide
block|,
literal|"Wide"
block|}
block|,
block|{
name|QChar
operator|::
name|Narrow
block|,
literal|"Narrow"
block|}
block|,
block|{
name|QChar
operator|::
name|Small
block|,
literal|"Small"
block|}
block|,
block|{
name|QChar
operator|::
name|Square
block|,
literal|"Square"
block|}
block|,
block|{
name|QChar
operator|::
name|Compat
block|,
literal|"Compat"
block|}
block|,
block|{
name|QChar
operator|::
name|Fraction
block|,
literal|"Fraction"
block|}
block|, }
decl_stmt|;
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
DECL|member|joiningTypeEnumLookup
specifier|static
specifier|const
name|EnumLookup
name|joiningTypeEnumLookup
index|[]
init|=
block|{
block|{
name|QChar
operator|::
name|Joining_None
block|,
literal|"Joining_None"
block|}
block|,
block|{
name|QChar
operator|::
name|Joining_Causing
block|,
literal|"Joining_Causing"
block|}
block|,
block|{
name|QChar
operator|::
name|Joining_Dual
block|,
literal|"Joining_Dual"
block|}
block|,
block|{
name|QChar
operator|::
name|Joining_Right
block|,
literal|"Joining_Right"
block|}
block|,
block|{
name|QChar
operator|::
name|Joining_Left
block|,
literal|"Joining_Left"
block|}
block|,
block|{
name|QChar
operator|::
name|Joining_Transparent
block|,
literal|"Joining_Transparent"
block|}
block|}
decl_stmt|;
endif|#
directive|endif
comment|// Qt 5
DECL|member|combiningClassEnumLookup
specifier|static
specifier|const
name|EnumLookup
name|combiningClassEnumLookup
index|[]
init|=
block|{
block|{
name|QChar
operator|::
name|Combining_BelowLeftAttached
block|,
literal|"Combining_BelowLeftAttached"
block|}
block|,
block|{
name|QChar
operator|::
name|Combining_BelowAttached
block|,
literal|"Combining_BelowAttached"
block|}
block|,
block|{
name|QChar
operator|::
name|Combining_BelowRightAttached
block|,
literal|"Combining_BelowRightAttached"
block|}
block|,
block|{
name|QChar
operator|::
name|Combining_LeftAttached
block|,
literal|"Combining_LeftAttached"
block|}
block|,
block|{
name|QChar
operator|::
name|Combining_RightAttached
block|,
literal|"Combining_RightAttached"
block|}
block|,
block|{
name|QChar
operator|::
name|Combining_AboveLeftAttached
block|,
literal|"Combining_AboveLeftAttached"
block|}
block|,
block|{
name|QChar
operator|::
name|Combining_AboveAttached
block|,
literal|"Combining_AboveAttached"
block|}
block|,
block|{
name|QChar
operator|::
name|Combining_AboveRightAttached
block|,
literal|"Combining_AboveRightAttached"
block|}
block|,
block|{
name|QChar
operator|::
name|Combining_BelowLeft
block|,
literal|"Combining_BelowLeft"
block|}
block|,
block|{
name|QChar
operator|::
name|Combining_Below
block|,
literal|"Combining_Below"
block|}
block|,
block|{
name|QChar
operator|::
name|Combining_BelowRight
block|,
literal|"Combining_BelowRight"
block|}
block|,
block|{
name|QChar
operator|::
name|Combining_Left
block|,
literal|"Combining_Left"
block|}
block|,
block|{
name|QChar
operator|::
name|Combining_Right
block|,
literal|"Combining_Right"
block|}
block|,
block|{
name|QChar
operator|::
name|Combining_AboveLeft
block|,
literal|"Combining_AboveLeft"
block|}
block|,
block|{
name|QChar
operator|::
name|Combining_Above
block|,
literal|"Combining_Above"
block|}
block|,
block|{
name|QChar
operator|::
name|Combining_AboveRight
block|,
literal|"Combining_AboveRight"
block|}
block|,
block|{
name|QChar
operator|::
name|Combining_DoubleBelow
block|,
literal|"Combining_DoubleBelow"
block|}
block|,
block|{
name|QChar
operator|::
name|Combining_DoubleAbove
block|,
literal|"Combining_DoubleAbove"
block|}
block|,
block|{
name|QChar
operator|::
name|Combining_IotaSubscript
block|,
literal|"Combining_IotaSubscript"
block|}
block|, }
decl_stmt|;
DECL|member|unicodeVersionEnumLookup
specifier|static
specifier|const
name|EnumLookup
name|unicodeVersionEnumLookup
index|[]
init|=
block|{
block|{
name|QChar
operator|::
name|Unicode_Unassigned
block|,
literal|"Unicode_Unassigned"
block|}
block|,
block|{
name|QChar
operator|::
name|Unicode_1_1
block|,
literal|"Unicode_1_1"
block|}
block|,
block|{
name|QChar
operator|::
name|Unicode_2_0
block|,
literal|"Unicode_2_0"
block|}
block|,
block|{
name|QChar
operator|::
name|Unicode_2_1_2
block|,
literal|"Unicode_2_1_2"
block|}
block|,
block|{
name|QChar
operator|::
name|Unicode_3_0
block|,
literal|"Unicode_3_0"
block|}
block|,
block|{
name|QChar
operator|::
name|Unicode_3_1
block|,
literal|"Unicode_3_1"
block|}
block|,
block|{
name|QChar
operator|::
name|Unicode_3_2
block|,
literal|"Unicode_3_2"
block|}
block|,
block|{
name|QChar
operator|::
name|Unicode_4_0
block|,
literal|"Unicode_4_0"
block|}
block|,
block|{
name|QChar
operator|::
name|Unicode_4_1
block|,
literal|"Unicode_4_1"
block|}
block|,
block|{
name|QChar
operator|::
name|Unicode_5_0
block|,
literal|"Unicode_5_0"
block|}
block|,
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
block|{
name|QChar
operator|::
name|Unicode_5_1
block|,
literal|"Unicode_5_1"
block|}
block|,
block|{
name|QChar
operator|::
name|Unicode_5_2
block|,
literal|"Unicode_5_2"
block|}
block|,
block|{
name|QChar
operator|::
name|Unicode_6_0
block|,
literal|"Unicode_6_0"
block|}
block|,
block|{
name|QChar
operator|::
name|Unicode_6_1
block|,
literal|"Unicode_6_1"
block|}
block|,
block|{
name|QChar
operator|::
name|Unicode_6_2
block|,
literal|"Unicode_6_2"
block|}
block|,
block|{
name|QChar
operator|::
name|Unicode_6_3
block|,
literal|"Unicode_6_3"
block|}
block|,
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050500
block|{
name|QChar
operator|::
name|Unicode_7_0
block|,
literal|"Unicode_7_0"
block|}
block|,
endif|#
directive|endif
comment|// Qt 5.5
endif|#
directive|endif
comment|// Qt 5
block|}
decl_stmt|;
DECL|function|enumLookup
specifier|static
specifier|const
name|EnumLookup
modifier|*
name|enumLookup
parameter_list|(
name|int
name|v
parameter_list|,
specifier|const
name|EnumLookup
modifier|*
name|array
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
specifier|const
name|EnumLookup
modifier|*
name|end
init|=
name|array
operator|+
name|size
decl_stmt|;
for|for
control|(
specifier|const
name|EnumLookup
modifier|*
name|p
init|=
name|array
init|;
name|p
operator|<
name|end
condition|;
operator|++
name|p
control|)
block|{
if|if
condition|(
name|p
operator|->
name|value
operator|==
name|v
condition|)
return|return
name|p
return|;
block|}
return|return
literal|0
return|;
block|}
DECL|function|enumName
specifier|static
specifier|const
name|char
modifier|*
name|enumName
parameter_list|(
name|int
name|v
parameter_list|,
specifier|const
name|EnumLookup
modifier|*
name|array
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
specifier|const
name|EnumLookup
modifier|*
name|e
init|=
name|enumLookup
argument_list|(
name|v
argument_list|,
name|array
argument_list|,
name|size
argument_list|)
decl_stmt|;
return|return
name|e
condition|?
name|e
operator|->
name|description
else|:
literal|"<unknown>"
return|;
block|}
comment|// Context struct storing the parameters of the last character, only the parameters
comment|// that change will be output.
DECL|struct|FormattingContext
struct|struct
name|FormattingContext
block|{
DECL|function|FormattingContext
name|FormattingContext
parameter_list|()
member_init_list|:
name|category
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|direction
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|joiningType
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|decompositionTag
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|script
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|unicodeVersion
argument_list|(
operator|-
literal|1
argument_list|)
block|{}
DECL|member|category
name|int
name|category
decl_stmt|;
DECL|member|direction
name|int
name|direction
decl_stmt|;
DECL|member|joiningType
name|int
name|joiningType
decl_stmt|;
DECL|member|decompositionTag
name|int
name|decompositionTag
decl_stmt|;
DECL|member|script
name|int
name|script
decl_stmt|;
DECL|member|unicodeVersion
name|int
name|unicodeVersion
decl_stmt|;
block|}
struct|;
DECL|function|formatCharacter
specifier|static
name|void
name|formatCharacter
parameter_list|(
name|QTextStream
modifier|&
name|str
parameter_list|,
specifier|const
name|QChar
modifier|&
name|qc
parameter_list|,
name|FormattingContext
modifier|&
name|context
parameter_list|)
block|{
specifier|const
name|ushort
name|unicode
init|=
name|qc
operator|.
name|unicode
argument_list|()
decl_stmt|;
name|str
operator|<<
literal|"U+"
operator|<<
name|qSetFieldWidth
argument_list|(
literal|4
argument_list|)
operator|<<
name|qSetPadChar
argument_list|(
literal|'0'
argument_list|)
operator|<<
name|uppercasedigits
operator|<<
name|hex
operator|<<
name|unicode
operator|<<
name|dec
operator|<<
name|qSetFieldWidth
argument_list|(
literal|0
argument_list|)
operator|<<
literal|' '
expr_stmt|;
specifier|const
name|EnumLookup
modifier|*
name|specialChar
init|=
name|enumLookup
argument_list|(
name|unicode
argument_list|,
name|specialCharactersEnumLookup
argument_list|,
sizeof|sizeof
argument_list|(
name|specialCharactersEnumLookup
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|EnumLookup
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|specialChar
condition|)
name|str
operator|<<
name|specialChar
operator|->
name|description
expr_stmt|;
else|else
name|str
operator|<<
literal|"'"
operator|<<
name|qc
operator|<<
literal|'\''
expr_stmt|;
specifier|const
name|int
name|category
init|=
name|qc
operator|.
name|category
argument_list|()
decl_stmt|;
if|if
condition|(
name|category
operator|!=
name|context
operator|.
name|category
condition|)
block|{
name|str
operator|<<
literal|" category="
operator|<<
name|enumName
argument_list|(
name|category
argument_list|,
name|categoryEnumLookup
argument_list|,
sizeof|sizeof
argument_list|(
name|categoryEnumLookup
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|EnumLookup
argument_list|)
argument_list|)
expr_stmt|;
name|context
operator|.
name|category
operator|=
name|category
expr_stmt|;
block|}
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050100
specifier|const
name|int
name|script
init|=
name|qc
operator|.
name|script
argument_list|()
decl_stmt|;
if|if
condition|(
name|script
operator|!=
name|context
operator|.
name|script
condition|)
block|{
name|str
operator|<<
literal|" script="
operator|<<
name|enumName
argument_list|(
name|script
argument_list|,
name|scriptEnumLookup
argument_list|,
sizeof|sizeof
argument_list|(
name|scriptEnumLookup
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|EnumLookup
argument_list|)
argument_list|)
operator|<<
literal|'('
operator|<<
name|script
operator|<<
literal|')'
expr_stmt|;
name|context
operator|.
name|script
operator|=
name|script
expr_stmt|;
block|}
endif|#
directive|endif
comment|// Qt 5
specifier|const
name|int
name|direction
init|=
name|qc
operator|.
name|direction
argument_list|()
decl_stmt|;
if|if
condition|(
name|direction
operator|!=
name|context
operator|.
name|direction
condition|)
block|{
name|str
operator|<<
literal|" direction="
operator|<<
name|enumName
argument_list|(
name|direction
argument_list|,
name|directionEnumLookup
argument_list|,
sizeof|sizeof
argument_list|(
name|directionEnumLookup
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|EnumLookup
argument_list|)
argument_list|)
expr_stmt|;
name|context
operator|.
name|direction
operator|=
name|direction
expr_stmt|;
block|}
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
specifier|const
name|int
name|joiningType
init|=
name|qc
operator|.
name|joiningType
argument_list|()
decl_stmt|;
if|if
condition|(
name|joiningType
operator|!=
name|context
operator|.
name|joiningType
condition|)
block|{
name|str
operator|<<
literal|" joiningType="
operator|<<
name|enumName
argument_list|(
name|joiningType
argument_list|,
name|joiningTypeEnumLookup
argument_list|,
sizeof|sizeof
argument_list|(
name|joiningTypeEnumLookup
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|EnumLookup
argument_list|)
argument_list|)
expr_stmt|;
name|context
operator|.
name|joiningType
operator|=
name|joiningType
expr_stmt|;
block|}
endif|#
directive|endif
comment|// Qt 5QWidget
specifier|const
name|int
name|decompositionTag
init|=
name|qc
operator|.
name|decompositionTag
argument_list|()
decl_stmt|;
if|if
condition|(
name|decompositionTag
operator|!=
name|context
operator|.
name|decompositionTag
condition|)
block|{
name|str
operator|<<
literal|" decomposition="
operator|<<
name|enumName
argument_list|(
name|decompositionTag
argument_list|,
name|decompositionEnumLookup
argument_list|,
sizeof|sizeof
argument_list|(
name|decompositionEnumLookup
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|EnumLookup
argument_list|)
argument_list|)
expr_stmt|;
name|context
operator|.
name|decompositionTag
operator|=
name|decompositionTag
expr_stmt|;
block|}
specifier|const
name|int
name|unicodeVersion
init|=
name|qc
operator|.
name|unicodeVersion
argument_list|()
decl_stmt|;
if|if
condition|(
name|unicodeVersion
operator|!=
name|context
operator|.
name|unicodeVersion
condition|)
block|{
name|str
operator|<<
literal|" version="
operator|<<
name|enumName
argument_list|(
name|unicodeVersion
argument_list|,
name|unicodeVersionEnumLookup
argument_list|,
sizeof|sizeof
argument_list|(
name|unicodeVersionEnumLookup
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|EnumLookup
argument_list|)
argument_list|)
expr_stmt|;
name|context
operator|.
name|unicodeVersion
operator|=
name|unicodeVersion
expr_stmt|;
block|}
block|}
DECL|function|dumpText
name|QString
name|dumpText
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|QString
name|result
decl_stmt|;
name|QTextStream
name|str
argument_list|(
operator|&
name|result
argument_list|)
decl_stmt|;
name|FormattingContext
name|context
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|text
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|str
operator|<<
literal|'#'
operator|<<
operator|(
name|i
operator|+
literal|1
operator|)
operator|<<
literal|' '
expr_stmt|;
name|formatCharacter
argument_list|(
name|str
argument_list|,
name|text
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
name|context
argument_list|)
expr_stmt|;
name|str
operator|<<
literal|'\n'
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
DECL|function|dumpTextAsCode
name|QString
name|dumpTextAsCode
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|QString
name|result
decl_stmt|;
name|QTextStream
name|str
argument_list|(
operator|&
name|result
argument_list|)
decl_stmt|;
name|str
operator|<<
literal|"    QString result;\n"
operator|<<
name|hex
operator|<<
name|showbase
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|text
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|str
operator|<<
literal|"    result += QChar("
operator|<<
name|text
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|unicode
argument_list|()
operator|<<
literal|");\n"
expr_stmt|;
name|str
operator|<<
literal|'\n'
expr_stmt|;
return|return
name|result
return|;
block|}
block|}
end_namespace
begin_comment
comment|// namespace QtDiag
end_comment
end_unit
