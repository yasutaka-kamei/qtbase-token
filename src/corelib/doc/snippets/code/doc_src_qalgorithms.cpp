begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|list
name|QStringList
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|<<
literal|"one"
operator|<<
literal|"two"
operator|<<
literal|"three"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qFill
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|,
literal|"eleven"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// list: [ "eleven", "eleven", "eleven" ]
end_comment
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_expr_stmt
name|qFill
argument_list|(
name|list
operator|.
name|begin
argument_list|()
operator|+
literal|1
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|,
literal|"six"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// list: [ "eleven", "six", "six" ]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|resolveEntity
name|QChar
name|resolveEntity
parameter_list|(
specifier|const
name|QString
modifier|&
name|entity
parameter_list|)
block|{
specifier|static
specifier|const
name|QLatin1String
name|name_table
index|[]
init|=
block|{
literal|"AElig"
block|,
literal|"Aacute"
block|,
operator|...
block|,
literal|"zwnj"
block|}
decl_stmt|;
specifier|static
specifier|const
name|ushort
name|value_table
index|[]
init|=
block|{
literal|0x0061
block|,
literal|0x00c1
block|,
operator|...
block|,
literal|0x200c
block|}
decl_stmt|;
name|int
name|N
init|=
sizeof|sizeof
argument_list|(
name|name_table
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|name_table
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
specifier|const
name|QLatin1String
modifier|*
name|name
init|=
name|qBinaryFind
argument_list|(
name|name_table
argument_list|,
name|name_table
operator|+
name|N
argument_list|,
name|entity
argument_list|)
decl_stmt|;
name|int
name|index
init|=
name|name
operator|-
name|name_table
decl_stmt|;
if|if
condition|(
name|index
operator|==
name|N
condition|)
return|return
name|QChar
argument_list|()
return|;
return|return
name|QChar
argument_list|(
name|value_table
index|[
name|index
index|]
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|resolveEntity
name|QChar
name|resolveEntity
parameter_list|(
specifier|const
name|QString
modifier|&
name|entity
parameter_list|)
block|{
specifier|static
name|QMap
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
name|entityMap
decl_stmt|;
if|if
condition|(
operator|!
name|entityMap
condition|)
block|{
name|entityMap
operator|.
name|insert
argument_list|(
literal|"AElig"
argument_list|,
literal|0x0061
argument_list|)
expr_stmt|;
name|entityMap
operator|.
name|insert
argument_list|(
literal|"Aacute"
argument_list|,
literal|0x00c1
argument_list|)
expr_stmt|;
operator|...
name|entityMap
operator|.
name|insert
argument_list|(
literal|"zwnj"
argument_list|,
literal|0x200c
argument_list|)
expr_stmt|;
block|}
return|return
name|QChar
argument_list|(
name|entityMap
operator|.
name|value
argument_list|(
name|entity
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_decl_stmt
DECL|variable|list
name|QStringList
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|<<
literal|"one"
operator|<<
literal|"two"
operator|<<
literal|"three"
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QVector
argument_list|<
name|QString
argument_list|>
name|vect1
argument_list|(
literal|3
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|qCopy
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|,
name|vect1
operator|.
name|begin
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// vect: [ "one", "two", "three" ]
end_comment
begin_decl_stmt
name|QVector
argument_list|<
name|QString
argument_list|>
name|vect2
argument_list|(
literal|8
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|qCopy
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|,
name|vect2
operator|.
name|begin
argument_list|()
operator|+
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// vect: [ "", "", "one", "two", "three", "", "", "" ]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_decl_stmt
DECL|variable|list
name|QStringList
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|<<
literal|"one"
operator|<<
literal|"two"
operator|<<
literal|"three"
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QVector
argument_list|<
name|QString
argument_list|>
name|vect
argument_list|(
literal|5
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|qCopyBackward
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|,
name|vect
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// vect: [ "", "", "one", "two", "three" ]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_decl_stmt
DECL|variable|list
name|QStringList
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|<<
literal|"one"
operator|<<
literal|"two"
operator|<<
literal|"three"
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QVector
argument_list|<
name|QString
argument_list|>
name|vect
argument_list|(
literal|3
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|vect
index|[
literal|0
index|]
operator|=
literal|"one"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|vect
index|[
literal|1
index|]
operator|=
literal|"two"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|vect
index|[
literal|2
index|]
operator|=
literal|"three"
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|ret1
name|bool
name|ret1
init|=
name|qEqual
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|,
name|vect
operator|.
name|begin
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// ret1 == true
end_comment
begin_expr_stmt
name|vect
index|[
literal|2
index|]
operator|=
literal|"seven"
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|ret2
name|bool
name|ret2
init|=
name|qEqual
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|,
name|vect
operator|.
name|begin
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// ret2 == false
end_comment
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_decl_stmt
DECL|variable|list
name|QStringList
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|<<
literal|"one"
operator|<<
literal|"two"
operator|<<
literal|"three"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qFill
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|,
literal|"eleven"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// list: [ "eleven", "eleven", "eleven" ]
end_comment
begin_expr_stmt
name|qFill
argument_list|(
name|list
operator|.
name|begin
argument_list|()
operator|+
literal|1
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|,
literal|"six"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// list: [ "eleven", "six", "six" ]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_decl_stmt
DECL|variable|list
name|QStringList
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|<<
literal|"one"
operator|<<
literal|"two"
operator|<<
literal|"three"
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|i1
name|QStringList
operator|::
name|iterator
name|i1
init|=
name|qFind
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|,
literal|"two"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// i1 == list.begin() + 1
end_comment
begin_decl_stmt
DECL|variable|i2
name|QStringList
operator|::
name|iterator
name|i2
init|=
name|qFind
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|,
literal|"seventy"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// i2 == list.end()
end_comment
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_decl_stmt
DECL|variable|list
name|QList
argument_list|<
name|int
argument_list|>
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|<<
literal|3
operator|<<
literal|3
operator|<<
literal|6
operator|<<
literal|6
operator|<<
literal|6
operator|<<
literal|8
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|countOf6
name|int
name|countOf6
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|qCount
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|,
literal|6
argument_list|,
name|countOf6
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// countOf6 == 3
end_comment
begin_decl_stmt
DECL|variable|countOf7
name|int
name|countOf7
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|qCount
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|,
literal|7
argument_list|,
name|countOf7
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// countOf7 == 0
end_comment
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_decl_stmt
DECL|variable|pi
name|double
name|pi
init|=
literal|3.14
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|e
name|double
name|e
init|=
literal|2.71
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|qSwap
argument_list|(
name|pi
argument_list|,
name|e
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// pi == 2.71, e == 3.14
end_comment
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_decl_stmt
DECL|variable|list
name|QList
argument_list|<
name|int
argument_list|>
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|<<
literal|33
operator|<<
literal|12
operator|<<
literal|68
operator|<<
literal|6
operator|<<
literal|12
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qSort
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// list: [ 6, 12, 12, 33, 68 ]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_comment
comment|//! [12]
end_comment
begin_function
DECL|function|caseInsensitiveLessThan
name|bool
name|caseInsensitiveLessThan
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
block|{
return|return
name|s1
operator|.
name|toLower
argument_list|()
operator|<
name|s2
operator|.
name|toLower
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|doSomething
name|int
name|doSomething
parameter_list|()
block|{
name|QStringList
name|list
decl_stmt|;
name|list
operator|<<
literal|"AlPha"
operator|<<
literal|"beTA"
operator|<<
literal|"gamma"
operator|<<
literal|"DELTA"
expr_stmt|;
name|qSort
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|,
name|caseInsensitiveLessThan
argument_list|)
expr_stmt|;
comment|// list: [ "AlPha", "beTA", "DELTA", "gamma" ]
block|}
end_function
begin_comment
comment|//! [12]
end_comment
begin_comment
comment|//! [13]
end_comment
begin_decl_stmt
DECL|variable|list
name|QList
argument_list|<
name|int
argument_list|>
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|<<
literal|33
operator|<<
literal|12
operator|<<
literal|68
operator|<<
literal|6
operator|<<
literal|12
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qSort
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|,
name|qGreater
argument_list|<
name|int
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// list: [ 68, 33, 12, 12, 6 ]
end_comment
begin_comment
comment|//! [13]
end_comment
begin_comment
comment|//! [14]
end_comment
begin_decl_stmt
DECL|variable|list
name|QStringList
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|<<
literal|"AlPha"
operator|<<
literal|"beTA"
operator|<<
literal|"gamma"
operator|<<
literal|"DELTA"
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|map
name|QMap
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
name|map
decl_stmt|;
end_decl_stmt
begin_foreach
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|str
decl|,
name|list
control|)
name|map
operator|.
name|insert
argument_list|(
name|str
operator|.
name|toLower
argument_list|()
argument_list|,
name|str
argument_list|)
expr_stmt|;
end_foreach
begin_expr_stmt
name|list
operator|=
name|map
operator|.
name|values
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [14]
end_comment
begin_comment
comment|//! [15]
end_comment
begin_decl_stmt
DECL|variable|list
name|QList
argument_list|<
name|int
argument_list|>
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|<<
literal|33
operator|<<
literal|12
operator|<<
literal|68
operator|<<
literal|6
operator|<<
literal|12
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qStableSort
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// list: [ 6, 12, 12, 33, 68 ]
end_comment
begin_comment
comment|//! [15]
end_comment
begin_comment
comment|//! [16]
end_comment
begin_function
DECL|function|caseInsensitiveLessThan
name|bool
name|caseInsensitiveLessThan
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
block|{
return|return
name|s1
operator|.
name|toLower
argument_list|()
operator|<
name|s2
operator|.
name|toLower
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|doSomething
name|int
name|doSomething
parameter_list|()
block|{
name|QStringList
name|list
decl_stmt|;
name|list
operator|<<
literal|"AlPha"
operator|<<
literal|"beTA"
operator|<<
literal|"gamma"
operator|<<
literal|"DELTA"
expr_stmt|;
name|qStableSort
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|,
name|caseInsensitiveLessThan
argument_list|)
expr_stmt|;
comment|// list: [ "AlPha", "beTA", "DELTA", "gamma" ]
block|}
end_function
begin_comment
comment|//! [16]
end_comment
begin_comment
comment|//! [17]
end_comment
begin_decl_stmt
DECL|variable|list
name|QList
argument_list|<
name|int
argument_list|>
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|<<
literal|33
operator|<<
literal|12
operator|<<
literal|68
operator|<<
literal|6
operator|<<
literal|12
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qStableSort
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|,
name|qGreater
argument_list|<
name|int
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// list: [ 68, 33, 12, 12, 6 ]
end_comment
begin_comment
comment|//! [17]
end_comment
begin_comment
comment|//! [18]
end_comment
begin_decl_stmt
DECL|variable|list
name|QList
argument_list|<
name|int
argument_list|>
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|<<
literal|3
operator|<<
literal|3
operator|<<
literal|6
operator|<<
literal|6
operator|<<
literal|6
operator|<<
literal|8
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|i
name|QList
argument_list|<
name|int
argument_list|>
operator|::
name|iterator
name|i
init|=
name|qLowerBound
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|,
literal|5
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|.
name|insert
argument_list|(
name|i
argument_list|,
literal|5
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// list: [ 3, 3, 5, 6, 6, 6, 8 ]
end_comment
begin_expr_stmt
name|i
operator|=
name|qLowerBound
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|,
literal|12
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|list
operator|.
name|insert
argument_list|(
name|i
argument_list|,
literal|12
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// list: [ 3, 3, 5, 6, 6, 6, 8, 12 ]
end_comment
begin_comment
comment|//! [18]
end_comment
begin_comment
comment|//! [19]
end_comment
begin_decl_stmt
DECL|variable|vect
name|QVector
argument_list|<
name|int
argument_list|>
name|vect
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|vect
operator|<<
literal|3
operator|<<
literal|3
operator|<<
literal|6
operator|<<
literal|6
operator|<<
literal|6
operator|<<
literal|8
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|begin6
name|QVector
argument_list|<
name|int
argument_list|>
operator|::
name|iterator
name|begin6
init|=
name|qLowerBound
argument_list|(
name|vect
operator|.
name|begin
argument_list|()
argument_list|,
name|vect
operator|.
name|end
argument_list|()
argument_list|,
literal|6
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|end6
name|QVector
argument_list|<
name|int
argument_list|>
operator|::
name|iterator
name|end6
init|=
name|qUpperBound
argument_list|(
name|begin6
argument_list|,
name|vect
operator|.
name|end
argument_list|()
argument_list|,
literal|6
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|i
name|QVector
argument_list|<
name|int
argument_list|>
operator|::
name|iterator
name|i
init|=
name|begin6
decl_stmt|;
end_decl_stmt
begin_while
while|while
condition|(
name|i
operator|!=
name|end6
condition|)
block|{
operator|*
name|i
operator|=
literal|7
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
end_while
begin_comment
comment|// vect: [ 3, 3, 7, 7, 7, 8 ]
end_comment
begin_comment
comment|//! [19]
end_comment
begin_comment
comment|//! [20]
end_comment
begin_decl_stmt
DECL|variable|list
name|QList
argument_list|<
name|int
argument_list|>
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|<<
literal|3
operator|<<
literal|3
operator|<<
literal|6
operator|<<
literal|6
operator|<<
literal|6
operator|<<
literal|8
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|i
name|QList
argument_list|<
name|int
argument_list|>
operator|::
name|iterator
name|i
init|=
name|qUpperBound
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|,
literal|5
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|.
name|insert
argument_list|(
name|i
argument_list|,
literal|5
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// list: [ 3, 3, 5, 6, 6, 6, 8 ]
end_comment
begin_expr_stmt
name|i
operator|=
name|qUpperBound
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|,
literal|12
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|list
operator|.
name|insert
argument_list|(
name|i
argument_list|,
literal|12
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// list: [ 3, 3, 5, 6, 6, 6, 8, 12 ]
end_comment
begin_comment
comment|//! [20]
end_comment
begin_comment
comment|//! [21]
end_comment
begin_decl_stmt
DECL|variable|vect
name|QVector
argument_list|<
name|int
argument_list|>
name|vect
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|vect
operator|<<
literal|3
operator|<<
literal|3
operator|<<
literal|6
operator|<<
literal|6
operator|<<
literal|6
operator|<<
literal|8
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|begin6
name|QVector
argument_list|<
name|int
argument_list|>
operator|::
name|iterator
name|begin6
init|=
name|qLowerBound
argument_list|(
name|vect
operator|.
name|begin
argument_list|()
argument_list|,
name|vect
operator|.
name|end
argument_list|()
argument_list|,
literal|6
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|end6
name|QVector
argument_list|<
name|int
argument_list|>
operator|::
name|iterator
name|end6
init|=
name|qUpperBound
argument_list|(
name|vect
operator|.
name|begin
argument_list|()
argument_list|,
name|vect
operator|.
name|end
argument_list|()
argument_list|,
literal|6
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|i
name|QVector
argument_list|<
name|int
argument_list|>
operator|::
name|iterator
name|i
init|=
name|begin6
decl_stmt|;
end_decl_stmt
begin_while
while|while
condition|(
name|i
operator|!=
name|end6
condition|)
block|{
operator|*
name|i
operator|=
literal|7
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
end_while
begin_comment
comment|// vect: [ 3, 3, 7, 7, 7, 8 ]
end_comment
begin_comment
comment|//! [21]
end_comment
begin_comment
comment|//! [22]
end_comment
begin_decl_stmt
DECL|variable|vect
name|QVector
argument_list|<
name|int
argument_list|>
name|vect
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|vect
operator|<<
literal|3
operator|<<
literal|3
operator|<<
literal|6
operator|<<
literal|6
operator|<<
literal|6
operator|<<
literal|8
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|i
name|QVector
argument_list|<
name|int
argument_list|>
operator|::
name|iterator
name|i
init|=
name|qBinaryFind
argument_list|(
name|vect
operator|.
name|begin
argument_list|()
argument_list|,
name|vect
operator|.
name|end
argument_list|()
argument_list|,
literal|6
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// i == vect.begin() + 2 (or 3 or 4)
end_comment
begin_comment
comment|//! [22]
end_comment
begin_comment
comment|//! [23]
end_comment
begin_decl_stmt
DECL|variable|list
name|QList
argument_list|<
name|Employee
modifier|*
argument_list|>
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|.
name|append
argument_list|(
operator|new
name|Employee
argument_list|(
literal|"Blackpool"
argument_list|,
literal|"Stephen"
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|list
operator|.
name|append
argument_list|(
operator|new
name|Employee
argument_list|(
literal|"Twist"
argument_list|,
literal|"Oliver"
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qDeleteAll
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|list
operator|.
name|clear
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [23]
end_comment
begin_comment
comment|//! [24]
end_comment
begin_decl_stmt
DECL|variable|list
name|QList
argument_list|<
name|int
argument_list|>
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|<<
literal|33
operator|<<
literal|12
operator|<<
literal|68
operator|<<
literal|6
operator|<<
literal|12
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qSort
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|,
name|qLess
argument_list|<
name|int
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// list: [ 6, 12, 12, 33, 68 ]
end_comment
begin_comment
comment|//! [24]
end_comment
begin_comment
comment|//! [25]
end_comment
begin_decl_stmt
DECL|variable|list
name|QList
argument_list|<
name|int
argument_list|>
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|<<
literal|33
operator|<<
literal|12
operator|<<
literal|68
operator|<<
literal|6
operator|<<
literal|12
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qSort
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|,
name|qGreater
argument_list|<
name|int
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// list: [ 68, 33, 12, 12, 6 ]
end_comment
begin_comment
comment|//! [25]
end_comment
end_unit
