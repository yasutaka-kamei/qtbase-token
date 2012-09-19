begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"propertyfield.h"
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_constructor
DECL|function|PropertyField
name|PropertyField
operator|::
name|PropertyField
parameter_list|(
name|QObject
modifier|*
name|subject
parameter_list|,
specifier|const
name|QMetaProperty
modifier|&
name|prop
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QLineEdit
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_subject
argument_list|(
name|subject
argument_list|)
member_init_list|,
name|m_lastChangeTime
argument_list|(
name|QTime
operator|::
name|currentTime
argument_list|()
argument_list|)
member_init_list|,
name|m_prop
argument_list|(
name|prop
argument_list|)
block|{
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
if|if
condition|(
name|prop
operator|.
name|hasNotifySignal
argument_list|()
condition|)
block|{
name|QMetaMethod
name|signal
init|=
name|prop
operator|.
name|notifySignal
argument_list|()
decl_stmt|;
name|QMetaMethod
name|updateSlot
init|=
name|metaObject
argument_list|()
operator|->
name|method
argument_list|(
name|metaObject
argument_list|()
operator|->
name|indexOfSlot
argument_list|(
literal|"propertyChanged()"
argument_list|)
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|m_subject
argument_list|,
name|signal
argument_list|,
name|this
argument_list|,
name|updateSlot
argument_list|)
expr_stmt|;
block|}
name|propertyChanged
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|valueToString
name|QString
name|PropertyField
operator|::
name|valueToString
parameter_list|(
name|QVariant
name|val
parameter_list|)
block|{
name|QString
name|text
init|=
name|val
operator|.
name|toString
argument_list|()
decl_stmt|;
if|if
condition|(
name|val
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|Size
condition|)
name|text
operator|=
name|QString
argument_list|(
literal|"%1 x %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|val
operator|.
name|toSize
argument_list|()
operator|.
name|width
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|val
operator|.
name|toSize
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|val
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|SizeF
condition|)
name|text
operator|=
name|QString
argument_list|(
literal|"%1 x %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|val
operator|.
name|toSizeF
argument_list|()
operator|.
name|width
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|val
operator|.
name|toSizeF
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|val
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|Rect
condition|)
name|text
operator|=
name|QString
argument_list|(
literal|"%1 x %2 +%3 +%4"
argument_list|)
operator|.
name|arg
argument_list|(
name|val
operator|.
name|toRect
argument_list|()
operator|.
name|width
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|val
operator|.
name|toRect
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|val
operator|.
name|toRect
argument_list|()
operator|.
name|x
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|val
operator|.
name|toRect
argument_list|()
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|text
return|;
block|}
end_function
begin_function
DECL|function|propertyChanged
name|void
name|PropertyField
operator|::
name|propertyChanged
parameter_list|()
block|{
if|if
condition|(
name|m_prop
operator|.
name|isReadable
argument_list|()
condition|)
block|{
name|QVariant
name|val
init|=
name|m_prop
operator|.
name|read
argument_list|(
name|m_subject
argument_list|)
decl_stmt|;
name|QString
name|text
init|=
name|valueToString
argument_list|(
name|val
argument_list|)
decl_stmt|;
name|QPalette
name|modPalette
init|=
name|palette
argument_list|()
decl_stmt|;
comment|// If we are seeing a value for the first time,
comment|// pretend it was that way for a while already.
if|if
condition|(
name|m_lastText
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|m_lastText
operator|=
name|text
expr_stmt|;
name|m_lastTextShowing
operator|=
name|text
expr_stmt|;
name|m_lastChangeTime
operator|=
name|QTime
operator|::
name|currentTime
argument_list|()
operator|.
name|addSecs
argument_list|(
operator|-
literal|5
argument_list|)
expr_stmt|;
block|}
name|qDebug
argument_list|()
operator|<<
literal|"  "
operator|<<
name|QString
operator|::
name|fromUtf8
argument_list|(
name|m_prop
operator|.
name|name
argument_list|()
argument_list|)
operator|<<
literal|":"
operator|<<
name|val
expr_stmt|;
comment|// If the value has recently changed, show the change
if|if
condition|(
name|text
operator|!=
name|m_lastText
operator|||
name|m_lastChangeTime
operator|.
name|elapsed
argument_list|()
operator|<
literal|1000
condition|)
block|{
name|setText
argument_list|(
name|m_lastTextShowing
operator|+
literal|" -> "
operator|+
name|text
argument_list|)
expr_stmt|;
name|modPalette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Text
argument_list|,
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|m_lastChangeTime
operator|.
name|start
argument_list|()
expr_stmt|;
name|m_lastText
operator|=
name|text
expr_stmt|;
block|}
comment|// If the value hasn't changed recently, just show the current value
else|else
block|{
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|m_lastText
operator|=
name|text
expr_stmt|;
name|m_lastTextShowing
operator|=
name|text
expr_stmt|;
name|modPalette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Text
argument_list|,
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
block|}
name|setPalette
argument_list|(
name|modPalette
argument_list|)
expr_stmt|;
block|}
block|}
end_function
end_unit
