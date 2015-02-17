begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 John Layt<jlayt@kde.org> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qppdprintdevice.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QMimeDatabase>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_LINUXBASE
end_ifndef
begin_comment
comment|// LSB merges everything into cups.h
end_comment
begin_include
include|#
directive|include
file|<cups/language.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
end_ifndef
begin_constructor
DECL|function|QPpdPrintDevice
name|QPpdPrintDevice
operator|::
name|QPpdPrintDevice
parameter_list|()
member_init_list|:
name|QPlatformPrintDevice
argument_list|()
member_init_list|,
name|m_cupsDest
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_ppd
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QPpdPrintDevice
name|QPpdPrintDevice
operator|::
name|QPpdPrintDevice
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|)
member_init_list|:
name|QPlatformPrintDevice
argument_list|(
name|id
argument_list|)
member_init_list|,
name|m_cupsDest
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_ppd
argument_list|(
literal|0
argument_list|)
block|{
if|if
condition|(
operator|!
name|id
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// TODO For now each dest is an individual device
name|QStringList
name|parts
init|=
name|id
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
decl_stmt|;
name|m_cupsName
operator|=
name|parts
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toUtf8
argument_list|()
expr_stmt|;
if|if
condition|(
name|parts
operator|.
name|size
argument_list|()
operator|>
literal|1
condition|)
name|m_cupsInstance
operator|=
name|parts
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|toUtf8
argument_list|()
expr_stmt|;
name|loadPrinter
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_cupsDest
operator|&&
name|m_ppd
condition|)
block|{
name|m_name
operator|=
name|printerOption
argument_list|(
literal|"printer-info"
argument_list|)
expr_stmt|;
name|m_location
operator|=
name|printerOption
argument_list|(
literal|"printer-location"
argument_list|)
expr_stmt|;
name|m_makeAndModel
operator|=
name|printerOption
argument_list|(
literal|"printer-make-and-model"
argument_list|)
expr_stmt|;
name|cups_ptype_e
name|type
init|=
name|printerTypeFlags
argument_list|()
decl_stmt|;
name|m_isRemote
operator|=
name|type
operator|&
name|CUPS_PRINTER_REMOTE
expr_stmt|;
comment|// Note this is if the hardware does multiple copies, not if Cups can
name|m_supportsMultipleCopies
operator|=
name|type
operator|&
name|CUPS_PRINTER_COPIES
expr_stmt|;
comment|// Note this is if the hardware does collation, not if Cups can
name|m_supportsCollateCopies
operator|=
name|type
operator|&
name|CUPS_PRINTER_COLLATE
expr_stmt|;
comment|// Custom Page Size support
comment|// Cups cups_ptype_e CUPS_PRINTER_VARIABLE
comment|// Cups ppd_file_t variable_sizes custom_min custom_max
comment|// PPD MaxMediaWidth MaxMediaHeight
name|m_supportsCustomPageSizes
operator|=
name|type
operator|&
name|CUPS_PRINTER_VARIABLE
expr_stmt|;
name|m_minimumPhysicalPageSize
operator|=
name|QSize
argument_list|(
name|m_ppd
operator|->
name|custom_min
index|[
literal|0
index|]
argument_list|,
name|m_ppd
operator|->
name|custom_min
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|m_maximumPhysicalPageSize
operator|=
name|QSize
argument_list|(
name|m_ppd
operator|->
name|custom_max
index|[
literal|0
index|]
argument_list|,
name|m_ppd
operator|->
name|custom_max
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|m_customMargins
operator|=
name|QMarginsF
argument_list|(
name|m_ppd
operator|->
name|custom_margins
index|[
literal|0
index|]
argument_list|,
name|m_ppd
operator|->
name|custom_margins
index|[
literal|3
index|]
argument_list|,
name|m_ppd
operator|->
name|custom_margins
index|[
literal|2
index|]
argument_list|,
name|m_ppd
operator|->
name|custom_margins
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_constructor
begin_constructor
DECL|function|QPpdPrintDevice
name|QPpdPrintDevice
operator|::
name|QPpdPrintDevice
parameter_list|(
specifier|const
name|QPpdPrintDevice
modifier|&
name|other
parameter_list|)
member_init_list|:
name|QPlatformPrintDevice
argument_list|(
name|other
argument_list|)
member_init_list|,
name|m_cupsDest
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_ppd
argument_list|(
literal|0
argument_list|)
block|{
name|m_cupsName
operator|=
name|other
operator|.
name|m_cupsName
expr_stmt|;
name|m_cupsInstance
operator|=
name|other
operator|.
name|m_cupsInstance
expr_stmt|;
name|loadPrinter
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QPpdPrintDevice
name|QPpdPrintDevice
operator|::
name|~
name|QPpdPrintDevice
parameter_list|()
block|{
if|if
condition|(
name|m_ppd
condition|)
name|ppdClose
argument_list|(
name|m_ppd
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_cupsDest
condition|)
name|cupsFreeDests
argument_list|(
literal|1
argument_list|,
name|m_cupsDest
argument_list|)
expr_stmt|;
name|m_cupsDest
operator|=
literal|0
expr_stmt|;
name|m_ppd
operator|=
literal|0
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|operator =
name|QPpdPrintDevice
modifier|&
name|QPpdPrintDevice
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QPpdPrintDevice
modifier|&
name|other
parameter_list|)
block|{
name|m_cupsName
operator|=
name|other
operator|.
name|m_cupsName
expr_stmt|;
name|m_cupsInstance
operator|=
name|other
operator|.
name|m_cupsInstance
expr_stmt|;
if|if
condition|(
name|other
operator|.
name|m_cupsDest
operator|&&
name|other
operator|.
name|m_ppd
condition|)
name|loadPrinter
argument_list|()
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_function
DECL|function|operator ==
name|bool
name|QPpdPrintDevice
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QPpdPrintDevice
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
operator|(
name|m_id
operator|==
name|other
operator|.
name|m_id
operator|)
return|;
block|}
end_function
begin_function
DECL|function|isValid
name|bool
name|QPpdPrintDevice
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
name|m_cupsDest
operator|&&
name|m_ppd
return|;
block|}
end_function
begin_function
DECL|function|isDefault
name|bool
name|QPpdPrintDevice
operator|::
name|isDefault
parameter_list|()
specifier|const
block|{
return|return
name|printerTypeFlags
argument_list|()
operator|&
name|CUPS_PRINTER_DEFAULT
return|;
block|}
end_function
begin_function
DECL|function|state
name|QPrint
operator|::
name|DeviceState
name|QPpdPrintDevice
operator|::
name|state
parameter_list|()
specifier|const
block|{
comment|// 3 = idle, 4 = printing, 5 = stopped
comment|// More details available from printer-state-message and printer-state-reasons
name|int
name|state
init|=
name|printerOption
argument_list|(
name|QStringLiteral
argument_list|(
literal|"printer-state"
argument_list|)
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
if|if
condition|(
name|state
operator|==
literal|3
condition|)
return|return
name|QPrint
operator|::
name|Idle
return|;
elseif|else
if|if
condition|(
name|state
operator|==
literal|4
condition|)
return|return
name|QPrint
operator|::
name|Active
return|;
else|else
return|return
name|QPrint
operator|::
name|Error
return|;
block|}
end_function
begin_function
DECL|function|loadPageSizes
name|void
name|QPpdPrintDevice
operator|::
name|loadPageSizes
parameter_list|()
specifier|const
block|{
name|m_pageSizes
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_printableMargins
operator|.
name|clear
argument_list|()
expr_stmt|;
name|ppd_option_t
modifier|*
name|pageSizes
init|=
name|ppdFindOption
argument_list|(
name|m_ppd
argument_list|,
literal|"PageSize"
argument_list|)
decl_stmt|;
if|if
condition|(
name|pageSizes
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|pageSizes
operator|->
name|num_choices
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|ppd_size_t
modifier|*
name|ppdSize
init|=
name|ppdPageSize
argument_list|(
name|m_ppd
argument_list|,
name|pageSizes
operator|->
name|choices
index|[
name|i
index|]
operator|.
name|choice
argument_list|)
decl_stmt|;
if|if
condition|(
name|ppdSize
condition|)
block|{
comment|// Returned size is in points
name|QString
name|key
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|ppdSize
operator|->
name|name
argument_list|)
decl_stmt|;
name|QSize
name|size
init|=
name|QSize
argument_list|(
name|qRound
argument_list|(
name|ppdSize
operator|->
name|width
argument_list|)
argument_list|,
name|qRound
argument_list|(
name|ppdSize
operator|->
name|length
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|name
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|pageSizes
operator|->
name|choices
index|[
name|i
index|]
operator|.
name|text
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|size
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QPageSize
name|ps
init|=
name|createPageSize
argument_list|(
name|key
argument_list|,
name|size
argument_list|,
name|name
argument_list|)
decl_stmt|;
if|if
condition|(
name|ps
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|m_pageSizes
operator|.
name|append
argument_list|(
name|ps
argument_list|)
expr_stmt|;
name|m_printableMargins
operator|.
name|insert
argument_list|(
name|key
argument_list|,
name|QMarginsF
argument_list|(
name|ppdSize
operator|->
name|left
argument_list|,
name|ppdSize
operator|->
name|length
operator|-
name|ppdSize
operator|->
name|top
argument_list|,
name|ppdSize
operator|->
name|width
operator|-
name|ppdSize
operator|->
name|right
argument_list|,
name|ppdSize
operator|->
name|bottom
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
name|m_havePageSizes
operator|=
literal|true
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|defaultPageSize
name|QPageSize
name|QPpdPrintDevice
operator|::
name|defaultPageSize
parameter_list|()
specifier|const
block|{
name|ppd_choice_t
modifier|*
name|defaultChoice
init|=
name|ppdFindMarkedChoice
argument_list|(
name|m_ppd
argument_list|,
literal|"PageSize"
argument_list|)
decl_stmt|;
if|if
condition|(
name|defaultChoice
condition|)
block|{
name|ppd_size_t
modifier|*
name|ppdSize
init|=
name|ppdPageSize
argument_list|(
name|m_ppd
argument_list|,
name|defaultChoice
operator|->
name|choice
argument_list|)
decl_stmt|;
if|if
condition|(
name|ppdSize
condition|)
block|{
comment|// Returned size is in points
name|QString
name|key
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|ppdSize
operator|->
name|name
argument_list|)
decl_stmt|;
name|QSize
name|size
init|=
name|QSize
argument_list|(
name|qRound
argument_list|(
name|ppdSize
operator|->
name|width
argument_list|)
argument_list|,
name|qRound
argument_list|(
name|ppdSize
operator|->
name|length
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|name
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|defaultChoice
operator|->
name|text
argument_list|)
decl_stmt|;
return|return
name|createPageSize
argument_list|(
name|key
argument_list|,
name|size
argument_list|,
name|name
argument_list|)
return|;
block|}
block|}
return|return
name|QPageSize
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|printableMargins
name|QMarginsF
name|QPpdPrintDevice
operator|::
name|printableMargins
parameter_list|(
specifier|const
name|QPageSize
modifier|&
name|pageSize
parameter_list|,
name|QPageLayout
operator|::
name|Orientation
name|orientation
parameter_list|,
name|int
name|resolution
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
argument|orientation
argument_list|)
name|Q_UNUSED
argument_list|(
argument|resolution
argument_list|)
if|if
condition|(
operator|!
name|m_havePageSizes
condition|)
name|loadPageSizes
argument_list|()
expr_stmt|;
comment|// TODO Orientation?
if|if
condition|(
name|m_printableMargins
operator|.
name|contains
argument_list|(
name|pageSize
operator|.
name|key
argument_list|()
argument_list|)
condition|)
return|return
name|m_printableMargins
operator|.
name|value
argument_list|(
name|pageSize
operator|.
name|key
argument_list|()
argument_list|)
return|;
return|return
name|m_customMargins
return|;
block|}
end_function
begin_function
DECL|function|loadResolutions
name|void
name|QPpdPrintDevice
operator|::
name|loadResolutions
parameter_list|()
specifier|const
block|{
name|m_resolutions
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|// Try load standard PPD options first
name|ppd_option_t
modifier|*
name|resolutions
init|=
name|ppdFindOption
argument_list|(
name|m_ppd
argument_list|,
literal|"Resolution"
argument_list|)
decl_stmt|;
if|if
condition|(
name|resolutions
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|resolutions
operator|->
name|num_choices
condition|;
operator|++
name|i
control|)
block|{
name|int
name|res
init|=
name|QPrintUtils
operator|::
name|parsePpdResolution
argument_list|(
name|resolutions
operator|->
name|choices
index|[
name|i
index|]
operator|.
name|choice
argument_list|)
decl_stmt|;
if|if
condition|(
name|res
operator|>
literal|0
condition|)
name|m_resolutions
operator|.
name|append
argument_list|(
name|res
argument_list|)
expr_stmt|;
block|}
block|}
comment|// If no result, try just the default
if|if
condition|(
name|m_resolutions
operator|.
name|size
argument_list|()
operator|==
literal|0
condition|)
block|{
name|resolutions
operator|=
name|ppdFindOption
argument_list|(
name|m_ppd
argument_list|,
literal|"DefaultResolution"
argument_list|)
expr_stmt|;
if|if
condition|(
name|resolutions
condition|)
block|{
name|int
name|res
init|=
name|QPrintUtils
operator|::
name|parsePpdResolution
argument_list|(
name|resolutions
operator|->
name|choices
index|[
literal|0
index|]
operator|.
name|choice
argument_list|)
decl_stmt|;
if|if
condition|(
name|res
operator|>
literal|0
condition|)
name|m_resolutions
operator|.
name|append
argument_list|(
name|res
argument_list|)
expr_stmt|;
block|}
block|}
comment|// If still no result, then try HP's custom options
if|if
condition|(
name|m_resolutions
operator|.
name|size
argument_list|()
operator|==
literal|0
condition|)
block|{
name|resolutions
operator|=
name|ppdFindOption
argument_list|(
name|m_ppd
argument_list|,
literal|"HPPrintQuality"
argument_list|)
expr_stmt|;
if|if
condition|(
name|resolutions
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|resolutions
operator|->
name|num_choices
condition|;
operator|++
name|i
control|)
block|{
name|int
name|res
init|=
name|QPrintUtils
operator|::
name|parsePpdResolution
argument_list|(
name|resolutions
operator|->
name|choices
index|[
name|i
index|]
operator|.
name|choice
argument_list|)
decl_stmt|;
if|if
condition|(
name|res
operator|>
literal|0
condition|)
name|m_resolutions
operator|.
name|append
argument_list|(
name|res
argument_list|)
expr_stmt|;
block|}
block|}
block|}
if|if
condition|(
name|m_resolutions
operator|.
name|size
argument_list|()
operator|==
literal|0
condition|)
block|{
name|resolutions
operator|=
name|ppdFindOption
argument_list|(
name|m_ppd
argument_list|,
literal|"DefaultHPPrintQuality"
argument_list|)
expr_stmt|;
if|if
condition|(
name|resolutions
condition|)
block|{
name|int
name|res
init|=
name|QPrintUtils
operator|::
name|parsePpdResolution
argument_list|(
name|resolutions
operator|->
name|choices
index|[
literal|0
index|]
operator|.
name|choice
argument_list|)
decl_stmt|;
if|if
condition|(
name|res
operator|>
literal|0
condition|)
name|m_resolutions
operator|.
name|append
argument_list|(
name|res
argument_list|)
expr_stmt|;
block|}
block|}
name|m_haveResolutions
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|defaultResolution
name|int
name|QPpdPrintDevice
operator|::
name|defaultResolution
parameter_list|()
specifier|const
block|{
comment|// Try load standard PPD option first
name|ppd_option_t
modifier|*
name|resolution
init|=
name|ppdFindOption
argument_list|(
name|m_ppd
argument_list|,
literal|"DefaultResolution"
argument_list|)
decl_stmt|;
if|if
condition|(
name|resolution
condition|)
block|{
name|int
name|res
init|=
name|QPrintUtils
operator|::
name|parsePpdResolution
argument_list|(
name|resolution
operator|->
name|choices
index|[
literal|0
index|]
operator|.
name|choice
argument_list|)
decl_stmt|;
if|if
condition|(
name|res
operator|>
literal|0
condition|)
return|return
name|res
return|;
block|}
comment|// If no result, then try a marked option
name|ppd_choice_t
modifier|*
name|defaultChoice
init|=
name|ppdFindMarkedChoice
argument_list|(
name|m_ppd
argument_list|,
literal|"Resolution"
argument_list|)
decl_stmt|;
if|if
condition|(
name|defaultChoice
condition|)
block|{
name|int
name|res
init|=
name|QPrintUtils
operator|::
name|parsePpdResolution
argument_list|(
name|defaultChoice
operator|->
name|choice
argument_list|)
decl_stmt|;
if|if
condition|(
name|res
operator|>
literal|0
condition|)
return|return
name|res
return|;
block|}
comment|// If still no result, then try HP's custom options
name|resolution
operator|=
name|ppdFindOption
argument_list|(
name|m_ppd
argument_list|,
literal|"DefaultHPPrintQuality"
argument_list|)
expr_stmt|;
if|if
condition|(
name|resolution
condition|)
block|{
name|int
name|res
init|=
name|QPrintUtils
operator|::
name|parsePpdResolution
argument_list|(
name|resolution
operator|->
name|choices
index|[
literal|0
index|]
operator|.
name|choice
argument_list|)
decl_stmt|;
if|if
condition|(
name|res
operator|>
literal|0
condition|)
return|return
name|res
return|;
block|}
name|defaultChoice
operator|=
name|ppdFindMarkedChoice
argument_list|(
name|m_ppd
argument_list|,
literal|"HPPrintQuality"
argument_list|)
expr_stmt|;
if|if
condition|(
name|defaultChoice
condition|)
block|{
name|int
name|res
init|=
name|QPrintUtils
operator|::
name|parsePpdResolution
argument_list|(
name|defaultChoice
operator|->
name|choice
argument_list|)
decl_stmt|;
if|if
condition|(
name|res
operator|>
literal|0
condition|)
return|return
name|res
return|;
block|}
comment|// Otherwise return a sensible default.
comment|// TODO What is sensible? 150? 300?
return|return
literal|72
return|;
block|}
end_function
begin_function
DECL|function|loadInputSlots
name|void
name|QPpdPrintDevice
operator|::
name|loadInputSlots
parameter_list|()
specifier|const
block|{
comment|// NOTE: Implemented in both CUPS and Mac plugins, please keep in sync
comment|// TODO Deal with concatenated names like Tray1Manual or Tray1_Man,
comment|//      will currently show as CustomInputSlot
comment|// TODO Deal with separate ManualFeed key
comment|// Try load standard PPD options first
name|m_inputSlots
operator|.
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_ppd
condition|)
block|{
name|ppd_option_t
modifier|*
name|inputSlots
init|=
name|ppdFindOption
argument_list|(
name|m_ppd
argument_list|,
literal|"InputSlot"
argument_list|)
decl_stmt|;
if|if
condition|(
name|inputSlots
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|inputSlots
operator|->
name|num_choices
condition|;
operator|++
name|i
control|)
name|m_inputSlots
operator|.
name|append
argument_list|(
name|QPrintUtils
operator|::
name|ppdChoiceToInputSlot
argument_list|(
name|inputSlots
operator|->
name|choices
index|[
name|i
index|]
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// If no result, try just the default
if|if
condition|(
name|m_inputSlots
operator|.
name|size
argument_list|()
operator|==
literal|0
condition|)
block|{
name|inputSlots
operator|=
name|ppdFindOption
argument_list|(
name|m_ppd
argument_list|,
literal|"DefaultInputSlot"
argument_list|)
expr_stmt|;
if|if
condition|(
name|inputSlots
condition|)
name|m_inputSlots
operator|.
name|append
argument_list|(
name|QPrintUtils
operator|::
name|ppdChoiceToInputSlot
argument_list|(
name|inputSlots
operator|->
name|choices
index|[
literal|0
index|]
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
comment|// If still no result, just use Auto
if|if
condition|(
name|m_inputSlots
operator|.
name|size
argument_list|()
operator|==
literal|0
condition|)
name|m_inputSlots
operator|.
name|append
argument_list|(
name|QPlatformPrintDevice
operator|::
name|defaultInputSlot
argument_list|()
argument_list|)
expr_stmt|;
name|m_haveInputSlots
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|defaultInputSlot
name|QPrint
operator|::
name|InputSlot
name|QPpdPrintDevice
operator|::
name|defaultInputSlot
parameter_list|()
specifier|const
block|{
comment|// NOTE: Implemented in both CUPS and Mac plugins, please keep in sync
comment|// Try load standard PPD option first
if|if
condition|(
name|m_ppd
condition|)
block|{
name|ppd_option_t
modifier|*
name|inputSlot
init|=
name|ppdFindOption
argument_list|(
name|m_ppd
argument_list|,
literal|"DefaultInputSlot"
argument_list|)
decl_stmt|;
if|if
condition|(
name|inputSlot
condition|)
return|return
name|QPrintUtils
operator|::
name|ppdChoiceToInputSlot
argument_list|(
name|inputSlot
operator|->
name|choices
index|[
literal|0
index|]
argument_list|)
return|;
comment|// If no result, then try a marked option
name|ppd_choice_t
modifier|*
name|defaultChoice
init|=
name|ppdFindMarkedChoice
argument_list|(
name|m_ppd
argument_list|,
literal|"InputSlot"
argument_list|)
decl_stmt|;
if|if
condition|(
name|defaultChoice
condition|)
return|return
name|QPrintUtils
operator|::
name|ppdChoiceToInputSlot
argument_list|(
operator|*
name|defaultChoice
argument_list|)
return|;
block|}
comment|// Otherwise return Auto
return|return
name|QPlatformPrintDevice
operator|::
name|defaultInputSlot
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|loadOutputBins
name|void
name|QPpdPrintDevice
operator|::
name|loadOutputBins
parameter_list|()
specifier|const
block|{
comment|// NOTE: Implemented in both CUPS and Mac plugins, please keep in sync
name|m_outputBins
operator|.
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_ppd
condition|)
block|{
name|ppd_option_t
modifier|*
name|outputBins
init|=
name|ppdFindOption
argument_list|(
name|m_ppd
argument_list|,
literal|"OutputBin"
argument_list|)
decl_stmt|;
if|if
condition|(
name|outputBins
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|outputBins
operator|->
name|num_choices
condition|;
operator|++
name|i
control|)
name|m_outputBins
operator|.
name|append
argument_list|(
name|QPrintUtils
operator|::
name|ppdChoiceToOutputBin
argument_list|(
name|outputBins
operator|->
name|choices
index|[
name|i
index|]
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// If no result, try just the default
if|if
condition|(
name|m_outputBins
operator|.
name|size
argument_list|()
operator|==
literal|0
condition|)
block|{
name|outputBins
operator|=
name|ppdFindOption
argument_list|(
name|m_ppd
argument_list|,
literal|"DefaultOutputBin"
argument_list|)
expr_stmt|;
if|if
condition|(
name|outputBins
condition|)
name|m_outputBins
operator|.
name|append
argument_list|(
name|QPrintUtils
operator|::
name|ppdChoiceToOutputBin
argument_list|(
name|outputBins
operator|->
name|choices
index|[
literal|0
index|]
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
comment|// If still no result, just use Auto
if|if
condition|(
name|m_outputBins
operator|.
name|size
argument_list|()
operator|==
literal|0
condition|)
name|m_outputBins
operator|.
name|append
argument_list|(
name|QPlatformPrintDevice
operator|::
name|defaultOutputBin
argument_list|()
argument_list|)
expr_stmt|;
name|m_haveOutputBins
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|defaultOutputBin
name|QPrint
operator|::
name|OutputBin
name|QPpdPrintDevice
operator|::
name|defaultOutputBin
parameter_list|()
specifier|const
block|{
comment|// NOTE: Implemented in both CUPS and Mac plugins, please keep in sync
comment|// Try load standard PPD option first
if|if
condition|(
name|m_ppd
condition|)
block|{
name|ppd_option_t
modifier|*
name|outputBin
init|=
name|ppdFindOption
argument_list|(
name|m_ppd
argument_list|,
literal|"DefaultOutputBin"
argument_list|)
decl_stmt|;
if|if
condition|(
name|outputBin
condition|)
return|return
name|QPrintUtils
operator|::
name|ppdChoiceToOutputBin
argument_list|(
name|outputBin
operator|->
name|choices
index|[
literal|0
index|]
argument_list|)
return|;
comment|// If no result, then try a marked option
name|ppd_choice_t
modifier|*
name|defaultChoice
init|=
name|ppdFindMarkedChoice
argument_list|(
name|m_ppd
argument_list|,
literal|"OutputBin"
argument_list|)
decl_stmt|;
if|if
condition|(
name|defaultChoice
condition|)
return|return
name|QPrintUtils
operator|::
name|ppdChoiceToOutputBin
argument_list|(
operator|*
name|defaultChoice
argument_list|)
return|;
block|}
comment|// Otherwise return AutoBin
return|return
name|QPlatformPrintDevice
operator|::
name|defaultOutputBin
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|loadDuplexModes
name|void
name|QPpdPrintDevice
operator|::
name|loadDuplexModes
parameter_list|()
specifier|const
block|{
comment|// NOTE: Implemented in both CUPS and Mac plugins, please keep in sync
comment|// Try load standard PPD options first
name|m_duplexModes
operator|.
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_ppd
condition|)
block|{
name|ppd_option_t
modifier|*
name|duplexModes
init|=
name|ppdFindOption
argument_list|(
name|m_ppd
argument_list|,
literal|"Duplex"
argument_list|)
decl_stmt|;
if|if
condition|(
name|duplexModes
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|duplexModes
operator|->
name|num_choices
condition|;
operator|++
name|i
control|)
name|m_duplexModes
operator|.
name|append
argument_list|(
name|QPrintUtils
operator|::
name|ppdChoiceToDuplexMode
argument_list|(
name|duplexModes
operator|->
name|choices
index|[
name|i
index|]
operator|.
name|choice
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// If no result, try just the default
if|if
condition|(
name|m_duplexModes
operator|.
name|size
argument_list|()
operator|==
literal|0
condition|)
block|{
name|duplexModes
operator|=
name|ppdFindOption
argument_list|(
name|m_ppd
argument_list|,
literal|"DefaultDuplex"
argument_list|)
expr_stmt|;
if|if
condition|(
name|duplexModes
condition|)
name|m_duplexModes
operator|.
name|append
argument_list|(
name|QPrintUtils
operator|::
name|ppdChoiceToDuplexMode
argument_list|(
name|duplexModes
operator|->
name|choices
index|[
literal|0
index|]
operator|.
name|choice
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
comment|// If still no result, or not added in PPD, then add None
if|if
condition|(
name|m_duplexModes
operator|.
name|size
argument_list|()
operator|==
literal|0
operator|||
operator|!
name|m_duplexModes
operator|.
name|contains
argument_list|(
name|QPrint
operator|::
name|DuplexNone
argument_list|)
condition|)
name|m_duplexModes
operator|.
name|append
argument_list|(
name|QPrint
operator|::
name|DuplexNone
argument_list|)
expr_stmt|;
comment|// If have both modes, then can support DuplexAuto
if|if
condition|(
name|m_duplexModes
operator|.
name|contains
argument_list|(
name|QPrint
operator|::
name|DuplexLongSide
argument_list|)
operator|&&
name|m_duplexModes
operator|.
name|contains
argument_list|(
name|QPrint
operator|::
name|DuplexShortSide
argument_list|)
condition|)
name|m_duplexModes
operator|.
name|append
argument_list|(
name|QPrint
operator|::
name|DuplexAuto
argument_list|)
expr_stmt|;
name|m_haveDuplexModes
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|defaultDuplexMode
name|QPrint
operator|::
name|DuplexMode
name|QPpdPrintDevice
operator|::
name|defaultDuplexMode
parameter_list|()
specifier|const
block|{
comment|// Try load standard PPD option first
if|if
condition|(
name|m_ppd
condition|)
block|{
name|ppd_option_t
modifier|*
name|inputSlot
init|=
name|ppdFindOption
argument_list|(
name|m_ppd
argument_list|,
literal|"DefaultDuplex"
argument_list|)
decl_stmt|;
if|if
condition|(
name|inputSlot
condition|)
return|return
name|QPrintUtils
operator|::
name|ppdChoiceToDuplexMode
argument_list|(
name|inputSlot
operator|->
name|choices
index|[
literal|0
index|]
operator|.
name|choice
argument_list|)
return|;
comment|// If no result, then try a marked option
name|ppd_choice_t
modifier|*
name|defaultChoice
init|=
name|ppdFindMarkedChoice
argument_list|(
name|m_ppd
argument_list|,
literal|"Duplex"
argument_list|)
decl_stmt|;
if|if
condition|(
name|defaultChoice
condition|)
return|return
name|QPrintUtils
operator|::
name|ppdChoiceToDuplexMode
argument_list|(
name|defaultChoice
operator|->
name|choice
argument_list|)
return|;
block|}
comment|// Otherwise return None
return|return
name|QPrint
operator|::
name|DuplexNone
return|;
block|}
end_function
begin_function
DECL|function|loadColorModes
name|void
name|QPpdPrintDevice
operator|::
name|loadColorModes
parameter_list|()
specifier|const
block|{
comment|// Cups cups_ptype_e CUPS_PRINTER_BW CUPS_PRINTER_COLOR
comment|// Cups ppd_file_t color_device
comment|// PPD ColorDevice
name|m_colorModes
operator|.
name|clear
argument_list|()
expr_stmt|;
name|cups_ptype_e
name|type
init|=
name|printerTypeFlags
argument_list|()
decl_stmt|;
if|if
condition|(
name|type
operator|&
name|CUPS_PRINTER_BW
condition|)
name|m_colorModes
operator|.
name|append
argument_list|(
name|QPrint
operator|::
name|GrayScale
argument_list|)
expr_stmt|;
if|if
condition|(
name|type
operator|&
name|CUPS_PRINTER_COLOR
condition|)
name|m_colorModes
operator|.
name|append
argument_list|(
name|QPrint
operator|::
name|Color
argument_list|)
expr_stmt|;
name|m_haveColorModes
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|defaultColorMode
name|QPrint
operator|::
name|ColorMode
name|QPpdPrintDevice
operator|::
name|defaultColorMode
parameter_list|()
specifier|const
block|{
comment|// NOTE: Implemented in both CUPS and Mac plugins, please keep in sync
comment|// Not a proper option, usually only know if supports color or not, but some
comment|// users known to abuse ColorModel to always force GrayScale.
if|if
condition|(
name|m_ppd
operator|&&
name|supportedColorModes
argument_list|()
operator|.
name|contains
argument_list|(
name|QPrint
operator|::
name|Color
argument_list|)
condition|)
block|{
name|ppd_option_t
modifier|*
name|colorModel
init|=
name|ppdFindOption
argument_list|(
name|m_ppd
argument_list|,
literal|"DefaultColorModel"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|colorModel
condition|)
name|colorModel
operator|=
name|ppdFindOption
argument_list|(
name|m_ppd
argument_list|,
literal|"ColorModel"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|colorModel
operator|||
operator|(
name|colorModel
operator|&&
operator|!
name|qstrcmp
argument_list|(
name|colorModel
operator|->
name|defchoice
argument_list|,
literal|"Gray"
argument_list|)
operator|)
condition|)
return|return
name|QPrint
operator|::
name|Color
return|;
block|}
return|return
name|QPrint
operator|::
name|GrayScale
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_MIMETYPE
end_ifndef
begin_function
DECL|function|loadMimeTypes
name|void
name|QPpdPrintDevice
operator|::
name|loadMimeTypes
parameter_list|()
specifier|const
block|{
comment|// TODO No CUPS api? Need to manually load CUPS mime.types file?
comment|//      For now hard-code most common support types
name|QMimeDatabase
name|db
decl_stmt|;
name|m_mimeTypes
operator|.
name|append
argument_list|(
name|db
operator|.
name|mimeTypeForName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"application/pdf"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_mimeTypes
operator|.
name|append
argument_list|(
name|db
operator|.
name|mimeTypeForName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"application/postscript"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_mimeTypes
operator|.
name|append
argument_list|(
name|db
operator|.
name|mimeTypeForName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"image/gif"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_mimeTypes
operator|.
name|append
argument_list|(
name|db
operator|.
name|mimeTypeForName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"image/png"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_mimeTypes
operator|.
name|append
argument_list|(
name|db
operator|.
name|mimeTypeForName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"image/jpeg"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_mimeTypes
operator|.
name|append
argument_list|(
name|db
operator|.
name|mimeTypeForName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"image/tiff"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_mimeTypes
operator|.
name|append
argument_list|(
name|db
operator|.
name|mimeTypeForName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"text/html"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_mimeTypes
operator|.
name|append
argument_list|(
name|db
operator|.
name|mimeTypeForName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"text/plain"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_haveMimeTypes
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|loadPrinter
name|void
name|QPpdPrintDevice
operator|::
name|loadPrinter
parameter_list|()
block|{
comment|// Just to be safe, check if existing printer needs closing
if|if
condition|(
name|m_ppd
condition|)
block|{
name|ppdClose
argument_list|(
name|m_ppd
argument_list|)
expr_stmt|;
name|m_ppd
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|m_cupsDest
condition|)
block|{
name|cupsFreeDests
argument_list|(
literal|1
argument_list|,
name|m_cupsDest
argument_list|)
expr_stmt|;
name|m_cupsDest
operator|=
literal|0
expr_stmt|;
block|}
comment|// Get the print instance and PPD file
name|m_cupsDest
operator|=
name|cupsGetNamedDest
argument_list|(
name|CUPS_HTTP_DEFAULT
argument_list|,
name|m_cupsName
argument_list|,
name|m_cupsInstance
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_cupsDest
condition|)
block|{
specifier|const
name|char
modifier|*
name|ppdFile
init|=
name|cupsGetPPD
argument_list|(
name|m_cupsName
argument_list|)
decl_stmt|;
if|if
condition|(
name|ppdFile
condition|)
block|{
name|m_ppd
operator|=
name|ppdOpenFile
argument_list|(
name|ppdFile
argument_list|)
expr_stmt|;
name|unlink
argument_list|(
name|ppdFile
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|m_ppd
condition|)
block|{
name|ppdMarkDefaults
argument_list|(
name|m_ppd
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|cupsFreeDests
argument_list|(
literal|1
argument_list|,
name|m_cupsDest
argument_list|)
expr_stmt|;
name|m_cupsDest
operator|=
literal|0
expr_stmt|;
name|m_ppd
operator|=
literal|0
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|printerOption
name|QString
name|QPpdPrintDevice
operator|::
name|printerOption
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
specifier|const
block|{
return|return
name|cupsGetOption
argument_list|(
name|key
operator|.
name|toUtf8
argument_list|()
argument_list|,
name|m_cupsDest
operator|->
name|num_options
argument_list|,
name|m_cupsDest
operator|->
name|options
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|printerTypeFlags
name|cups_ptype_e
name|QPpdPrintDevice
operator|::
name|printerTypeFlags
parameter_list|()
specifier|const
block|{
return|return
cast|static_cast
argument_list|<
name|cups_ptype_e
argument_list|>
argument_list|(
name|printerOption
argument_list|(
literal|"printer-type"
argument_list|)
operator|.
name|toUInt
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PRINTER
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
