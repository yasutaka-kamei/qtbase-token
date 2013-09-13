begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Aleix Pol Gonzalez<aleixpol@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qcollator_p.h"
end_include
begin_include
include|#
directive|include
file|"qstringlist.h"
end_include
begin_include
include|#
directive|include
file|"qstring.h"
end_include
begin_include
include|#
directive|include
file|<cstring>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|init
name|void
name|QCollatorPrivate
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanup
name|void
name|QCollatorPrivate
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|setCaseSensitivity
name|void
name|QCollator
operator|::
name|setCaseSensitivity
parameter_list|(
name|Qt
operator|::
name|CaseSensitivity
name|cs
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|cs
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"unsupported in the posix collation implementation"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|caseSensitivity
name|Qt
operator|::
name|CaseSensitivity
name|QCollator
operator|::
name|caseSensitivity
parameter_list|()
specifier|const
block|{
name|qWarning
argument_list|(
literal|"unsupported in the posix collation implementation"
argument_list|)
expr_stmt|;
return|return
name|Qt
operator|::
name|CaseSensitive
return|;
block|}
end_function
begin_function
DECL|function|setNumericMode
name|void
name|QCollator
operator|::
name|setNumericMode
parameter_list|(
name|bool
name|on
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|on
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"unsupported in the posix collation implementation"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|numericMode
name|bool
name|QCollator
operator|::
name|numericMode
parameter_list|()
specifier|const
block|{
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|setIgnorePunctuation
name|void
name|QCollator
operator|::
name|setIgnorePunctuation
parameter_list|(
name|bool
name|on
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|on
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"unsupported in the posix collation implementation"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|ignorePunctuation
name|bool
name|QCollator
operator|::
name|ignorePunctuation
parameter_list|()
specifier|const
block|{
name|qWarning
argument_list|(
literal|"unsupported in the posix collation implementation"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|stringToWCharArray
specifier|static
name|void
name|stringToWCharArray
parameter_list|(
name|QVarLengthArray
argument_list|<
name|wchar_t
argument_list|>
modifier|&
name|ret
parameter_list|,
specifier|const
name|QString
modifier|&
name|string
parameter_list|)
block|{
name|ret
operator|.
name|resize
argument_list|(
name|string
operator|.
name|length
argument_list|()
argument_list|)
expr_stmt|;
name|int
name|len
init|=
name|string
operator|.
name|toWCharArray
argument_list|(
name|ret
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
name|ret
operator|.
name|resize
argument_list|(
name|len
operator|+
literal|1
argument_list|)
expr_stmt|;
name|ret
index|[
name|len
index|]
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|compare
name|int
name|QCollator
operator|::
name|compare
parameter_list|(
specifier|const
name|QChar
modifier|*
name|s1
parameter_list|,
name|int
name|len1
parameter_list|,
specifier|const
name|QChar
modifier|*
name|s2
parameter_list|,
name|int
name|len2
parameter_list|)
specifier|const
block|{
name|QVarLengthArray
argument_list|<
name|wchar_t
argument_list|>
name|array1
decl_stmt|,
name|array2
decl_stmt|;
name|stringToWCharArray
argument_list|(
name|array1
argument_list|,
name|QString
argument_list|(
name|s1
argument_list|,
name|len1
argument_list|)
argument_list|)
expr_stmt|;
name|stringToWCharArray
argument_list|(
name|array2
argument_list|,
name|QString
argument_list|(
name|s2
argument_list|,
name|len2
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|std
operator|::
name|wcscoll
argument_list|(
name|array1
operator|.
name|constData
argument_list|()
argument_list|,
name|array2
operator|.
name|constData
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|compare
name|int
name|QCollator
operator|::
name|compare
parameter_list|(
specifier|const
name|QString
modifier|&
name|s1
parameter_list|,
specifier|const
name|QString
modifier|&
name|s2
parameter_list|)
specifier|const
block|{
name|QVarLengthArray
argument_list|<
name|wchar_t
argument_list|>
name|array1
decl_stmt|,
name|array2
decl_stmt|;
name|stringToWCharArray
argument_list|(
name|array1
argument_list|,
name|s1
argument_list|)
expr_stmt|;
name|stringToWCharArray
argument_list|(
name|array2
argument_list|,
name|s2
argument_list|)
expr_stmt|;
return|return
name|std
operator|::
name|wcscoll
argument_list|(
name|array1
operator|.
name|constData
argument_list|()
argument_list|,
name|array2
operator|.
name|constData
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|compare
name|int
name|QCollator
operator|::
name|compare
parameter_list|(
specifier|const
name|QStringRef
modifier|&
name|s1
parameter_list|,
specifier|const
name|QStringRef
modifier|&
name|s2
parameter_list|)
specifier|const
block|{
return|return
name|compare
argument_list|(
name|s1
operator|.
name|constData
argument_list|()
argument_list|,
name|s1
operator|.
name|size
argument_list|()
argument_list|,
name|s2
operator|.
name|constData
argument_list|()
argument_list|,
name|s2
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|sortKey
name|QCollatorSortKey
name|QCollator
operator|::
name|sortKey
parameter_list|(
specifier|const
name|QString
modifier|&
name|string
parameter_list|)
specifier|const
block|{
name|QVarLengthArray
argument_list|<
name|wchar_t
argument_list|>
name|original
decl_stmt|;
name|stringToWCharArray
argument_list|(
name|original
argument_list|,
name|string
argument_list|)
expr_stmt|;
name|QVector
argument_list|<
name|wchar_t
argument_list|>
name|result
argument_list|(
name|string
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
name|size_t
name|size
init|=
name|std
operator|::
name|wcsxfrm
argument_list|(
name|result
operator|.
name|data
argument_list|()
argument_list|,
name|original
operator|.
name|constData
argument_list|()
argument_list|,
name|string
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|size
operator|>
name|uint
argument_list|(
name|result
operator|.
name|size
argument_list|()
argument_list|)
condition|)
block|{
name|result
operator|.
name|resize
argument_list|(
name|size
operator|+
literal|1
argument_list|)
expr_stmt|;
name|size
operator|=
name|std
operator|::
name|wcsxfrm
argument_list|(
name|result
operator|.
name|data
argument_list|()
argument_list|,
name|original
operator|.
name|constData
argument_list|()
argument_list|,
name|string
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|result
operator|.
name|resize
argument_list|(
name|size
operator|+
literal|1
argument_list|)
expr_stmt|;
name|result
index|[
name|size
index|]
operator|=
literal|0
expr_stmt|;
return|return
name|QCollatorSortKey
argument_list|(
operator|new
name|QCollatorSortKeyPrivate
argument_list|(
name|result
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|operator <
name|bool
name|QCollatorSortKey
operator|::
name|operator
name|<
parameter_list|(
specifier|const
name|QCollatorSortKey
modifier|&
name|otherKey
parameter_list|)
specifier|const
block|{
return|return
name|compare
argument_list|(
name|otherKey
argument_list|)
operator|<
literal|0
return|;
block|}
end_function
begin_function
DECL|function|compare
name|int
name|QCollatorSortKey
operator|::
name|compare
parameter_list|(
specifier|const
name|QCollatorSortKey
modifier|&
name|otherKey
parameter_list|)
specifier|const
block|{
return|return
name|wcscmp
argument_list|(
name|d
operator|->
name|m_key
operator|.
name|constData
argument_list|()
argument_list|,
name|otherKey
operator|.
name|d
operator|->
name|m_key
operator|.
name|constData
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit