begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformaccessibility_qpa.h"
end_include
begin_include
include|#
directive|include
file|<private/qfactoryloader_p.h>
end_include
begin_include
include|#
directive|include
file|"qaccessibleplugin.h"
end_include
begin_include
include|#
directive|include
file|"qaccessibleobject.h"
end_include
begin_include
include|#
directive|include
file|"qaccessiblebridge.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|/* accessiblebridge plugin discovery stuff */
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
name|QFactoryLoader
argument_list|,
name|bridgeloader
argument_list|,
operator|(
name|QAccessibleBridgeFactoryInterface_iid
operator|,
name|QLatin1String
argument_list|(
literal|"/accessiblebridge"
argument_list|)
operator|)
argument_list|)
endif|#
directive|endif
name|Q_GLOBAL_STATIC
argument_list|(
name|QVector
argument_list|<
name|QAccessibleBridge
operator|*
argument_list|>
argument_list|,
name|bridges
argument_list|)
comment|/*!     \class QPlatformAccessibility     \since 5.0     \internal     \preliminary     \ingroup qpa     \ingroup accessibility      \brief The QPlatformAccessibility class is the base class for     integrating accessibility backends      \sa QAccessible */
DECL|function|QPlatformAccessibility
name|QPlatformAccessibility
operator|::
name|QPlatformAccessibility
argument_list|()
argument_list|{ }
DECL|function|~QPlatformAccessibility
name|QPlatformAccessibility
operator|::
name|~
name|QPlatformAccessibility
argument_list|()
argument_list|{ }
DECL|function|notifyAccessibilityUpdate
name|void
name|QPlatformAccessibility
operator|::
name|notifyAccessibilityUpdate
argument_list|(
name|QAccessibleEvent
operator|*
name|event
argument_list|)
argument_list|{
name|initialize
argument_list|()
argument_list|;      if
operator|(
operator|!
name|bridges
argument_list|()
operator|||
name|bridges
argument_list|()
operator|->
name|isEmpty
argument_list|()
operator|)
return|return;
end_decl_stmt
begin_for
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|bridges
argument_list|()
operator|->
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|bridges
argument_list|()
operator|->
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|notifyAccessibilityUpdate
argument_list|(
name|event
argument_list|)
expr_stmt|;
end_for
begin_macro
unit|}  void
DECL|function|setRootObject
name|QPlatformAccessibility
end_macro
begin_expr_stmt
DECL|function|setRootObject
operator|::
name|setRootObject
operator|(
name|QObject
operator|*
name|o
operator|)
block|{
name|initialize
argument_list|()
block|;
if|if
condition|(
name|bridges
argument_list|()
operator|->
name|isEmpty
argument_list|()
condition|)
return|return;
end_expr_stmt
begin_if
if|if
condition|(
operator|!
name|o
condition|)
return|return;
end_if
begin_for
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|bridges
argument_list|()
operator|->
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QAccessibleInterface
modifier|*
name|iface
init|=
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|o
argument_list|)
decl_stmt|;
name|bridges
argument_list|()
operator|->
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|setRootObject
argument_list|(
name|iface
argument_list|)
expr_stmt|;
block|}
end_for
begin_macro
unit|}  void
DECL|function|initialize
name|QPlatformAccessibility
end_macro
begin_expr_stmt
DECL|function|initialize
operator|::
name|initialize
operator|(
operator|)
block|{
specifier|static
name|bool
name|isInit
operator|=
literal|false
block|;
if|if
condition|(
name|isInit
condition|)
return|return;
name|isInit
operator|=
literal|true
expr_stmt|;
end_expr_stmt
begin_comment
comment|// ### not atomic
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
end_ifndef
begin_decl_stmt
specifier|const
name|QStringList
name|l
init|=
name|bridgeloader
argument_list|()
operator|->
name|keys
argument_list|()
decl_stmt|;
end_decl_stmt
begin_for
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|l
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|QAccessibleBridgeFactoryInterface
modifier|*
name|factory
init|=
name|qobject_cast
argument_list|<
name|QAccessibleBridgeFactoryInterface
operator|*
argument_list|>
argument_list|(
name|bridgeloader
argument_list|()
operator|->
name|instance
argument_list|(
name|l
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
argument_list|)
condition|)
block|{
name|QAccessibleBridge
modifier|*
name|bridge
init|=
name|factory
operator|->
name|create
argument_list|(
name|l
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|bridge
condition|)
block|{
name|bridges
argument_list|()
operator|->
name|append
argument_list|(
name|bridge
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_for
begin_endif
endif|#
directive|endif
end_endif
begin_macro
unit|}  void
DECL|function|cleanup
name|QPlatformAccessibility
end_macro
begin_expr_stmt
DECL|function|cleanup
operator|::
name|cleanup
operator|(
operator|)
block|{
name|qDeleteAll
argument_list|(
operator|*
name|bridges
argument_list|()
argument_list|)
block|; }
name|QT_END_NAMESPACE
end_expr_stmt
end_unit
