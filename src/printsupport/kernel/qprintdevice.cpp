begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 John Layt<jlayt@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtPrintSupport module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qprintdevice_p.h"
end_include
begin_include
include|#
directive|include
file|"qplatformprintdevice.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QPrintDevice
name|QPrintDevice
operator|::
name|QPrintDevice
parameter_list|()
member_init_list|:
name|d
argument_list|(
operator|new
name|QPlatformPrintDevice
argument_list|()
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QPrintDevice
name|QPrintDevice
operator|::
name|QPrintDevice
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QPlatformPrintDevice
argument_list|(
name|id
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QPrintDevice
name|QPrintDevice
operator|::
name|QPrintDevice
parameter_list|(
name|QPlatformPrintDevice
modifier|*
name|dd
parameter_list|)
member_init_list|:
name|d
argument_list|(
name|dd
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QPrintDevice
name|QPrintDevice
operator|::
name|QPrintDevice
parameter_list|(
specifier|const
name|QPrintDevice
modifier|&
name|other
parameter_list|)
member_init_list|:
name|d
argument_list|(
name|other
operator|.
name|d
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QPrintDevice
name|QPrintDevice
operator|::
name|~
name|QPrintDevice
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|operator =
name|QPrintDevice
modifier|&
name|QPrintDevice
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QPrintDevice
modifier|&
name|other
parameter_list|)
block|{
name|d
operator|=
name|other
operator|.
name|d
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
name|QPrintDevice
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QPrintDevice
modifier|&
name|other
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|d
operator|&&
name|other
operator|.
name|d
condition|)
return|return
operator|*
name|d
operator|==
operator|*
name|other
operator|.
name|d
return|;
return|return
name|d
operator|==
name|other
operator|.
name|d
return|;
block|}
end_function
begin_function
DECL|function|id
name|QString
name|QPrintDevice
operator|::
name|id
parameter_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
condition|?
name|d
operator|->
name|id
argument_list|()
else|:
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|name
name|QString
name|QPrintDevice
operator|::
name|name
parameter_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
condition|?
name|d
operator|->
name|name
argument_list|()
else|:
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|location
name|QString
name|QPrintDevice
operator|::
name|location
parameter_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
condition|?
name|d
operator|->
name|location
argument_list|()
else|:
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|makeAndModel
name|QString
name|QPrintDevice
operator|::
name|makeAndModel
parameter_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
condition|?
name|d
operator|->
name|makeAndModel
argument_list|()
else|:
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|isValid
name|bool
name|QPrintDevice
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|&&
name|d
operator|->
name|isValid
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|isDefault
name|bool
name|QPrintDevice
operator|::
name|isDefault
parameter_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
operator|&&
name|d
operator|->
name|isDefault
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|isRemote
name|bool
name|QPrintDevice
operator|::
name|isRemote
parameter_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
operator|&&
name|d
operator|->
name|isRemote
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|state
name|QPrint
operator|::
name|DeviceState
name|QPrintDevice
operator|::
name|state
parameter_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
condition|?
name|d
operator|->
name|state
argument_list|()
else|:
name|QPrint
operator|::
name|Error
return|;
block|}
end_function
begin_function
DECL|function|isValidPageLayout
name|bool
name|QPrintDevice
operator|::
name|isValidPageLayout
parameter_list|(
specifier|const
name|QPageLayout
modifier|&
name|layout
parameter_list|,
name|int
name|resolution
parameter_list|)
specifier|const
block|{
return|return
name|isValid
argument_list|()
operator|&&
name|d
operator|->
name|isValidPageLayout
argument_list|(
name|layout
argument_list|,
name|resolution
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|supportsMultipleCopies
name|bool
name|QPrintDevice
operator|::
name|supportsMultipleCopies
parameter_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
operator|&&
name|d
operator|->
name|supportsMultipleCopies
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|supportsCollateCopies
name|bool
name|QPrintDevice
operator|::
name|supportsCollateCopies
parameter_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
operator|&&
name|d
operator|->
name|supportsCollateCopies
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|defaultPageSize
name|QPageSize
name|QPrintDevice
operator|::
name|defaultPageSize
parameter_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
condition|?
name|d
operator|->
name|defaultPageSize
argument_list|()
else|:
name|QPageSize
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|supportedPageSizes
name|QList
argument_list|<
name|QPageSize
argument_list|>
name|QPrintDevice
operator|::
name|supportedPageSizes
parameter_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
condition|?
name|d
operator|->
name|supportedPageSizes
argument_list|()
else|:
name|QList
argument_list|<
name|QPageSize
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|supportedPageSize
name|QPageSize
name|QPrintDevice
operator|::
name|supportedPageSize
parameter_list|(
specifier|const
name|QPageSize
modifier|&
name|pageSize
parameter_list|)
specifier|const
block|{
return|return
name|isValid
argument_list|()
condition|?
name|d
operator|->
name|supportedPageSize
argument_list|(
name|pageSize
argument_list|)
else|:
name|QPageSize
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|supportedPageSize
name|QPageSize
name|QPrintDevice
operator|::
name|supportedPageSize
parameter_list|(
name|QPageSize
operator|::
name|PageSizeId
name|pageSizeId
parameter_list|)
specifier|const
block|{
return|return
name|isValid
argument_list|()
condition|?
name|d
operator|->
name|supportedPageSize
argument_list|(
name|pageSizeId
argument_list|)
else|:
name|QPageSize
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|supportedPageSize
name|QPageSize
name|QPrintDevice
operator|::
name|supportedPageSize
parameter_list|(
specifier|const
name|QString
modifier|&
name|pageName
parameter_list|)
specifier|const
block|{
return|return
name|isValid
argument_list|()
condition|?
name|d
operator|->
name|supportedPageSize
argument_list|(
name|pageName
argument_list|)
else|:
name|QPageSize
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|supportedPageSize
name|QPageSize
name|QPrintDevice
operator|::
name|supportedPageSize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|pointSize
parameter_list|)
specifier|const
block|{
return|return
name|isValid
argument_list|()
condition|?
name|d
operator|->
name|supportedPageSize
argument_list|(
name|pointSize
argument_list|)
else|:
name|QPageSize
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|supportedPageSize
name|QPageSize
name|QPrintDevice
operator|::
name|supportedPageSize
parameter_list|(
specifier|const
name|QSizeF
modifier|&
name|size
parameter_list|,
name|QPageSize
operator|::
name|Unit
name|units
parameter_list|)
specifier|const
block|{
return|return
name|isValid
argument_list|()
condition|?
name|d
operator|->
name|supportedPageSize
argument_list|(
name|size
argument_list|,
name|units
argument_list|)
else|:
name|QPageSize
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|supportsCustomPageSizes
name|bool
name|QPrintDevice
operator|::
name|supportsCustomPageSizes
parameter_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
operator|&&
name|d
operator|->
name|supportsCustomPageSizes
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|minimumPhysicalPageSize
name|QSize
name|QPrintDevice
operator|::
name|minimumPhysicalPageSize
parameter_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
condition|?
name|d
operator|->
name|minimumPhysicalPageSize
argument_list|()
else|:
name|QSize
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|maximumPhysicalPageSize
name|QSize
name|QPrintDevice
operator|::
name|maximumPhysicalPageSize
parameter_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
condition|?
name|d
operator|->
name|maximumPhysicalPageSize
argument_list|()
else|:
name|QSize
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|printableMargins
name|QMarginsF
name|QPrintDevice
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
return|return
name|isValid
argument_list|()
condition|?
name|d
operator|->
name|printableMargins
argument_list|(
name|pageSize
argument_list|,
name|orientation
argument_list|,
name|resolution
argument_list|)
else|:
name|QMarginsF
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|defaultResolution
name|int
name|QPrintDevice
operator|::
name|defaultResolution
parameter_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
condition|?
name|d
operator|->
name|defaultResolution
argument_list|()
else|:
literal|0
return|;
block|}
end_function
begin_function
DECL|function|supportedResolutions
name|QList
argument_list|<
name|int
argument_list|>
name|QPrintDevice
operator|::
name|supportedResolutions
parameter_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
condition|?
name|d
operator|->
name|supportedResolutions
argument_list|()
else|:
name|QList
argument_list|<
name|int
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|defaultInputSlot
name|QPrint
operator|::
name|InputSlot
name|QPrintDevice
operator|::
name|defaultInputSlot
parameter_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
condition|?
name|d
operator|->
name|defaultInputSlot
argument_list|()
else|:
name|QPrint
operator|::
name|InputSlot
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|supportedInputSlots
name|QList
argument_list|<
name|QPrint
operator|::
name|InputSlot
argument_list|>
name|QPrintDevice
operator|::
name|supportedInputSlots
parameter_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
condition|?
name|d
operator|->
name|supportedInputSlots
argument_list|()
else|:
name|QList
argument_list|<
name|QPrint
operator|::
name|InputSlot
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|defaultOutputBin
name|QPrint
operator|::
name|OutputBin
name|QPrintDevice
operator|::
name|defaultOutputBin
parameter_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
condition|?
name|d
operator|->
name|defaultOutputBin
argument_list|()
else|:
name|QPrint
operator|::
name|OutputBin
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|supportedOutputBins
name|QList
argument_list|<
name|QPrint
operator|::
name|OutputBin
argument_list|>
name|QPrintDevice
operator|::
name|supportedOutputBins
parameter_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
condition|?
name|d
operator|->
name|supportedOutputBins
argument_list|()
else|:
name|QList
argument_list|<
name|QPrint
operator|::
name|OutputBin
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|defaultDuplexMode
name|QPrint
operator|::
name|DuplexMode
name|QPrintDevice
operator|::
name|defaultDuplexMode
parameter_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
condition|?
name|d
operator|->
name|defaultDuplexMode
argument_list|()
else|:
name|QPrint
operator|::
name|DuplexNone
return|;
block|}
end_function
begin_function
DECL|function|supportedDuplexModes
name|QList
argument_list|<
name|QPrint
operator|::
name|DuplexMode
argument_list|>
name|QPrintDevice
operator|::
name|supportedDuplexModes
parameter_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
condition|?
name|d
operator|->
name|supportedDuplexModes
argument_list|()
else|:
name|QList
argument_list|<
name|QPrint
operator|::
name|DuplexMode
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|defaultColorMode
name|QPrint
operator|::
name|ColorMode
name|QPrintDevice
operator|::
name|defaultColorMode
parameter_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
condition|?
name|d
operator|->
name|defaultColorMode
argument_list|()
else|:
name|QPrint
operator|::
name|GrayScale
return|;
block|}
end_function
begin_function
DECL|function|supportedColorModes
name|QList
argument_list|<
name|QPrint
operator|::
name|ColorMode
argument_list|>
name|QPrintDevice
operator|::
name|supportedColorModes
parameter_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
condition|?
name|d
operator|->
name|supportedColorModes
argument_list|()
else|:
name|QList
argument_list|<
name|QPrint
operator|::
name|ColorMode
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|supportedMimeTypes
name|QList
argument_list|<
name|QMimeType
argument_list|>
name|QPrintDevice
operator|::
name|supportedMimeTypes
parameter_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
condition|?
name|d
operator|->
name|supportedMimeTypes
argument_list|()
else|:
name|QList
argument_list|<
name|QMimeType
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
