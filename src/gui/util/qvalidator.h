begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2012 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Giuseppe D'Angelo<giuseppe.dangelo@kdab.com> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QVALIDATOR_H
end_ifndef
begin_define
DECL|macro|QVALIDATOR_H
define|#
directive|define
name|QVALIDATOR_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qregexp.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qregularexpression.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlocale.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_VALIDATOR
DECL|variable|QValidatorPrivate
name|class
name|QValidatorPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QValidator
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QValidator
argument_list|(
name|QObject
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
operator|~
name|QValidator
argument_list|()
block|;      enum
name|State
block|{
name|Invalid
block|,
name|Intermediate
block|,
name|Acceptable
block|}
block|;
name|void
name|setLocale
argument_list|(
specifier|const
name|QLocale
operator|&
name|locale
argument_list|)
block|;
name|QLocale
name|locale
argument_list|()
specifier|const
block|;
name|virtual
name|State
name|validate
argument_list|(
argument|QString&
argument_list|,
argument|int&
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|fixup
argument_list|(
argument|QString&
argument_list|)
specifier|const
block|;
name|Q_SIGNALS
operator|:
name|void
name|changed
argument_list|()
block|;
name|protected
operator|:
name|QValidator
argument_list|(
name|QObjectPrivate
operator|&
name|d
argument_list|,
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|QValidator
argument_list|(
name|QValidatorPrivate
operator|&
name|d
argument_list|,
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QValidator
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QValidator
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QIntValidator
range|:
name|public
name|QValidator
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|int bottom READ bottom WRITE setBottom NOTIFY bottomChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int top READ top WRITE setTop NOTIFY topChanged
argument_list|)
name|public
operator|:
name|explicit
name|QIntValidator
argument_list|(
name|QObject
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|QIntValidator
argument_list|(
argument|int bottom
argument_list|,
argument|int top
argument_list|,
argument|QObject *parent = Q_NULLPTR
argument_list|)
block|;
operator|~
name|QIntValidator
argument_list|()
block|;
name|QValidator
operator|::
name|State
name|validate
argument_list|(
argument|QString&
argument_list|,
argument|int&
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|fixup
argument_list|(
argument|QString&input
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setBottom
argument_list|(
name|int
argument_list|)
block|;
name|void
name|setTop
argument_list|(
name|int
argument_list|)
block|;
name|virtual
name|void
name|setRange
argument_list|(
argument|int bottom
argument_list|,
argument|int top
argument_list|)
block|;
name|int
name|bottom
argument_list|()
specifier|const
block|{
return|return
name|b
return|;
block|}
name|int
name|top
argument_list|()
specifier|const
block|{
return|return
name|t
return|;
block|}
name|Q_SIGNALS
operator|:
name|void
name|bottomChanged
argument_list|(
argument|int bottom
argument_list|)
block|;
name|void
name|topChanged
argument_list|(
argument|int top
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QIntValidator
argument_list|)
name|int
name|b
block|;
name|int
name|t
block|; }
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_REGEXP
end_ifndef
begin_decl_stmt
DECL|variable|QDoubleValidatorPrivate
name|class
name|QDoubleValidatorPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QDoubleValidator
range|:
name|public
name|QValidator
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|double bottom READ bottom WRITE setBottom NOTIFY bottomChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|double top READ top WRITE setTop NOTIFY topChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int decimals READ decimals WRITE setDecimals NOTIFY decimalsChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Notation notation READ notation WRITE setNotation NOTIFY notationChanged
argument_list|)
name|public
operator|:
name|explicit
name|QDoubleValidator
argument_list|(
name|QObject
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|QDoubleValidator
argument_list|(
argument|double bottom
argument_list|,
argument|double top
argument_list|,
argument|int decimals
argument_list|,
argument|QObject *parent = Q_NULLPTR
argument_list|)
block|;
operator|~
name|QDoubleValidator
argument_list|()
block|;      enum
name|Notation
block|{
name|StandardNotation
block|,
name|ScientificNotation
block|}
block|;
name|Q_ENUM
argument_list|(
argument|Notation
argument_list|)
name|QValidator
operator|::
name|State
name|validate
argument_list|(
argument|QString&
argument_list|,
argument|int&
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|setRange
argument_list|(
argument|double bottom
argument_list|,
argument|double top
argument_list|,
argument|int decimals =
literal|0
argument_list|)
block|;
name|void
name|setBottom
argument_list|(
name|double
argument_list|)
block|;
name|void
name|setTop
argument_list|(
name|double
argument_list|)
block|;
name|void
name|setDecimals
argument_list|(
name|int
argument_list|)
block|;
name|void
name|setNotation
argument_list|(
name|Notation
argument_list|)
block|;
name|double
name|bottom
argument_list|()
specifier|const
block|{
return|return
name|b
return|;
block|}
name|double
name|top
argument_list|()
specifier|const
block|{
return|return
name|t
return|;
block|}
name|int
name|decimals
argument_list|()
specifier|const
block|{
return|return
name|dec
return|;
block|}
name|Notation
name|notation
argument_list|()
specifier|const
block|;
name|Q_SIGNALS
operator|:
name|void
name|bottomChanged
argument_list|(
argument|double bottom
argument_list|)
block|;
name|void
name|topChanged
argument_list|(
argument|double top
argument_list|)
block|;
name|void
name|decimalsChanged
argument_list|(
argument|int decimals
argument_list|)
block|;
name|void
name|notationChanged
argument_list|(
argument|QDoubleValidator::Notation notation
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QDoubleValidator
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QDoubleValidator
argument_list|)
name|double
name|b
block|;
name|double
name|t
block|;
name|int
name|dec
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QRegExpValidator
range|:
name|public
name|QValidator
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QRegExp regExp READ regExp WRITE setRegExp NOTIFY regExpChanged
argument_list|)
name|public
operator|:
name|explicit
name|QRegExpValidator
argument_list|(
name|QObject
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|explicit
name|QRegExpValidator
argument_list|(
specifier|const
name|QRegExp
operator|&
name|rx
argument_list|,
name|QObject
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
operator|~
name|QRegExpValidator
argument_list|()
block|;
name|virtual
name|QValidator
operator|::
name|State
name|validate
argument_list|(
argument|QString& input
argument_list|,
argument|int& pos
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setRegExp
argument_list|(
specifier|const
name|QRegExp
operator|&
name|rx
argument_list|)
block|;
specifier|const
name|QRegExp
operator|&
name|regExp
argument_list|()
specifier|const
block|{
return|return
name|r
return|;
block|}
name|Q_SIGNALS
operator|:
name|void
name|regExpChanged
argument_list|(
specifier|const
name|QRegExp
operator|&
name|regExp
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QRegExpValidator
argument_list|)
name|QRegExp
name|r
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_REGEXP
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_REGULAREXPRESSION
end_ifndef
begin_decl_stmt
DECL|variable|QRegularExpressionValidatorPrivate
name|class
name|QRegularExpressionValidatorPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QRegularExpressionValidator
range|:
name|public
name|QValidator
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QRegularExpression regularExpression READ regularExpression WRITE setRegularExpression NOTIFY regularExpressionChanged
argument_list|)
name|public
operator|:
name|explicit
name|QRegularExpressionValidator
argument_list|(
name|QObject
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|explicit
name|QRegularExpressionValidator
argument_list|(
specifier|const
name|QRegularExpression
operator|&
name|re
argument_list|,
name|QObject
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
operator|~
name|QRegularExpressionValidator
argument_list|()
block|;
name|virtual
name|QValidator
operator|::
name|State
name|validate
argument_list|(
argument|QString&input
argument_list|,
argument|int&pos
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QRegularExpression
name|regularExpression
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setRegularExpression
argument_list|(
specifier|const
name|QRegularExpression
operator|&
name|re
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|regularExpressionChanged
argument_list|(
specifier|const
name|QRegularExpression
operator|&
name|re
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QRegularExpressionValidator
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QRegularExpressionValidator
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_REGULAREXPRESSION
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_VALIDATOR
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QVALIDATOR_H
end_comment
end_unit
