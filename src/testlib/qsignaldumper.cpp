begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/private/qsignaldumper_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmetaobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmetatype.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/qtestlog_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_namespace
DECL|namespace|QTest
namespace|namespace
name|QTest
block|{
DECL|function|qPrintMessage
specifier|inline
specifier|static
name|void
name|qPrintMessage
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|ba
parameter_list|)
block|{
name|QTestLog
operator|::
name|info
argument_list|(
name|ba
operator|.
name|constData
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
name|Q_GLOBAL_STATIC
argument_list|(
argument|QList<QByteArray>
argument_list|,
argument|ignoreClasses
argument_list|)
DECL|member|iLevel
specifier|static
name|int
name|iLevel
init|=
literal|0
decl_stmt|;
DECL|member|ignoreLevel
specifier|static
name|int
name|ignoreLevel
init|=
literal|0
decl_stmt|;
DECL|enumerator|IndentSpacesCount
enum|enum
block|{
name|IndentSpacesCount
init|=
literal|4
block|}
enum|;
DECL|function|memberName
specifier|static
name|QByteArray
name|memberName
parameter_list|(
specifier|const
name|QMetaMethod
modifier|&
name|member
parameter_list|)
block|{
name|QByteArray
name|ba
init|=
name|member
operator|.
name|signature
argument_list|()
decl_stmt|;
return|return
name|ba
operator|.
name|left
argument_list|(
name|ba
operator|.
name|indexOf
argument_list|(
literal|'('
argument_list|)
argument_list|)
return|;
block|}
DECL|function|qSignalDumperCallback
specifier|static
name|void
name|qSignalDumperCallback
parameter_list|(
name|QObject
modifier|*
name|caller
parameter_list|,
name|int
name|method_index
parameter_list|,
name|void
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|caller
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|argv
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|argv
argument_list|)
expr_stmt|;
specifier|const
name|QMetaObject
modifier|*
name|mo
init|=
name|caller
operator|->
name|metaObject
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|mo
argument_list|)
expr_stmt|;
name|QMetaMethod
name|member
init|=
name|mo
operator|->
name|method
argument_list|(
name|method_index
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|member
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|QTest
operator|::
name|ignoreClasses
argument_list|()
operator|&&
name|QTest
operator|::
name|ignoreClasses
argument_list|()
operator|->
name|contains
argument_list|(
name|mo
operator|->
name|className
argument_list|()
argument_list|)
condition|)
block|{
operator|++
name|QTest
operator|::
name|ignoreLevel
expr_stmt|;
return|return;
block|}
name|QByteArray
name|str
decl_stmt|;
name|str
operator|.
name|fill
argument_list|(
literal|' '
argument_list|,
name|QTest
operator|::
name|iLevel
operator|++
operator|*
name|QTest
operator|::
name|IndentSpacesCount
argument_list|)
expr_stmt|;
name|str
operator|+=
literal|"Signal: "
expr_stmt|;
name|str
operator|+=
name|mo
operator|->
name|className
argument_list|()
expr_stmt|;
name|str
operator|+=
literal|'('
expr_stmt|;
name|QString
name|objname
init|=
name|caller
operator|->
name|objectName
argument_list|()
decl_stmt|;
name|str
operator|+=
name|objname
operator|.
name|toLocal8Bit
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|objname
operator|.
name|isEmpty
argument_list|()
condition|)
name|str
operator|+=
literal|' '
expr_stmt|;
name|str
operator|+=
name|QByteArray
operator|::
name|number
argument_list|(
name|quintptr
argument_list|(
name|caller
argument_list|)
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|str
operator|+=
literal|") "
expr_stmt|;
name|str
operator|+=
name|QTest
operator|::
name|memberName
argument_list|(
name|member
argument_list|)
expr_stmt|;
name|str
operator|+=
literal|" ("
expr_stmt|;
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|args
init|=
name|member
operator|.
name|parameterTypes
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|args
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QByteArray
modifier|&
name|arg
init|=
name|args
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|int
name|typeId
init|=
name|QMetaType
operator|::
name|type
argument_list|(
name|args
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|arg
operator|.
name|endsWith
argument_list|(
literal|'*'
argument_list|)
operator|||
name|arg
operator|.
name|endsWith
argument_list|(
literal|'&'
argument_list|)
condition|)
block|{
name|str
operator|+=
literal|'('
expr_stmt|;
name|str
operator|+=
name|arg
expr_stmt|;
name|str
operator|+=
literal|')'
expr_stmt|;
if|if
condition|(
name|arg
operator|.
name|endsWith
argument_list|(
literal|'&'
argument_list|)
condition|)
name|str
operator|+=
literal|'@'
expr_stmt|;
name|quintptr
name|addr
init|=
name|quintptr
argument_list|(
operator|*
cast|reinterpret_cast
argument_list|<
name|void
operator|*
operator|*
argument_list|>
argument_list|(
name|argv
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
argument_list|)
decl_stmt|;
name|str
operator|.
name|append
argument_list|(
name|QByteArray
operator|::
name|number
argument_list|(
name|addr
argument_list|,
literal|16
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|typeId
operator|!=
name|QMetaType
operator|::
name|Void
condition|)
block|{
name|str
operator|.
name|append
argument_list|(
name|arg
argument_list|)
operator|.
name|append
argument_list|(
literal|'('
argument_list|)
operator|.
name|append
argument_list|(
name|QVariant
argument_list|(
name|typeId
argument_list|,
name|argv
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
operator|.
name|toString
argument_list|()
operator|.
name|toLocal8Bit
argument_list|()
argument_list|)
operator|.
name|append
argument_list|(
literal|')'
argument_list|)
expr_stmt|;
block|}
name|str
operator|.
name|append
argument_list|(
literal|", "
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|str
operator|.
name|endsWith
argument_list|(
literal|", "
argument_list|)
condition|)
name|str
operator|.
name|chop
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|str
operator|.
name|append
argument_list|(
literal|')'
argument_list|)
expr_stmt|;
name|qPrintMessage
argument_list|(
name|str
argument_list|)
expr_stmt|;
block|}
DECL|function|qSignalDumperCallbackSlot
specifier|static
name|void
name|qSignalDumperCallbackSlot
parameter_list|(
name|QObject
modifier|*
name|caller
parameter_list|,
name|int
name|method_index
parameter_list|,
name|void
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|caller
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|argv
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|argv
argument_list|)
expr_stmt|;
specifier|const
name|QMetaObject
modifier|*
name|mo
init|=
name|caller
operator|->
name|metaObject
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|mo
argument_list|)
expr_stmt|;
name|QMetaMethod
name|member
init|=
name|mo
operator|->
name|method
argument_list|(
name|method_index
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|member
operator|.
name|isValid
argument_list|()
condition|)
return|return;
if|if
condition|(
name|QTest
operator|::
name|ignoreLevel
operator|||
operator|(
name|QTest
operator|::
name|ignoreClasses
argument_list|()
operator|&&
name|QTest
operator|::
name|ignoreClasses
argument_list|()
operator|->
name|contains
argument_list|(
name|mo
operator|->
name|className
argument_list|()
argument_list|)
operator|)
condition|)
return|return;
name|QByteArray
name|str
decl_stmt|;
name|str
operator|.
name|fill
argument_list|(
literal|' '
argument_list|,
name|QTest
operator|::
name|iLevel
operator|*
name|QTest
operator|::
name|IndentSpacesCount
argument_list|)
expr_stmt|;
name|str
operator|+=
literal|"Slot: "
expr_stmt|;
name|str
operator|+=
name|mo
operator|->
name|className
argument_list|()
expr_stmt|;
name|str
operator|+=
literal|'('
expr_stmt|;
name|QString
name|objname
init|=
name|caller
operator|->
name|objectName
argument_list|()
decl_stmt|;
name|str
operator|+=
name|objname
operator|.
name|toLocal8Bit
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|objname
operator|.
name|isEmpty
argument_list|()
condition|)
name|str
operator|+=
literal|' '
expr_stmt|;
name|str
operator|+=
name|QByteArray
operator|::
name|number
argument_list|(
name|quintptr
argument_list|(
name|caller
argument_list|)
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|str
operator|+=
literal|") "
expr_stmt|;
name|str
operator|+=
name|member
operator|.
name|signature
argument_list|()
expr_stmt|;
name|qPrintMessage
argument_list|(
name|str
argument_list|)
expr_stmt|;
block|}
DECL|function|qSignalDumperCallbackEndSignal
specifier|static
name|void
name|qSignalDumperCallbackEndSignal
parameter_list|(
name|QObject
modifier|*
name|caller
parameter_list|,
name|int
comment|/*method_index*/
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|caller
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|caller
operator|->
name|metaObject
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|QTest
operator|::
name|ignoreClasses
argument_list|()
operator|&&
name|QTest
operator|::
name|ignoreClasses
argument_list|()
operator|->
name|contains
argument_list|(
name|caller
operator|->
name|metaObject
argument_list|()
operator|->
name|className
argument_list|()
argument_list|)
condition|)
block|{
operator|--
name|QTest
operator|::
name|ignoreLevel
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|QTest
operator|::
name|ignoreLevel
operator|>=
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
operator|--
name|QTest
operator|::
name|iLevel
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|QTest
operator|::
name|iLevel
operator|>=
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
end_namespace
begin_comment
comment|// this struct is copied from qobject_p.h to prevent us
end_comment
begin_comment
comment|// from including private Qt headers.
end_comment
begin_struct
DECL|struct|QSignalSpyCallbackSet
struct|struct
name|QSignalSpyCallbackSet
block|{
DECL|typedef|BeginCallback
typedef|typedef
name|void
function_decl|(
modifier|*
name|BeginCallback
function_decl|)
parameter_list|(
name|QObject
modifier|*
name|caller
parameter_list|,
name|int
name|method_index
parameter_list|,
name|void
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
DECL|typedef|EndCallback
typedef|typedef
name|void
function_decl|(
modifier|*
name|EndCallback
function_decl|)
parameter_list|(
name|QObject
modifier|*
name|caller
parameter_list|,
name|int
name|method_index
parameter_list|)
function_decl|;
DECL|member|signal_begin_callback
name|BeginCallback
name|signal_begin_callback
decl_stmt|,
DECL|member|slot_begin_callback
name|slot_begin_callback
decl_stmt|;
DECL|member|signal_end_callback
name|EndCallback
name|signal_end_callback
decl_stmt|,
DECL|member|slot_end_callback
name|slot_end_callback
decl_stmt|;
block|}
struct|;
end_struct
begin_function_decl
specifier|extern
name|void
name|Q_CORE_EXPORT
name|qt_register_signal_spy_callbacks
parameter_list|(
specifier|const
name|QSignalSpyCallbackSet
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|startDump
name|void
name|QSignalDumper
operator|::
name|startDump
parameter_list|()
block|{
specifier|static
name|QSignalSpyCallbackSet
name|set
init|=
block|{
name|QTest
operator|::
name|qSignalDumperCallback
block|,
name|QTest
operator|::
name|qSignalDumperCallbackSlot
block|,
name|QTest
operator|::
name|qSignalDumperCallbackEndSignal
block|,
literal|0
block|}
decl_stmt|;
name|qt_register_signal_spy_callbacks
argument_list|(
name|set
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|endDump
name|void
name|QSignalDumper
operator|::
name|endDump
parameter_list|()
block|{
specifier|static
name|QSignalSpyCallbackSet
name|nset
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|qt_register_signal_spy_callbacks
argument_list|(
name|nset
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|ignoreClass
name|void
name|QSignalDumper
operator|::
name|ignoreClass
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|klass
parameter_list|)
block|{
if|if
condition|(
name|QTest
operator|::
name|ignoreClasses
argument_list|()
condition|)
name|QTest
operator|::
name|ignoreClasses
argument_list|()
operator|->
name|append
argument_list|(
name|klass
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|clearIgnoredClasses
name|void
name|QSignalDumper
operator|::
name|clearIgnoredClasses
parameter_list|()
block|{
if|if
condition|(
name|QTest
operator|::
name|ignoreClasses
argument_list|()
condition|)
name|QTest
operator|::
name|ignoreClasses
argument_list|()
operator|->
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
