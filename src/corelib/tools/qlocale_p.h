begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLOCALE_P_H
end_ifndef
begin_define
DECL|macro|QLOCALE_P_H
define|#
directive|define
name|QLOCALE_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of internal files.  This header file may change from version to version
end_comment
begin_comment
comment|// without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"QtCore/qstring.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qvarlengtharray.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qvariant.h"
end_include
begin_include
include|#
directive|include
file|"qlocale.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_QNX
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qsocketnotifier.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMLOCALE
name|class
name|QSystemLocale
block|{
name|public
label|:
name|QSystemLocale
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QSystemLocale
argument_list|()
expr_stmt|;
struct|struct
name|CurrencyToStringArgument
block|{
name|CurrencyToStringArgument
argument_list|()
block|{ }
name|CurrencyToStringArgument
argument_list|(
specifier|const
name|QVariant
operator|&
name|v
argument_list|,
specifier|const
name|QString
operator|&
name|s
argument_list|)
operator|:
name|value
argument_list|(
name|v
argument_list|)
operator|,
name|symbol
argument_list|(
argument|s
argument_list|)
block|{ }
name|QVariant
name|value
expr_stmt|;
name|QString
name|symbol
decl_stmt|;
block|}
struct|;
enum|enum
name|QueryType
block|{
name|LanguageId
block|,
comment|// uint
name|CountryId
block|,
comment|// uint
name|DecimalPoint
block|,
comment|// QString
name|GroupSeparator
block|,
comment|// QString
name|ZeroDigit
block|,
comment|// QString
name|NegativeSign
block|,
comment|// QString
name|DateFormatLong
block|,
comment|// QString
name|DateFormatShort
block|,
comment|// QString
name|TimeFormatLong
block|,
comment|// QString
name|TimeFormatShort
block|,
comment|// QString
name|DayNameLong
block|,
comment|// QString, in: int
name|DayNameShort
block|,
comment|// QString, in: int
name|MonthNameLong
block|,
comment|// QString, in: int
name|MonthNameShort
block|,
comment|// QString, in: int
name|DateToStringLong
block|,
comment|// QString, in: QDate
name|DateToStringShort
block|,
comment|// QString in: QDate
name|TimeToStringLong
block|,
comment|// QString in: QTime
name|TimeToStringShort
block|,
comment|// QString in: QTime
name|DateTimeFormatLong
block|,
comment|// QString
name|DateTimeFormatShort
block|,
comment|// QString
name|DateTimeToStringLong
block|,
comment|// QString in: QDateTime
name|DateTimeToStringShort
block|,
comment|// QString in: QDateTime
name|MeasurementSystem
block|,
comment|// uint
name|PositiveSign
block|,
comment|// QString
name|AMText
block|,
comment|// QString
name|PMText
block|,
comment|// QString
name|FirstDayOfWeek
block|,
comment|// Qt::DayOfWeek
name|Weekdays
block|,
comment|// QList<Qt::DayOfWeek>
name|CurrencySymbol
block|,
comment|// QString in: CurrencyToStringArgument
name|CurrencyToString
block|,
comment|// QString in: qlonglong, qulonglong or double
name|UILanguages
block|,
comment|// QStringList
name|StringToStandardQuotation
block|,
comment|// QString in: QStringRef to quote
name|StringToAlternateQuotation
block|,
comment|// QString in: QStringRef to quote
name|ScriptId
block|,
comment|// uint
name|ListToSeparatedString
block|,
comment|// QString
name|LocaleChanged
block|,
comment|// system locale changed
name|NativeLanguageName
block|,
comment|// QString
name|NativeCountryName
comment|// QString
block|}
enum|;
name|virtual
name|QVariant
name|query
argument_list|(
name|QueryType
name|type
argument_list|,
name|QVariant
name|in
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QLocale
name|fallbackUiLocale
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QSystemLocale
argument_list|(
name|bool
argument_list|)
expr_stmt|;
name|friend
name|class
name|QSystemLocaleSingleton
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|QT_USE_ICU
end_ifdef
begin_decl_stmt
name|namespace
name|QIcu
block|{
name|QString
name|toUpper
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|localeId
parameter_list|,
specifier|const
name|QString
modifier|&
name|str
parameter_list|,
name|bool
modifier|*
name|ok
parameter_list|)
function_decl|;
name|QString
name|toLower
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|localeId
parameter_list|,
specifier|const
name|QString
modifier|&
name|str
parameter_list|,
name|bool
modifier|*
name|ok
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_struct
DECL|struct|QLocaleData
struct|struct
name|QLocaleData
block|{
DECL|member|public
name|public
label|:
specifier|static
specifier|const
name|QLocaleData
modifier|*
name|findLocaleData
argument_list|(
name|QLocale
operator|::
name|Language
name|language
argument_list|,
DECL|member|script
name|QLocale
operator|::
name|Script
name|script
argument_list|,
DECL|member|country
name|QLocale
operator|::
name|Country
name|country
argument_list|)
decl_stmt|;
DECL|member|m_language_id
DECL|member|m_script_id
DECL|member|m_country_id
name|quint16
name|m_language_id
decl_stmt|,
name|m_script_id
decl_stmt|,
name|m_country_id
decl_stmt|;
DECL|member|m_decimal
DECL|member|m_group
DECL|member|m_list
DECL|member|m_percent
DECL|member|m_zero
DECL|member|m_minus
DECL|member|m_plus
DECL|member|m_exponential
name|quint16
name|m_decimal
decl_stmt|,
name|m_group
decl_stmt|,
name|m_list
decl_stmt|,
name|m_percent
decl_stmt|,
name|m_zero
decl_stmt|,
name|m_minus
decl_stmt|,
name|m_plus
decl_stmt|,
name|m_exponential
decl_stmt|;
DECL|member|m_quotation_start
DECL|member|m_quotation_end
name|quint16
name|m_quotation_start
decl_stmt|,
name|m_quotation_end
decl_stmt|;
DECL|member|m_alternate_quotation_start
DECL|member|m_alternate_quotation_end
name|quint16
name|m_alternate_quotation_start
decl_stmt|,
name|m_alternate_quotation_end
decl_stmt|;
DECL|member|m_list_pattern_part_start_idx
DECL|member|m_list_pattern_part_start_size
name|quint16
name|m_list_pattern_part_start_idx
decl_stmt|,
name|m_list_pattern_part_start_size
decl_stmt|;
DECL|member|m_list_pattern_part_mid_idx
DECL|member|m_list_pattern_part_mid_size
name|quint16
name|m_list_pattern_part_mid_idx
decl_stmt|,
name|m_list_pattern_part_mid_size
decl_stmt|;
DECL|member|m_list_pattern_part_end_idx
DECL|member|m_list_pattern_part_end_size
name|quint16
name|m_list_pattern_part_end_idx
decl_stmt|,
name|m_list_pattern_part_end_size
decl_stmt|;
DECL|member|m_list_pattern_part_two_idx
DECL|member|m_list_pattern_part_two_size
name|quint16
name|m_list_pattern_part_two_idx
decl_stmt|,
name|m_list_pattern_part_two_size
decl_stmt|;
DECL|member|m_short_date_format_idx
DECL|member|m_short_date_format_size
name|quint16
name|m_short_date_format_idx
decl_stmt|,
name|m_short_date_format_size
decl_stmt|;
DECL|member|m_long_date_format_idx
DECL|member|m_long_date_format_size
name|quint16
name|m_long_date_format_idx
decl_stmt|,
name|m_long_date_format_size
decl_stmt|;
DECL|member|m_short_time_format_idx
DECL|member|m_short_time_format_size
name|quint16
name|m_short_time_format_idx
decl_stmt|,
name|m_short_time_format_size
decl_stmt|;
DECL|member|m_long_time_format_idx
DECL|member|m_long_time_format_size
name|quint16
name|m_long_time_format_idx
decl_stmt|,
name|m_long_time_format_size
decl_stmt|;
DECL|member|m_standalone_short_month_names_idx
DECL|member|m_standalone_short_month_names_size
name|quint16
name|m_standalone_short_month_names_idx
decl_stmt|,
name|m_standalone_short_month_names_size
decl_stmt|;
DECL|member|m_standalone_long_month_names_idx
DECL|member|m_standalone_long_month_names_size
name|quint16
name|m_standalone_long_month_names_idx
decl_stmt|,
name|m_standalone_long_month_names_size
decl_stmt|;
DECL|member|m_standalone_narrow_month_names_idx
DECL|member|m_standalone_narrow_month_names_size
name|quint16
name|m_standalone_narrow_month_names_idx
decl_stmt|,
name|m_standalone_narrow_month_names_size
decl_stmt|;
DECL|member|m_short_month_names_idx
DECL|member|m_short_month_names_size
name|quint16
name|m_short_month_names_idx
decl_stmt|,
name|m_short_month_names_size
decl_stmt|;
DECL|member|m_long_month_names_idx
DECL|member|m_long_month_names_size
name|quint16
name|m_long_month_names_idx
decl_stmt|,
name|m_long_month_names_size
decl_stmt|;
DECL|member|m_narrow_month_names_idx
DECL|member|m_narrow_month_names_size
name|quint16
name|m_narrow_month_names_idx
decl_stmt|,
name|m_narrow_month_names_size
decl_stmt|;
DECL|member|m_standalone_short_day_names_idx
DECL|member|m_standalone_short_day_names_size
name|quint16
name|m_standalone_short_day_names_idx
decl_stmt|,
name|m_standalone_short_day_names_size
decl_stmt|;
DECL|member|m_standalone_long_day_names_idx
DECL|member|m_standalone_long_day_names_size
name|quint16
name|m_standalone_long_day_names_idx
decl_stmt|,
name|m_standalone_long_day_names_size
decl_stmt|;
DECL|member|m_standalone_narrow_day_names_idx
DECL|member|m_standalone_narrow_day_names_size
name|quint16
name|m_standalone_narrow_day_names_idx
decl_stmt|,
name|m_standalone_narrow_day_names_size
decl_stmt|;
DECL|member|m_short_day_names_idx
DECL|member|m_short_day_names_size
name|quint16
name|m_short_day_names_idx
decl_stmt|,
name|m_short_day_names_size
decl_stmt|;
DECL|member|m_long_day_names_idx
DECL|member|m_long_day_names_size
name|quint16
name|m_long_day_names_idx
decl_stmt|,
name|m_long_day_names_size
decl_stmt|;
DECL|member|m_narrow_day_names_idx
DECL|member|m_narrow_day_names_size
name|quint16
name|m_narrow_day_names_idx
decl_stmt|,
name|m_narrow_day_names_size
decl_stmt|;
DECL|member|m_am_idx
DECL|member|m_am_size
name|quint16
name|m_am_idx
decl_stmt|,
name|m_am_size
decl_stmt|;
DECL|member|m_pm_idx
DECL|member|m_pm_size
name|quint16
name|m_pm_idx
decl_stmt|,
name|m_pm_size
decl_stmt|;
DECL|member|m_currency_iso_code
name|char
name|m_currency_iso_code
index|[
literal|3
index|]
decl_stmt|;
DECL|member|m_currency_symbol_idx
DECL|member|m_currency_symbol_size
name|quint16
name|m_currency_symbol_idx
decl_stmt|,
name|m_currency_symbol_size
decl_stmt|;
DECL|member|m_currency_display_name_idx
DECL|member|m_currency_display_name_size
name|quint16
name|m_currency_display_name_idx
decl_stmt|,
name|m_currency_display_name_size
decl_stmt|;
DECL|member|m_currency_format_idx
DECL|member|m_currency_format_size
name|quint8
name|m_currency_format_idx
decl_stmt|,
name|m_currency_format_size
decl_stmt|;
DECL|member|m_currency_negative_format_idx
DECL|member|m_currency_negative_format_size
name|quint8
name|m_currency_negative_format_idx
decl_stmt|,
name|m_currency_negative_format_size
decl_stmt|;
DECL|member|m_language_endonym_idx
DECL|member|m_language_endonym_size
name|quint16
name|m_language_endonym_idx
decl_stmt|,
name|m_language_endonym_size
decl_stmt|;
DECL|member|m_country_endonym_idx
DECL|member|m_country_endonym_size
name|quint16
name|m_country_endonym_idx
decl_stmt|,
name|m_country_endonym_size
decl_stmt|;
DECL|member|m_currency_digits
name|quint16
name|m_currency_digits
range|:
literal|2
decl_stmt|;
DECL|member|m_currency_rounding
name|quint16
name|m_currency_rounding
range|:
literal|3
decl_stmt|;
DECL|member|m_first_day_of_week
name|quint16
name|m_first_day_of_week
range|:
literal|3
decl_stmt|;
DECL|member|m_weekend_start
name|quint16
name|m_weekend_start
range|:
literal|3
decl_stmt|;
DECL|member|m_weekend_end
name|quint16
name|m_weekend_end
range|:
literal|3
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QLocalePrivate
range|:
name|public
name|QSharedData
block|{
name|public
operator|:
name|explicit
name|QLocalePrivate
argument_list|(
argument|int index
argument_list|,
argument|int numberOptions =
literal|0
argument_list|)
operator|:
name|m_index
argument_list|(
name|index
argument_list|)
block|,
name|m_numberOptions
argument_list|(
argument|numberOptions
argument_list|)
block|{
name|m_data
operator|=
name|dataPointerForIndex
argument_list|(
name|index
argument_list|)
block|;
name|m_localeID
operator|=
name|bcp47Name
argument_list|()
operator|.
name|toLatin1
argument_list|()
block|;
name|m_localeID
operator|.
name|replace
argument_list|(
literal|'-'
argument_list|,
literal|'_'
argument_list|)
block|;     }
operator|~
name|QLocalePrivate
argument_list|()
block|{     }
name|QChar
name|decimal
argument_list|()
specifier|const
block|{
return|return
name|QChar
argument_list|(
name|m_data
operator|->
name|m_decimal
argument_list|)
return|;
block|}
name|QChar
name|group
argument_list|()
specifier|const
block|{
return|return
name|QChar
argument_list|(
name|m_data
operator|->
name|m_group
argument_list|)
return|;
block|}
name|QChar
name|list
argument_list|()
specifier|const
block|{
return|return
name|QChar
argument_list|(
name|m_data
operator|->
name|m_list
argument_list|)
return|;
block|}
name|QChar
name|percent
argument_list|()
specifier|const
block|{
return|return
name|QChar
argument_list|(
name|m_data
operator|->
name|m_percent
argument_list|)
return|;
block|}
name|QChar
name|zero
argument_list|()
specifier|const
block|{
return|return
name|QChar
argument_list|(
name|m_data
operator|->
name|m_zero
argument_list|)
return|;
block|}
name|QChar
name|plus
argument_list|()
specifier|const
block|{
return|return
name|QChar
argument_list|(
name|m_data
operator|->
name|m_plus
argument_list|)
return|;
block|}
name|QChar
name|minus
argument_list|()
specifier|const
block|{
return|return
name|QChar
argument_list|(
name|m_data
operator|->
name|m_minus
argument_list|)
return|;
block|}
name|QChar
name|exponential
argument_list|()
specifier|const
block|{
return|return
name|QChar
argument_list|(
name|m_data
operator|->
name|m_exponential
argument_list|)
return|;
block|}
name|quint16
name|languageId
argument_list|()
specifier|const
block|{
return|return
name|m_data
operator|->
name|m_language_id
return|;
block|}
name|quint16
name|countryId
argument_list|()
specifier|const
block|{
return|return
name|m_data
operator|->
name|m_country_id
return|;
block|}
name|QString
name|bcp47Name
argument_list|()
specifier|const
block|;
name|QString
name|languageCode
argument_list|()
specifier|const
block|;
comment|// ### QByteArray::fromRawData would be more optimal
name|QString
name|scriptCode
argument_list|()
specifier|const
block|;
name|QString
name|countryCode
argument_list|()
specifier|const
block|;
specifier|static
name|QLocale
operator|::
name|Language
name|codeToLanguage
argument_list|(
specifier|const
name|QString
operator|&
name|code
argument_list|)
block|;
specifier|static
name|QLocale
operator|::
name|Script
name|codeToScript
argument_list|(
specifier|const
name|QString
operator|&
name|code
argument_list|)
block|;
specifier|static
name|QLocale
operator|::
name|Country
name|codeToCountry
argument_list|(
specifier|const
name|QString
operator|&
name|code
argument_list|)
block|;
specifier|static
name|void
name|getLangAndCountry
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
name|QLocale
operator|::
name|Language
operator|&
name|lang
argument_list|,
name|QLocale
operator|::
name|Script
operator|&
name|script
argument_list|,
name|QLocale
operator|::
name|Country
operator|&
name|cntry
argument_list|)
block|;
specifier|static
specifier|const
name|QLocaleData
operator|*
name|dataPointerForIndex
argument_list|(
argument|quint16 index
argument_list|)
block|;
name|QLocale
operator|::
name|MeasurementSystem
name|measurementSystem
argument_list|()
specifier|const
block|;      enum
name|DoubleForm
block|{
name|DFExponent
operator|=
literal|0
block|,
name|DFDecimal
block|,
name|DFSignificantDigits
block|,
name|_DFMax
operator|=
name|DFSignificantDigits
block|}
block|;      enum
name|Flags
block|{
name|NoFlags
operator|=
literal|0
block|,
name|Alternate
operator|=
literal|0x01
block|,
name|ZeroPadded
operator|=
literal|0x02
block|,
name|LeftAdjusted
operator|=
literal|0x04
block|,
name|BlankBeforePositive
operator|=
literal|0x08
block|,
name|AlwaysShowSign
operator|=
literal|0x10
block|,
name|ThousandsGroup
operator|=
literal|0x20
block|,
name|CapitalEorX
operator|=
literal|0x40
block|,
name|ShowBase
operator|=
literal|0x80
block|,
name|UppercaseBase
operator|=
literal|0x100
block|,
name|ForcePoint
operator|=
name|Alternate
block|}
block|;      enum
name|GroupSeparatorMode
block|{
name|FailOnGroupSeparators
block|,
name|ParseGroupSeparators
block|}
block|;
specifier|static
name|QString
name|doubleToString
argument_list|(
argument|const QChar zero
argument_list|,
argument|const QChar plus
argument_list|,
argument|const QChar minus
argument_list|,
argument|const QChar exponent
argument_list|,
argument|const QChar group
argument_list|,
argument|const QChar decimal
argument_list|,
argument|double d
argument_list|,
argument|int precision
argument_list|,
argument|DoubleForm form
argument_list|,
argument|int width
argument_list|,
argument|unsigned flags
argument_list|)
block|;
specifier|static
name|QString
name|longLongToString
argument_list|(
argument|const QChar zero
argument_list|,
argument|const QChar group
argument_list|,
argument|const QChar plus
argument_list|,
argument|const QChar minus
argument_list|,
argument|qint64 l
argument_list|,
argument|int precision
argument_list|,
argument|int base
argument_list|,
argument|int width
argument_list|,
argument|unsigned flags
argument_list|)
block|;
specifier|static
name|QString
name|unsLongLongToString
argument_list|(
argument|const QChar zero
argument_list|,
argument|const QChar group
argument_list|,
argument|const QChar plus
argument_list|,
argument|quint64 l
argument_list|,
argument|int precision
argument_list|,
argument|int base
argument_list|,
argument|int width
argument_list|,
argument|unsigned flags
argument_list|)
block|;
name|QString
name|doubleToString
argument_list|(
argument|double d
argument_list|,
argument|int precision = -
literal|1
argument_list|,
argument|DoubleForm form = DFSignificantDigits
argument_list|,
argument|int width = -
literal|1
argument_list|,
argument|unsigned flags = NoFlags
argument_list|)
specifier|const
block|;
name|QString
name|longLongToString
argument_list|(
argument|qint64 l
argument_list|,
argument|int precision = -
literal|1
argument_list|,
argument|int base =
literal|10
argument_list|,
argument|int width = -
literal|1
argument_list|,
argument|unsigned flags = NoFlags
argument_list|)
specifier|const
block|;
name|QString
name|unsLongLongToString
argument_list|(
argument|quint64 l
argument_list|,
argument|int precision = -
literal|1
argument_list|,
argument|int base =
literal|10
argument_list|,
argument|int width = -
literal|1
argument_list|,
argument|unsigned flags = NoFlags
argument_list|)
specifier|const
block|;
name|double
name|stringToDouble
argument_list|(
argument|const QString&num
argument_list|,
argument|bool *ok
argument_list|,
argument|GroupSeparatorMode group_sep_mode
argument_list|)
specifier|const
block|;
name|qint64
name|stringToLongLong
argument_list|(
argument|const QString&num
argument_list|,
argument|int base
argument_list|,
argument|bool *ok
argument_list|,
argument|GroupSeparatorMode group_sep_mode
argument_list|)
specifier|const
block|;
name|quint64
name|stringToUnsLongLong
argument_list|(
argument|const QString&num
argument_list|,
argument|int base
argument_list|,
argument|bool *ok
argument_list|,
argument|GroupSeparatorMode group_sep_mode
argument_list|)
specifier|const
block|;
specifier|static
name|double
name|bytearrayToDouble
argument_list|(
specifier|const
name|char
operator|*
name|num
argument_list|,
name|bool
operator|*
name|ok
argument_list|,
name|bool
operator|*
name|overflow
operator|=
literal|0
argument_list|)
block|;
specifier|static
name|qint64
name|bytearrayToLongLong
argument_list|(
argument|const char *num
argument_list|,
argument|int base
argument_list|,
argument|bool *ok
argument_list|,
argument|bool *overflow =
literal|0
argument_list|)
block|;
specifier|static
name|quint64
name|bytearrayToUnsLongLong
argument_list|(
argument|const char *num
argument_list|,
argument|int base
argument_list|,
argument|bool *ok
argument_list|)
block|;
typedef|typedef
name|QVarLengthArray
operator|<
name|char
operator|,
literal|256
operator|>
name|CharBuff
expr_stmt|;
name|bool
name|numberToCLocale
argument_list|(
argument|const QString&num
argument_list|,
argument|GroupSeparatorMode group_sep_mode
argument_list|,
argument|CharBuff *result
argument_list|)
specifier|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|inline
name|char
name|digitToCLocale
argument_list|(
name|QChar
name|c
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|static
name|void
name|updateSystemPrivate
parameter_list|()
function_decl|;
end_function_decl
begin_enum
enum|enum
name|NumberMode
block|{
name|IntegerMode
block|,
name|DoubleStandardMode
block|,
name|DoubleScientificMode
block|}
enum|;
end_enum
begin_decl_stmt
name|bool
name|validateChars
argument_list|(
specifier|const
name|QString
operator|&
name|str
argument_list|,
name|NumberMode
name|numMode
argument_list|,
name|QByteArray
operator|*
name|buff
argument_list|,
name|int
name|decDigits
operator|=
operator|-
literal|1
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|dateTimeToString
argument_list|(
specifier|const
name|QString
operator|&
name|format
argument_list|,
specifier|const
name|QDate
operator|*
name|date
argument_list|,
specifier|const
name|QTime
operator|*
name|time
argument_list|,
specifier|const
name|QLocale
operator|*
name|q
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QLocale
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|quint16
name|m_index
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|quint16
name|m_numberOptions
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QLocaleData
modifier|*
name|m_data
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QByteArray
name|m_localeID
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
DECL|function|digitToCLocale
specifier|inline
name|char
name|QLocalePrivate
operator|::
name|digitToCLocale
argument_list|(
argument|QChar in
argument_list|)
specifier|const
block|{
specifier|const
name|QChar
name|_zero
operator|=
name|zero
argument_list|()
block|;
specifier|const
name|QChar
name|_group
operator|=
name|group
argument_list|()
block|;
specifier|const
name|ushort
name|zeroUnicode
operator|=
name|_zero
operator|.
name|unicode
argument_list|()
block|;
specifier|const
name|ushort
name|tenUnicode
operator|=
name|zeroUnicode
operator|+
literal|10
block|;
if|if
condition|(
name|in
operator|.
name|unicode
argument_list|()
operator|>=
name|zeroUnicode
operator|&&
name|in
operator|.
name|unicode
argument_list|()
operator|<
name|tenUnicode
condition|)
return|return
literal|'0'
operator|+
name|in
operator|.
name|unicode
argument_list|()
operator|-
name|zeroUnicode
return|;
end_expr_stmt
begin_if
if|if
condition|(
name|in
operator|.
name|unicode
argument_list|()
operator|>=
literal|'0'
operator|&&
name|in
operator|.
name|unicode
argument_list|()
operator|<=
literal|'9'
condition|)
return|return
name|in
operator|.
name|toLatin1
argument_list|()
return|;
end_if
begin_if
if|if
condition|(
name|in
operator|==
name|plus
argument_list|()
condition|)
return|return
literal|'+'
return|;
end_if
begin_if
if|if
condition|(
name|in
operator|==
name|minus
argument_list|()
condition|)
return|return
literal|'-'
return|;
end_if
begin_if
if|if
condition|(
name|in
operator|==
name|decimal
argument_list|()
condition|)
return|return
literal|'.'
return|;
end_if
begin_if
if|if
condition|(
name|in
operator|==
name|group
argument_list|()
condition|)
return|return
literal|','
return|;
end_if
begin_if
if|if
condition|(
name|in
operator|==
name|exponential
argument_list|()
operator|||
name|in
operator|==
name|exponential
argument_list|()
operator|.
name|toUpper
argument_list|()
condition|)
return|return
literal|'e'
return|;
end_if
begin_comment
comment|// In several languages group() is the char 0xA0, which looks like a space.
end_comment
begin_comment
comment|// People use a regular space instead of it and complain it doesn't work.
end_comment
begin_if
if|if
condition|(
name|_group
operator|.
name|unicode
argument_list|()
operator|==
literal|0xA0
operator|&&
name|in
operator|.
name|unicode
argument_list|()
operator|==
literal|' '
condition|)
return|return
literal|','
return|;
end_if
begin_return
return|return
literal|0
return|;
end_return
begin_if
unit|}
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_QNX
argument_list|)
end_if
begin_label
unit|class
name|QBBLocaleData
label|:
end_label
begin_decl_stmt
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
range|:
name|QBBLocaleData
argument_list|()
decl_stmt|;
name|virtual
operator|~
name|QBBLocaleData
argument_list|()
expr_stmt|;
name|void
name|readPPSLocale
parameter_list|()
function_decl|;
name|public
name|Q_SLOTS
range|:
name|void
name|updateMesurementSystem
argument_list|()
decl_stmt|;
name|public
label|:
name|uint
name|ppsMeasurement
decl_stmt|;
name|QSocketNotifier
modifier|*
name|ppsNotifier
decl_stmt|;
name|int
name|ppsFd
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|QString
name|qt_readEscapedFormatString
parameter_list|(
specifier|const
name|QString
modifier|&
name|format
parameter_list|,
name|int
modifier|*
name|idx
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|qt_splitLocaleName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|QString
modifier|&
name|lang
parameter_list|,
name|QString
modifier|&
name|script
parameter_list|,
name|QString
modifier|&
name|cntry
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|int
name|qt_repeatCount
parameter_list|(
specifier|const
name|QString
modifier|&
name|s
parameter_list|,
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QStringRef
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|QList
operator|<
name|Qt
operator|::
name|DayOfWeek
operator|>
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMLOCALE
name|Q_DECLARE_METATYPE
argument_list|(
name|QSystemLocale
operator|::
name|CurrencyToStringArgument
argument_list|)
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QLOCALE_P_H
end_comment
end_unit
