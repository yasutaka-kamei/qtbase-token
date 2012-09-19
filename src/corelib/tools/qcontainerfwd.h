begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCONTAINERFWD_H
end_ifndef
begin_define
DECL|macro|QCONTAINERFWD_H
define|#
directive|define
name|QCONTAINERFWD_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_expr_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|Key
DECL|variable|QCache
name|template
operator|<
name|class
name|Key
operator|,
name|class
name|T
operator|>
name|class
name|QCache
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|Key
DECL|variable|QHash
name|template
operator|<
name|class
name|Key
operator|,
name|class
name|T
operator|>
name|class
name|QHash
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|QLinkedList
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QLinkedList
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|QList
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QList
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|Key
DECL|variable|QMap
name|template
operator|<
name|class
name|Key
operator|,
name|class
name|T
operator|>
name|class
name|QMap
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|Key
DECL|variable|QMultiHash
name|template
operator|<
name|class
name|Key
operator|,
name|class
name|T
operator|>
name|class
name|QMultiHash
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|Key
DECL|variable|QMultiMap
name|template
operator|<
name|class
name|Key
operator|,
name|class
name|T
operator|>
name|class
name|QMultiMap
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|T1
name|template
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
expr|struct
name|QPair
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|QQueue
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QQueue
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|QSet
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QSet
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|QStack
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QStack
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|T
DECL|variable|Prealloc
name|template
operator|<
name|class
name|T
operator|,
name|int
name|Prealloc
operator|=
literal|256
operator|>
name|class
name|QVarLengthArray
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|QVector
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QVector
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCONTAINERFWD_H
end_comment
end_unit
