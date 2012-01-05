begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the utils of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<QtXml>
end_include
begin_class
DECL|class|XKBLayout
class|class
name|XKBLayout
block|{
public|public:
DECL|member|name
name|QString
name|name
decl_stmt|;
DECL|member|description
name|QString
name|description
decl_stmt|;
DECL|member|variants
name|QStringList
name|variants
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|find
name|QDomElement
name|find
parameter_list|(
specifier|const
name|QString
modifier|&
name|tagName
parameter_list|,
specifier|const
name|QDomElement
modifier|&
name|e
parameter_list|)
block|{
name|QDomNodeList
name|children
init|=
name|e
operator|.
name|childNodes
argument_list|()
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
name|children
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QDomNode
modifier|&
name|n
init|=
name|children
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|n
operator|.
name|isElement
argument_list|()
condition|)
block|{
name|QDomElement
name|c
init|=
name|n
operator|.
name|toElement
argument_list|()
decl_stmt|;
if|if
condition|(
name|c
operator|.
name|tagName
argument_list|()
operator|==
name|tagName
condition|)
return|return
name|c
return|;
block|}
block|}
return|return
name|QDomElement
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|parseVariant
name|QString
name|parseVariant
parameter_list|(
specifier|const
name|QDomElement
modifier|&
name|e
parameter_list|)
block|{
name|QDomElement
name|configItem
init|=
name|find
argument_list|(
literal|"configItem"
argument_list|,
name|e
argument_list|)
decl_stmt|;
return|return
name|find
argument_list|(
literal|"name"
argument_list|,
name|configItem
argument_list|)
operator|.
name|text
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|findVariants
name|QStringList
name|findVariants
parameter_list|(
specifier|const
name|QDomElement
modifier|&
name|e
parameter_list|)
block|{
name|QStringList
name|variants
decl_stmt|;
name|QDomNodeList
name|children
init|=
name|e
operator|.
name|childNodes
argument_list|()
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
name|children
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QDomNode
modifier|&
name|n
init|=
name|children
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|n
operator|.
name|isElement
argument_list|()
condition|)
name|variants
operator|+=
name|parseVariant
argument_list|(
name|n
operator|.
name|toElement
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
name|variants
return|;
block|}
end_function
begin_function
DECL|function|parseLayout
name|XKBLayout
name|parseLayout
parameter_list|(
specifier|const
name|QDomElement
modifier|&
name|e
parameter_list|)
block|{
name|QDomElement
name|configItem
init|=
name|find
argument_list|(
literal|"configItem"
argument_list|,
name|e
argument_list|)
decl_stmt|;
name|XKBLayout
name|layout
decl_stmt|;
name|layout
operator|.
name|name
operator|=
name|find
argument_list|(
literal|"name"
argument_list|,
name|configItem
argument_list|)
operator|.
name|text
argument_list|()
expr_stmt|;
name|layout
operator|.
name|description
operator|=
name|find
argument_list|(
literal|"description"
argument_list|,
name|configItem
argument_list|)
operator|.
name|text
argument_list|()
expr_stmt|;
name|QDomElement
name|variantList
init|=
name|find
argument_list|(
literal|"variantList"
argument_list|,
name|e
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|variantList
operator|.
name|isNull
argument_list|()
condition|)
name|layout
operator|.
name|variants
operator|=
name|findVariants
argument_list|(
name|variantList
argument_list|)
expr_stmt|;
return|return
name|layout
return|;
block|}
end_function
begin_function
DECL|function|findLayouts
name|QList
argument_list|<
name|XKBLayout
argument_list|>
name|findLayouts
parameter_list|(
specifier|const
name|QDomElement
modifier|&
name|layoutList
parameter_list|)
block|{
name|QList
argument_list|<
name|XKBLayout
argument_list|>
name|layouts
decl_stmt|;
name|QDomNodeList
name|children
init|=
name|layoutList
operator|.
name|childNodes
argument_list|()
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
name|children
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QDomNode
modifier|&
name|n
init|=
name|children
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|n
operator|.
name|isElement
argument_list|()
condition|)
name|layouts
operator|+=
name|parseLayout
argument_list|(
name|n
operator|.
name|toElement
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
name|layouts
return|;
block|}
end_function
begin_function
DECL|function|mapCountry
name|QString
name|mapCountry
parameter_list|(
specifier|const
name|QString
modifier|&
name|v
parameter_list|)
block|{
specifier|static
name|QMap
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
name|map
decl_stmt|;
specifier|static
name|bool
name|initialized
init|=
literal|false
decl_stmt|;
if|if
condition|(
operator|!
name|initialized
condition|)
block|{
name|map
index|[
literal|"U.S. English"
index|]
operator|=
literal|"UnitedStates"
expr_stmt|;
name|map
index|[
literal|"PC-98xx Series"
index|]
operator|=
literal|"Japan"
expr_stmt|;
name|map
index|[
literal|"Bosnia and Herzegovina"
index|]
operator|=
literal|"BosniaAndHerzegowina"
expr_stmt|;
name|map
index|[
literal|"Czechia"
index|]
operator|=
literal|"CzechRepublic"
expr_stmt|;
name|map
index|[
literal|"Faroe Islands"
index|]
operator|=
literal|"FaroeIslands"
expr_stmt|;
name|map
index|[
literal|"Laos"
index|]
operator|=
literal|"Lao"
expr_stmt|;
name|map
index|[
literal|"Latin American"
index|]
operator|=
literal|"Mexico"
expr_stmt|;
name|map
index|[
literal|"Russia"
index|]
operator|=
literal|"RussianFederation"
expr_stmt|;
name|map
index|[
literal|"Syria"
index|]
operator|=
literal|"SyrianArabRepublic"
expr_stmt|;
name|map
index|[
literal|"Sri Lanka"
index|]
operator|=
literal|"SriLanka"
expr_stmt|;
name|map
index|[
literal|"United Kingdom"
index|]
operator|=
literal|"UnitedKingdom"
expr_stmt|;
name|map
index|[
literal|"Vietnam"
index|]
operator|=
literal|"VietNam"
expr_stmt|;
name|map
index|[
literal|"Macedonian"
index|]
operator|=
literal|"Macedonia"
expr_stmt|;
name|map
index|[
literal|"Serbian"
index|]
operator|=
literal|"SerbiaAndMontenegro"
expr_stmt|;
name|map
index|[
literal|"Turkish "
index|]
operator|=
literal|"Turkey"
expr_stmt|;
name|map
index|[
literal|"Maori"
index|]
operator|=
literal|"NewZealand"
expr_stmt|;
name|map
index|[
literal|"Arabic"
index|]
operator|=
literal|"UnitedArabEmirates"
expr_stmt|;
name|initialized
operator|=
literal|true
expr_stmt|;
block|}
return|return
name|map
operator|.
name|value
argument_list|(
name|v
argument_list|,
name|v
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|mapLanguage
name|QString
name|mapLanguage
parameter_list|(
specifier|const
name|QString
modifier|&
name|v
parameter_list|)
block|{
specifier|static
name|QMap
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
name|map
decl_stmt|;
specifier|static
name|bool
name|initialized
init|=
literal|false
decl_stmt|;
if|if
condition|(
operator|!
name|initialized
condition|)
block|{
name|map
index|[
literal|"us"
index|]
operator|=
literal|"English"
expr_stmt|;
name|map
index|[
literal|"us:intl"
index|]
operator|=
literal|"English"
expr_stmt|;
name|map
index|[
literal|"us:alt-intl"
index|]
operator|=
literal|"English"
expr_stmt|;
name|map
index|[
literal|"us:dvorak"
index|]
operator|=
literal|"English"
expr_stmt|;
name|map
index|[
literal|"us:rus"
index|]
operator|=
literal|"Russian"
expr_stmt|;
name|map
index|[
literal|"ara"
index|]
operator|=
literal|"Arabic"
expr_stmt|;
name|map
index|[
literal|"ara:azerty"
index|]
operator|=
literal|"Arabic"
expr_stmt|;
name|map
index|[
literal|"ara:azerty_digits"
index|]
operator|=
literal|"Arabic"
expr_stmt|;
name|map
index|[
literal|"ara:digits"
index|]
operator|=
literal|"Arabic"
expr_stmt|;
name|map
index|[
literal|"ara:qwerty"
index|]
operator|=
literal|"Arabic"
expr_stmt|;
name|map
index|[
literal|"ara:qwerty_digits"
index|]
operator|=
literal|"Arabic"
expr_stmt|;
name|map
index|[
literal|"al"
index|]
operator|=
literal|"Albanian"
expr_stmt|;
name|map
index|[
literal|"am"
index|]
operator|=
literal|"Armenian"
expr_stmt|;
name|map
index|[
literal|"am:phonetic"
index|]
operator|=
literal|"Armenian"
expr_stmt|;
name|map
index|[
literal|"az"
index|]
operator|=
literal|"Azerbaijani"
expr_stmt|;
name|map
index|[
literal|"az:cyrillic"
index|]
operator|=
literal|"Azerbaijani"
expr_stmt|;
name|map
index|[
literal|"by"
index|]
operator|=
literal|"Byelorussian"
expr_stmt|;
name|map
index|[
literal|"by:winkeys"
index|]
operator|=
literal|"Byelorussian"
expr_stmt|;
name|map
index|[
literal|"be"
index|]
operator|=
literal|"Dutch"
expr_stmt|;
name|map
index|[
literal|"be:iso-alternate"
index|]
operator|=
literal|"Dutch"
expr_stmt|;
name|map
index|[
literal|"be:nodeadkeys"
index|]
operator|=
literal|"Dutch"
expr_stmt|;
name|map
index|[
literal|"be:sundeadkeys"
index|]
operator|=
literal|"Dutch"
expr_stmt|;
name|map
index|[
literal|"bd"
index|]
operator|=
literal|"Bengali"
expr_stmt|;
name|map
index|[
literal|"bd:probhat"
index|]
operator|=
literal|"Bengali"
expr_stmt|;
name|map
index|[
literal|"in"
index|]
operator|=
literal|"Hindi"
expr_stmt|;
name|map
index|[
literal|"in:ben"
index|]
operator|=
literal|"Bengali"
expr_stmt|;
name|map
index|[
literal|"in:ben_probhat"
index|]
operator|=
literal|"Bengali"
expr_stmt|;
name|map
index|[
literal|"in:guj"
index|]
operator|=
literal|"Gujarati"
expr_stmt|;
name|map
index|[
literal|"in:guru"
index|]
operator|=
literal|"Punjabi"
expr_stmt|;
name|map
index|[
literal|"in:kan"
index|]
operator|=
literal|"Kannada"
expr_stmt|;
name|map
index|[
literal|"in:mal"
index|]
operator|=
literal|"Malayalam"
expr_stmt|;
name|map
index|[
literal|"in:ori"
index|]
operator|=
literal|"Oriya"
expr_stmt|;
name|map
index|[
literal|"in:tam_unicode"
index|]
operator|=
literal|"Tamil"
expr_stmt|;
name|map
index|[
literal|"in:tam_TAB"
index|]
operator|=
literal|"Tamil"
expr_stmt|;
name|map
index|[
literal|"in:tam_TSCII"
index|]
operator|=
literal|"Tamil"
expr_stmt|;
name|map
index|[
literal|"in:tam"
index|]
operator|=
literal|"Tamil"
expr_stmt|;
name|map
index|[
literal|"in:tel"
index|]
operator|=
literal|"Telugu"
expr_stmt|;
name|map
index|[
literal|"in:urd"
index|]
operator|=
literal|"Urdu"
expr_stmt|;
name|map
index|[
literal|"ba"
index|]
operator|=
literal|"Bosnian"
expr_stmt|;
name|map
index|[
literal|"br"
index|]
operator|=
literal|"Portuguese"
expr_stmt|;
name|map
index|[
literal|"br:nodeadkeys"
index|]
operator|=
literal|"Portuguese"
expr_stmt|;
name|map
index|[
literal|"bg"
index|]
operator|=
literal|"Bulgarian"
expr_stmt|;
name|map
index|[
literal|"bg:phonetic"
index|]
operator|=
literal|"Bulgarian"
expr_stmt|;
name|map
index|[
literal|"mm"
index|]
operator|=
literal|"Burmese"
expr_stmt|;
name|map
index|[
literal|"ca"
index|]
operator|=
literal|"English"
expr_stmt|;
name|map
index|[
literal|"ca:fr-dvorak"
index|]
operator|=
literal|"French"
expr_stmt|;
name|map
index|[
literal|"ca:fr-legacy"
index|]
operator|=
literal|"French"
expr_stmt|;
name|map
index|[
literal|"ca:multi"
index|]
operator|=
literal|"English"
expr_stmt|;
name|map
index|[
literal|"ca:multi-2gr"
index|]
operator|=
literal|"English"
expr_stmt|;
name|map
index|[
literal|"ca:ike"
index|]
operator|=
literal|"Inuktitut"
expr_stmt|;
name|map
index|[
literal|"hr"
index|]
operator|=
literal|"Croatian"
expr_stmt|;
name|map
index|[
literal|"hr:us"
index|]
operator|=
literal|"Croatian"
expr_stmt|;
name|map
index|[
literal|"cz"
index|]
operator|=
literal|"Czech"
expr_stmt|;
name|map
index|[
literal|"cz:bksl"
index|]
operator|=
literal|"Czech"
expr_stmt|;
name|map
index|[
literal|"cz:qwerty"
index|]
operator|=
literal|"Czech"
expr_stmt|;
name|map
index|[
literal|"cz:qwerty_bksl"
index|]
operator|=
literal|"Czech"
expr_stmt|;
name|map
index|[
literal|"dk"
index|]
operator|=
literal|"Danish"
expr_stmt|;
name|map
index|[
literal|"dk:nodeadkeys"
index|]
operator|=
literal|"Danish"
expr_stmt|;
name|map
index|[
literal|"nl"
index|]
operator|=
literal|"Dutch"
expr_stmt|;
name|map
index|[
literal|"bt"
index|]
operator|=
literal|"Bhutani"
expr_stmt|;
name|map
index|[
literal|"ee"
index|]
operator|=
literal|"Estonian"
expr_stmt|;
name|map
index|[
literal|"ee:nodeadkeys"
index|]
operator|=
literal|"Estonian"
expr_stmt|;
name|map
index|[
literal|"ir"
index|]
operator|=
literal|"Persian"
expr_stmt|;
name|map
index|[
literal|"fo"
index|]
operator|=
literal|"Faroese"
expr_stmt|;
name|map
index|[
literal|"fo:nodeadkeys"
index|]
operator|=
literal|"Faroese"
expr_stmt|;
name|map
index|[
literal|"fi"
index|]
operator|=
literal|"Finnish"
expr_stmt|;
name|map
index|[
literal|"fi:nodeadkeys"
index|]
operator|=
literal|"Finnish"
expr_stmt|;
name|map
index|[
literal|"fi:smi"
index|]
operator|=
literal|"Finnish"
expr_stmt|;
name|map
index|[
literal|"fr"
index|]
operator|=
literal|"French"
expr_stmt|;
name|map
index|[
literal|"fr:nodeadkeys"
index|]
operator|=
literal|"French"
expr_stmt|;
name|map
index|[
literal|"fr:sundeadkeys"
index|]
operator|=
literal|"French"
expr_stmt|;
name|map
index|[
literal|"fr:latin9"
index|]
operator|=
literal|"French"
expr_stmt|;
name|map
index|[
literal|"fr:latin9_nodeadkeys"
index|]
operator|=
literal|"French"
expr_stmt|;
name|map
index|[
literal|"fr:latin9_sundeadkeys"
index|]
operator|=
literal|"French"
expr_stmt|;
name|map
index|[
literal|"fr:dvorak"
index|]
operator|=
literal|"French"
expr_stmt|;
name|map
index|[
literal|"ge"
index|]
operator|=
literal|"Georgian"
expr_stmt|;
name|map
index|[
literal|"ge:ru"
index|]
operator|=
literal|"Russian"
expr_stmt|;
name|map
index|[
literal|"de"
index|]
operator|=
literal|"German"
expr_stmt|;
name|map
index|[
literal|"de:deadacute"
index|]
operator|=
literal|"German"
expr_stmt|;
name|map
index|[
literal|"de:deadgraveacute"
index|]
operator|=
literal|"German"
expr_stmt|;
name|map
index|[
literal|"de:nodeadkeys"
index|]
operator|=
literal|"German"
expr_stmt|;
name|map
index|[
literal|"de:ro"
index|]
operator|=
literal|"Romanian"
expr_stmt|;
name|map
index|[
literal|"de:ro_nodeadkeys"
index|]
operator|=
literal|"Romanian"
expr_stmt|;
name|map
index|[
literal|"de:dvorak"
index|]
operator|=
literal|"German"
expr_stmt|;
name|map
index|[
literal|"gr"
index|]
operator|=
literal|"Greek"
expr_stmt|;
name|map
index|[
literal|"gr:extended"
index|]
operator|=
literal|"Greek"
expr_stmt|;
name|map
index|[
literal|"gr:nodeadkeys"
index|]
operator|=
literal|"Greek"
expr_stmt|;
name|map
index|[
literal|"gr:polytonic"
index|]
operator|=
literal|"Greek"
expr_stmt|;
name|map
index|[
literal|"hu"
index|]
operator|=
literal|"Hungarian"
expr_stmt|;
name|map
index|[
literal|"hu:standard"
index|]
operator|=
literal|"Hungarian"
expr_stmt|;
name|map
index|[
literal|"hu:nodeadkeys"
index|]
operator|=
literal|"Hungarian"
expr_stmt|;
name|map
index|[
literal|"hu:qwerty"
index|]
operator|=
literal|"Hungarian"
expr_stmt|;
name|map
index|[
literal|"hu:101_qwertz_comma_dead"
index|]
operator|=
literal|"Hungarian"
expr_stmt|;
name|map
index|[
literal|"hu:101_qwertz_comma_nodead"
index|]
operator|=
literal|"Hungarian"
expr_stmt|;
name|map
index|[
literal|"hu:101_qwertz_dot_dead"
index|]
operator|=
literal|"Hungarian"
expr_stmt|;
name|map
index|[
literal|"hu:101_qwertz_dot_nodead"
index|]
operator|=
literal|"Hungarian"
expr_stmt|;
name|map
index|[
literal|"hu:101_qwerty_comma_dead"
index|]
operator|=
literal|"Hungarian"
expr_stmt|;
name|map
index|[
literal|"hu:101_qwerty_comma_nodead"
index|]
operator|=
literal|"Hungarian"
expr_stmt|;
name|map
index|[
literal|"hu:101_qwerty_dot_dead"
index|]
operator|=
literal|"Hungarian"
expr_stmt|;
name|map
index|[
literal|"hu:101_qwerty_dot_nodead"
index|]
operator|=
literal|"Hungarian"
expr_stmt|;
name|map
index|[
literal|"hu:102_qwertz_comma_dead"
index|]
operator|=
literal|"Hungarian"
expr_stmt|;
name|map
index|[
literal|"hu:102_qwertz_comma_nodead"
index|]
operator|=
literal|"Hungarian"
expr_stmt|;
name|map
index|[
literal|"hu:102_qwertz_dot_dead"
index|]
operator|=
literal|"Hungarian"
expr_stmt|;
name|map
index|[
literal|"hu:102_qwertz_dot_nodead"
index|]
operator|=
literal|"Hungarian"
expr_stmt|;
name|map
index|[
literal|"hu:102_qwerty_comma_dead"
index|]
operator|=
literal|"Hungarian"
expr_stmt|;
name|map
index|[
literal|"hu:102_qwerty_comma_nodead"
index|]
operator|=
literal|"Hungarian"
expr_stmt|;
name|map
index|[
literal|"hu:102_qwerty_dot_dead"
index|]
operator|=
literal|"Hungarian"
expr_stmt|;
name|map
index|[
literal|"hu:102_qwerty_dot_nodead"
index|]
operator|=
literal|"Hungarian"
expr_stmt|;
name|map
index|[
literal|"is"
index|]
operator|=
literal|"Icelandic"
expr_stmt|;
name|map
index|[
literal|"is:Sundeadkeys"
index|]
operator|=
literal|"Icelandic"
expr_stmt|;
name|map
index|[
literal|"is:nodeadkeys"
index|]
operator|=
literal|"Icelandic"
expr_stmt|;
name|map
index|[
literal|"il"
index|]
operator|=
literal|"Hebrew"
expr_stmt|;
name|map
index|[
literal|"il:lyx"
index|]
operator|=
literal|"Hebrew"
expr_stmt|;
name|map
index|[
literal|"il:si1452"
index|]
operator|=
literal|"Hebrew"
expr_stmt|;
name|map
index|[
literal|"il:phonetic"
index|]
operator|=
literal|"Hebrew"
expr_stmt|;
name|map
index|[
literal|"it"
index|]
operator|=
literal|"Italian"
expr_stmt|;
name|map
index|[
literal|"it:nodeadkeys"
index|]
operator|=
literal|"Italian"
expr_stmt|;
name|map
index|[
literal|"jp"
index|]
operator|=
literal|"Japanese"
expr_stmt|;
name|map
index|[
literal|"kg"
index|]
operator|=
literal|"Kirghiz"
expr_stmt|;
name|map
index|[
literal|"la"
index|]
operator|=
literal|"Laothian"
expr_stmt|;
name|map
index|[
literal|"latam"
index|]
operator|=
literal|"Spanish"
expr_stmt|;
name|map
index|[
literal|"latam:nodeadkeys"
index|]
operator|=
literal|"Spanish"
expr_stmt|;
name|map
index|[
literal|"latam:sundeadkeys"
index|]
operator|=
literal|"Spanish"
expr_stmt|;
name|map
index|[
literal|"lt"
index|]
operator|=
literal|"Lithuanian"
expr_stmt|;
name|map
index|[
literal|"lt:std"
index|]
operator|=
literal|"Lithuanian"
expr_stmt|;
name|map
index|[
literal|"lt:us"
index|]
operator|=
literal|"Lithuanian"
expr_stmt|;
name|map
index|[
literal|"lv"
index|]
operator|=
literal|"Latvian"
expr_stmt|;
name|map
index|[
literal|"lv:apostrophe"
index|]
operator|=
literal|"Latvian"
expr_stmt|;
name|map
index|[
literal|"lv:tilde"
index|]
operator|=
literal|"Latvian"
expr_stmt|;
name|map
index|[
literal|"lv:fkey"
index|]
operator|=
literal|"Latvian"
expr_stmt|;
name|map
index|[
literal|"mao"
index|]
operator|=
literal|"Maori"
expr_stmt|;
name|map
index|[
literal|"mkd"
index|]
operator|=
literal|"Macedonian"
expr_stmt|;
name|map
index|[
literal|"mkd:nodeadkeys"
index|]
operator|=
literal|"Macedonian"
expr_stmt|;
name|map
index|[
literal|"mt"
index|]
operator|=
literal|"Maltese"
expr_stmt|;
name|map
index|[
literal|"mt:us"
index|]
operator|=
literal|"Maltese"
expr_stmt|;
name|map
index|[
literal|"mn"
index|]
operator|=
literal|"Mongolian"
expr_stmt|;
name|map
index|[
literal|"no"
index|]
operator|=
literal|"Norwegian"
expr_stmt|;
name|map
index|[
literal|"no:nodeadkeys"
index|]
operator|=
literal|"Norwegian"
expr_stmt|;
name|map
index|[
literal|"no:dvorak"
index|]
operator|=
literal|"Norwegian"
expr_stmt|;
name|map
index|[
literal|"no:smi"
index|]
operator|=
literal|"Norwegian"
expr_stmt|;
name|map
index|[
literal|"no:smi_nodeadkeys"
index|]
operator|=
literal|"Norwegian"
expr_stmt|;
name|map
index|[
literal|"pl"
index|]
operator|=
literal|"Polish"
expr_stmt|;
name|map
index|[
literal|"pl:qwertz"
index|]
operator|=
literal|"Polish"
expr_stmt|;
name|map
index|[
literal|"pl:dvorak"
index|]
operator|=
literal|"Polish"
expr_stmt|;
name|map
index|[
literal|"pl:dvorak_quotes"
index|]
operator|=
literal|"Polish"
expr_stmt|;
name|map
index|[
literal|"pl:dvorak_altquotes"
index|]
operator|=
literal|"Polish"
expr_stmt|;
name|map
index|[
literal|"pt"
index|]
operator|=
literal|"Portuguese"
expr_stmt|;
name|map
index|[
literal|"pt:nodeadkeys"
index|]
operator|=
literal|"Portuguese"
expr_stmt|;
name|map
index|[
literal|"pt:sundeadkeys"
index|]
operator|=
literal|"Portuguese"
expr_stmt|;
name|map
index|[
literal|"ro"
index|]
operator|=
literal|"Romanian"
expr_stmt|;
name|map
index|[
literal|"ro:us"
index|]
operator|=
literal|"English"
expr_stmt|;
name|map
index|[
literal|"ro:de"
index|]
operator|=
literal|"German"
expr_stmt|;
name|map
index|[
literal|"ru"
index|]
operator|=
literal|"Russian"
expr_stmt|;
name|map
index|[
literal|"ru:phonetic"
index|]
operator|=
literal|"Russian"
expr_stmt|;
name|map
index|[
literal|"ru:typewriter"
index|]
operator|=
literal|"Russian"
expr_stmt|;
name|map
index|[
literal|"ru:winkeys"
index|]
operator|=
literal|"Russian"
expr_stmt|;
name|map
index|[
literal|"srp"
index|]
operator|=
literal|"Serbian"
expr_stmt|;
name|map
index|[
literal|"srp:yz"
index|]
operator|=
literal|"Serbian"
expr_stmt|;
name|map
index|[
literal|"srp:latin"
index|]
operator|=
literal|"Serbian"
expr_stmt|;
name|map
index|[
literal|"srp:latinunicode"
index|]
operator|=
literal|"Serbian"
expr_stmt|;
name|map
index|[
literal|"srp:latinyz"
index|]
operator|=
literal|"Serbian"
expr_stmt|;
name|map
index|[
literal|"srp:latinunicodeyz"
index|]
operator|=
literal|"Serbian"
expr_stmt|;
name|map
index|[
literal|"srp:alternatequotes"
index|]
operator|=
literal|"Serbian"
expr_stmt|;
name|map
index|[
literal|"srp:latinalternatequotes"
index|]
operator|=
literal|"Serbian"
expr_stmt|;
name|map
index|[
literal|"si"
index|]
operator|=
literal|"Slovenian"
expr_stmt|;
name|map
index|[
literal|"sk"
index|]
operator|=
literal|"Slovak"
expr_stmt|;
name|map
index|[
literal|"sk:bksl"
index|]
operator|=
literal|"Slovak"
expr_stmt|;
name|map
index|[
literal|"sk:qwerty"
index|]
operator|=
literal|"Slovak"
expr_stmt|;
name|map
index|[
literal|"sk:qwerty_bksl"
index|]
operator|=
literal|"Slovak"
expr_stmt|;
name|map
index|[
literal|"es"
index|]
operator|=
literal|"Spanish"
expr_stmt|;
name|map
index|[
literal|"es:nodeadkeys"
index|]
operator|=
literal|"Spanish"
expr_stmt|;
name|map
index|[
literal|"es:sundeadkeys"
index|]
operator|=
literal|"Spanish"
expr_stmt|;
name|map
index|[
literal|"es:dvorak"
index|]
operator|=
literal|"Spanish"
expr_stmt|;
name|map
index|[
literal|"se"
index|]
operator|=
literal|"Swedish"
expr_stmt|;
name|map
index|[
literal|"se:nodeadkeys"
index|]
operator|=
literal|"Swedish"
expr_stmt|;
name|map
index|[
literal|"se:dvorak"
index|]
operator|=
literal|"Swedish"
expr_stmt|;
name|map
index|[
literal|"se:rus"
index|]
operator|=
literal|"Russian"
expr_stmt|;
name|map
index|[
literal|"se:rus_nodeadkeys"
index|]
operator|=
literal|"Russian"
expr_stmt|;
name|map
index|[
literal|"se:smi"
index|]
operator|=
literal|"Swedish"
expr_stmt|;
name|map
index|[
literal|"ch"
index|]
operator|=
literal|"German"
expr_stmt|;
name|map
index|[
literal|"ch:de_nodeadkeys"
index|]
operator|=
literal|"German"
expr_stmt|;
name|map
index|[
literal|"ch:de_sundeadkeys"
index|]
operator|=
literal|"German"
expr_stmt|;
name|map
index|[
literal|"ch:fr"
index|]
operator|=
literal|"French"
expr_stmt|;
name|map
index|[
literal|"ch:fr_nodeadkeys"
index|]
operator|=
literal|"French"
expr_stmt|;
name|map
index|[
literal|"ch:fr_sundeadkeys"
index|]
operator|=
literal|"French"
expr_stmt|;
name|map
index|[
literal|"sy"
index|]
operator|=
literal|"Arabic"
expr_stmt|;
name|map
index|[
literal|"sy:syc"
index|]
operator|=
literal|"Arabic"
expr_stmt|;
name|map
index|[
literal|"sy:syc_phonetic"
index|]
operator|=
literal|"Arabic"
expr_stmt|;
name|map
index|[
literal|"tj"
index|]
operator|=
literal|"Tajik"
expr_stmt|;
name|map
index|[
literal|"lk"
index|]
operator|=
literal|"Singhalese"
expr_stmt|;
name|map
index|[
literal|"lk:tam_unicode"
index|]
operator|=
literal|"Tamil"
expr_stmt|;
name|map
index|[
literal|"lk:tam_TAB"
index|]
operator|=
literal|"Tamil"
expr_stmt|;
name|map
index|[
literal|"lk:tam_TSCII"
index|]
operator|=
literal|"Tamil"
expr_stmt|;
name|map
index|[
literal|"lk:sin_phonetic"
index|]
operator|=
literal|"Singhalese"
expr_stmt|;
name|map
index|[
literal|"th"
index|]
operator|=
literal|"Thai"
expr_stmt|;
name|map
index|[
literal|"th:tis"
index|]
operator|=
literal|"Thai"
expr_stmt|;
name|map
index|[
literal|"th:pat"
index|]
operator|=
literal|"Thai"
expr_stmt|;
name|map
index|[
literal|"tr"
index|]
operator|=
literal|"Turkish"
expr_stmt|;
name|map
index|[
literal|"tr:f"
index|]
operator|=
literal|"Turkish"
expr_stmt|;
name|map
index|[
literal|"tr:alt"
index|]
operator|=
literal|"Turkish"
expr_stmt|;
name|map
index|[
literal|"ua"
index|]
operator|=
literal|"Ukrainian"
expr_stmt|;
name|map
index|[
literal|"ua:phonetic"
index|]
operator|=
literal|"Ukrainian"
expr_stmt|;
name|map
index|[
literal|"ua:typewriter"
index|]
operator|=
literal|"Ukrainian"
expr_stmt|;
name|map
index|[
literal|"ua:winkeys"
index|]
operator|=
literal|"Ukrainian"
expr_stmt|;
name|map
index|[
literal|"ua:rstu"
index|]
operator|=
literal|"Ukrainian"
expr_stmt|;
name|map
index|[
literal|"ua:rstu_ru"
index|]
operator|=
literal|"Ukrainian"
expr_stmt|;
name|map
index|[
literal|"gb"
index|]
operator|=
literal|"English"
expr_stmt|;
name|map
index|[
literal|"gb:intl"
index|]
operator|=
literal|"English"
expr_stmt|;
name|map
index|[
literal|"gb:dvorak"
index|]
operator|=
literal|"English"
expr_stmt|;
name|map
index|[
literal|"uz"
index|]
operator|=
literal|"Uzbek"
expr_stmt|;
name|map
index|[
literal|"vn"
index|]
operator|=
literal|"Vietnamese"
expr_stmt|;
name|map
index|[
literal|"nec_vndr/jp"
index|]
operator|=
literal|"Japanese"
expr_stmt|;
name|map
index|[
literal|"ie"
index|]
operator|=
literal|"Irish"
expr_stmt|;
name|map
index|[
literal|"ie:CloGaelach"
index|]
operator|=
literal|"Gaelic"
expr_stmt|;
name|map
index|[
literal|"ie:UnicodeExpert"
index|]
operator|=
literal|"Irish"
expr_stmt|;
name|map
index|[
literal|"ie:ogam"
index|]
operator|=
literal|"Gaelic"
expr_stmt|;
name|map
index|[
literal|"ie:ogam_is434"
index|]
operator|=
literal|"Gaelic"
expr_stmt|;
name|map
index|[
literal|"pk"
index|]
operator|=
literal|"Urdu"
expr_stmt|;
name|initialized
operator|=
literal|true
expr_stmt|;
block|}
return|return
name|map
operator|.
name|value
argument_list|(
name|v
argument_list|,
name|v
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|mapDirection
name|QString
name|mapDirection
parameter_list|(
specifier|const
name|QString
modifier|&
name|v
parameter_list|)
block|{
specifier|static
name|QMap
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
name|map
decl_stmt|;
specifier|static
name|bool
name|initialized
init|=
literal|false
decl_stmt|;
if|if
condition|(
operator|!
name|initialized
condition|)
block|{
comment|// 1. xkbdata-X11R7.0-1.0.1/symbols% grep -l '\([Hh]ebrew\|[Aa]rabic\)' **/*
name|map
index|[
literal|"Arabic"
index|]
operator|=
literal|"Qt::RightToLeft"
expr_stmt|;
name|map
index|[
literal|"Persian"
index|]
operator|=
literal|"Qt::RightToLeft"
expr_stmt|;
name|map
index|[
literal|"Urdu"
index|]
operator|=
literal|"Qt::RightToLeft"
expr_stmt|;
name|initialized
operator|=
literal|true
expr_stmt|;
block|}
return|return
name|map
operator|.
name|value
argument_list|(
name|v
argument_list|,
literal|"Qt::LeftToRight"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
if|if
condition|(
name|argc
operator|!=
literal|2
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"usage: %s<xml input file>\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QFile
name|file
decl_stmt|;
name|file
operator|.
name|setFileName
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"cannot open %s: %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|file
operator|.
name|fileName
argument_list|()
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|file
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|QDomDocument
name|dom
decl_stmt|;
name|dom
operator|.
name|setContent
argument_list|(
operator|&
name|file
argument_list|)
expr_stmt|;
if|if
condition|(
name|dom
operator|.
name|documentElement
argument_list|()
operator|.
name|tagName
argument_list|()
operator|!=
name|QLatin1String
argument_list|(
literal|"xkbConfigRegistry"
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"cannot parse %s, this is not an XKB config file\n"
argument_list|,
name|qPrintable
argument_list|(
name|file
operator|.
name|fileName
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|QDomElement
name|layoutList
init|=
name|find
argument_list|(
literal|"layoutList"
argument_list|,
name|dom
operator|.
name|documentElement
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|layoutList
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"cannot parse %s, this is not an XKB config file\n"
argument_list|,
name|qPrintable
argument_list|(
name|file
operator|.
name|fileName
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|QList
argument_list|<
name|XKBLayout
argument_list|>
name|layouts
init|=
name|findLayouts
argument_list|(
name|layoutList
argument_list|)
decl_stmt|;
comment|// copyright and stuff
name|printf
argument_list|(
literal|"/****************************************************************************\n"
literal|"**\n"
literal|"** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).\n"
literal|"** All rights reserved.\n"
literal|"** Contact: Nokia Corporation (qt-info@nokia.com)\n"
literal|"**\n"
literal|"** This file is part of the QtGui module of the Qt Toolkit.\n"
literal|"**\n"
literal|"** $QT_BEGIN_LICENSE:LGPL$\n"
literal|"** GNU Lesser General Public License Usage\n"
literal|"** This file may be used under the terms of the GNU Lesser General Public\n"
literal|"** License version 2.1 as published by the Free Software Foundation and\n"
literal|"** appearing in the file LICENSE.LGPL included in the packaging of this\n"
literal|"** file. Please review the following information to ensure the GNU Lesser\n"
literal|"** General Public License version 2.1 requirements will be met:\n"
literal|"** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.\n"
literal|"**\n"
literal|"** In addition, as a special exception, Nokia gives you certain additional\n"
literal|"** rights. These rights are described in the Nokia Qt LGPL Exception\n"
literal|"** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.\n"
literal|"**\n"
literal|"** GNU General Public License Usage\n"
literal|"** Alternatively, this file may be used under the terms of the GNU General\n"
literal|"** Public License version 3.0 as published by the Free Software Foundation\n"
literal|"** and appearing in the file LICENSE.GPL included in the packaging of this\n"
literal|"** file. Please review the following information to ensure the GNU General\n"
literal|"** Public License version 3.0 requirements will be met:\n"
literal|"** http://www.gnu.org/copyleft/gpl.html.\n"
literal|"**\n"
literal|"** Other Usage\n"
literal|"** Alternatively, this file may be used in accordance with the terms and\n"
literal|"** conditions contained in a signed written agreement between you and Nokia.\n"
literal|"**\n"
literal|"**\n"
literal|"**\n"
literal|"**\n"
literal|"**\n"
literal|"** $QT_END_LICENSE$\n"
literal|"**\n"
literal|"****************************************************************************/\n"
literal|"\n"
literal|"// This file is auto-generated, do not edit!\n"
literal|"// (Generated using util/xkbdatagen)\n"
literal|"\n"
argument_list|)
expr_stmt|;
comment|// data structure
name|printf
argument_list|(
literal|"static struct {\n"
literal|"    const char *layout;\n"
literal|"    const char *variant; // 0 means any variant\n"
literal|"    Qt::LayoutDirection direction;\n"
literal|"    QLocale::Language language;\n"
literal|"    QLocale::Country country;\n"
literal|"} xkbLayoutData[] = {\n"
argument_list|)
expr_stmt|;
comment|// contents
foreach|foreach
control|(
specifier|const
name|XKBLayout
modifier|&
name|l
decl|,
name|layouts
control|)
block|{
specifier|const
name|QString
name|country
init|=
name|mapCountry
argument_list|(
name|l
operator|.
name|description
argument_list|)
decl_stmt|;
name|QString
name|lang
init|=
name|mapLanguage
argument_list|(
name|l
operator|.
name|name
argument_list|)
decl_stmt|;
if|if
condition|(
name|lang
operator|.
name|isEmpty
argument_list|()
condition|)
name|lang
operator|=
literal|"C"
expr_stmt|;
name|printf
argument_list|(
literal|"    // name = %s, description = %s\n"
literal|"    { \"%s\", \"\", %s, QLocale::%s, QLocale::%s },\n"
argument_list|,
name|l
operator|.
name|name
operator|.
name|toAscii
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|l
operator|.
name|description
operator|.
name|toAscii
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|l
operator|.
name|name
operator|.
name|toAscii
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|mapDirection
argument_list|(
name|lang
argument_list|)
operator|.
name|toAscii
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|lang
operator|.
name|toAscii
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|country
operator|.
name|toAscii
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|v
decl|,
name|l
operator|.
name|variants
control|)
block|{
name|QString
name|vlang
init|=
name|mapLanguage
argument_list|(
name|l
operator|.
name|name
operator|+
literal|":"
operator|+
name|v
argument_list|)
decl_stmt|;
if|if
condition|(
name|vlang
operator|.
name|isEmpty
argument_list|()
condition|)
name|vlang
operator|=
literal|"C"
expr_stmt|;
name|printf
argument_list|(
literal|"    // name = %s:%s, description = %s\n"
literal|"    { \"%s\", \"%s\", %s, QLocale::%s, QLocale::%s },\n"
argument_list|,
name|l
operator|.
name|name
operator|.
name|toAscii
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|v
operator|.
name|toAscii
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|l
operator|.
name|description
operator|.
name|toAscii
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|l
operator|.
name|name
operator|.
name|toAscii
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|v
operator|.
name|toAscii
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|mapDirection
argument_list|(
name|vlang
argument_list|)
operator|.
name|toAscii
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|vlang
operator|.
name|toAscii
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|country
operator|.
name|toAscii
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
comment|// wrapping up
name|printf
argument_list|(
literal|"    { 0, 0, Qt::LeftToRight, QLocale::C, QLocale::AnyCountry }\n"
literal|"};\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
