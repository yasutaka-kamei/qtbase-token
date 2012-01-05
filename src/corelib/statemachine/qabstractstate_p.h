begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTSTATE_P_H
end_ifndef
begin_define
DECL|macro|QABSTRACTSTATE_P_H
define|#
directive|define
name|QABSTRACTSTATE_P_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
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
file|<private/qobject_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QStateMachine
name|class
name|QStateMachine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractState
name|class
name|QAbstractState
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAbstractStatePrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QAbstractState
argument_list|)
name|public
operator|:
expr|enum
name|StateType
block|{
name|AbstractState
block|,
name|StandardState
block|,
name|FinalState
block|,
name|HistoryState
block|}
block|;
name|QAbstractStatePrivate
argument_list|(
argument|StateType type
argument_list|)
block|;
specifier|static
name|QAbstractStatePrivate
operator|*
name|get
argument_list|(
name|QAbstractState
operator|*
name|q
argument_list|)
block|;
specifier|static
specifier|const
name|QAbstractStatePrivate
operator|*
name|get
argument_list|(
specifier|const
name|QAbstractState
operator|*
name|q
argument_list|)
block|;
name|QStateMachine
operator|*
name|machine
argument_list|()
specifier|const
block|;
name|void
name|callOnEntry
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|callOnExit
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|emitEntered
argument_list|()
block|;
name|void
name|emitExited
argument_list|()
block|;
name|uint
name|stateType
operator|:
literal|31
block|;
name|uint
name|isMachine
operator|:
literal|1
block|;
name|mutable
name|QState
operator|*
name|parentState
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
