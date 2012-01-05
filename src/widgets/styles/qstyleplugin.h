begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTYLEPLUGIN_H
end_ifndef
begin_define
DECL|macro|QSTYLEPLUGIN_H
define|#
directive|define
name|QSTYLEPLUGIN_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qplugin.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfactoryinterface.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QStyle
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|struct|QFactoryInterface
name|struct
name|Q_WIDGETS_EXPORT
name|QStyleFactoryInterface
range|:
name|public
name|QFactoryInterface
block|{
DECL|member|key
name|virtual
name|QStyle
operator|*
name|create
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
operator|=
literal|0
block|; }
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|QStyleFactoryInterface_iid
define|#
directive|define
name|QStyleFactoryInterface_iid
value|"com.trolltech.Qt.QStyleFactoryInterface"
end_define
begin_macro
DECL|function|Q_DECLARE_INTERFACE
name|Q_DECLARE_INTERFACE
argument_list|(
argument|QStyleFactoryInterface
argument_list|,
argument|QStyleFactoryInterface_iid
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QStylePlugin
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QStyleFactoryInterface
block|{
name|Q_OBJECT
name|Q_INTERFACES
argument_list|(
name|QStyleFactoryInterface
operator|:
name|QFactoryInterface
argument_list|)
name|public
range|:
name|explicit
name|QStylePlugin
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
decl_stmt|;
operator|~
name|QStylePlugin
argument_list|()
expr_stmt|;
name|virtual
name|QStringList
name|keys
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QStyle
modifier|*
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
init|=
literal|0
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSTYLEPLUGIN_H
end_comment
end_unit
