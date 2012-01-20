begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFONTDIALOG_H
end_ifndef
begin_define
DECL|macro|QFONTDIALOG_H
define|#
directive|define
name|QFONTDIALOG_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qwindowdefs.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qdialog.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qfont.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_FONTDIALOG
name|class
name|QFontDialogPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QFontDialog
range|:
name|public
name|QDialog
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QFontDialog
argument_list|)
name|Q_ENUMS
argument_list|(
argument|FontDialogOption
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QFont currentFont READ currentFont WRITE setCurrentFont NOTIFY currentFontChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|FontDialogOptions options READ options WRITE setOptions
argument_list|)
name|public
operator|:
expr|enum
name|FontDialogOption
block|{
name|NoButtons
operator|=
literal|0x00000001
block|,
name|DontUseNativeDialog
operator|=
literal|0x00000002
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|FontDialogOptions
argument_list|,
argument|FontDialogOption
argument_list|)
name|explicit
name|QFontDialog
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QFontDialog
argument_list|(
specifier|const
name|QFont
operator|&
name|initial
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QFontDialog
argument_list|()
block|;
name|void
name|setCurrentFont
argument_list|(
specifier|const
name|QFont
operator|&
name|font
argument_list|)
block|;
name|QFont
name|currentFont
argument_list|()
specifier|const
block|;
name|QFont
name|selectedFont
argument_list|()
specifier|const
block|;
name|void
name|setOption
argument_list|(
argument|FontDialogOption option
argument_list|,
argument|bool on = true
argument_list|)
block|;
name|bool
name|testOption
argument_list|(
argument|FontDialogOption option
argument_list|)
specifier|const
block|;
name|void
name|setOptions
argument_list|(
argument|FontDialogOptions options
argument_list|)
block|;
name|FontDialogOptions
name|options
argument_list|()
specifier|const
block|;
ifdef|#
directive|ifdef
name|Q_NO_USING_KEYWORD
ifndef|#
directive|ifndef
name|Q_QDOC
name|void
name|open
argument_list|()
block|{
name|QDialog
operator|::
name|open
argument_list|()
block|; }
endif|#
directive|endif
else|#
directive|else
name|using
name|QDialog
operator|::
name|open
block|;
endif|#
directive|endif
name|void
name|open
argument_list|(
name|QObject
operator|*
name|receiver
argument_list|,
specifier|const
name|char
operator|*
name|member
argument_list|)
block|;
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
comment|// ### Qt 5: merge overloads
specifier|static
name|QFont
name|getFont
argument_list|(
argument|bool *ok
argument_list|,
argument|const QFont&initial
argument_list|,
argument|QWidget *parent
argument_list|,
argument|const QString&title
argument_list|,
argument|FontDialogOptions options
argument_list|)
block|;
specifier|static
name|QFont
name|getFont
argument_list|(
name|bool
operator|*
name|ok
argument_list|,
specifier|const
name|QFont
operator|&
name|initial
argument_list|,
name|QWidget
operator|*
name|parent
argument_list|,
specifier|const
name|QString
operator|&
name|title
argument_list|)
block|;
specifier|static
name|QFont
name|getFont
argument_list|(
name|bool
operator|*
name|ok
argument_list|,
specifier|const
name|QFont
operator|&
name|initial
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
specifier|static
name|QFont
name|getFont
argument_list|(
name|bool
operator|*
name|ok
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|currentFontChanged
argument_list|(
specifier|const
name|QFont
operator|&
name|font
argument_list|)
block|;
name|void
name|fontSelected
argument_list|(
specifier|const
name|QFont
operator|&
name|font
argument_list|)
block|;
name|protected
operator|:
name|void
name|changeEvent
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|done
argument_list|(
argument|int result
argument_list|)
block|;
name|bool
name|eventFilter
argument_list|(
name|QObject
operator|*
name|object
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QFontDialog
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sizeChanged(const QString&)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_familyHighlighted(int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_writingSystemHighlighted(int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_styleHighlighted(int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sizeHighlighted(int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateSample()
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_macRunNativeAppModalPanel()
argument_list|)
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QFontDialog::FontDialogOptions
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_FONTDIALOG
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFONTDIALOG_H
end_comment
end_unit
