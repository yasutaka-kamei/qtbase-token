begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtOpenGL/qgl.h>
end_include
begin_include
include|#
directive|include
file|<QtOpenGL/qglbuffer.h>
end_include
begin_class
DECL|class|tst_QGLBuffer
class|class
name|tst_QGLBuffer
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_QGLBuffer
name|tst_QGLBuffer
parameter_list|()
block|{}
DECL|function|~tst_QGLBuffer
name|~
name|tst_QGLBuffer
parameter_list|()
block|{}
private|private
name|slots
private|:
name|void
name|vertexBuffer_data
parameter_list|()
function_decl|;
name|void
name|vertexBuffer
parameter_list|()
function_decl|;
name|void
name|indexBuffer_data
parameter_list|()
function_decl|;
name|void
name|indexBuffer
parameter_list|()
function_decl|;
name|void
name|bufferSharing
parameter_list|()
function_decl|;
private|private:
name|void
name|testBuffer
parameter_list|(
name|QGLBuffer
operator|::
name|Type
name|type
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|vertexBuffer_data
name|void
name|tst_QGLBuffer
operator|::
name|vertexBuffer_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"usagePattern"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"StreamDraw"
argument_list|)
operator|<<
name|int
argument_list|(
name|QGLBuffer
operator|::
name|StreamDraw
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"StaticDraw"
argument_list|)
operator|<<
name|int
argument_list|(
name|QGLBuffer
operator|::
name|StaticDraw
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"DynamicDraw"
argument_list|)
operator|<<
name|int
argument_list|(
name|QGLBuffer
operator|::
name|DynamicDraw
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|vertexBuffer
name|void
name|tst_QGLBuffer
operator|::
name|vertexBuffer
parameter_list|()
block|{
name|testBuffer
argument_list|(
name|QGLBuffer
operator|::
name|VertexBuffer
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|indexBuffer_data
name|void
name|tst_QGLBuffer
operator|::
name|indexBuffer_data
parameter_list|()
block|{
name|vertexBuffer_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|indexBuffer
name|void
name|tst_QGLBuffer
operator|::
name|indexBuffer
parameter_list|()
block|{
name|testBuffer
argument_list|(
name|QGLBuffer
operator|::
name|IndexBuffer
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testBuffer
name|void
name|tst_QGLBuffer
operator|::
name|testBuffer
parameter_list|(
name|QGLBuffer
operator|::
name|Type
name|type
parameter_list|)
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|usagePattern
argument_list|)
expr_stmt|;
name|QGLWidget
name|w
decl_stmt|;
name|w
operator|.
name|makeCurrent
argument_list|()
expr_stmt|;
comment|// Create the local object, but not the buffer in the server.
name|QGLBuffer
name|buffer
argument_list|(
name|type
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|buffer
operator|.
name|usagePattern
argument_list|()
operator|==
name|QGLBuffer
operator|::
name|StaticDraw
argument_list|)
expr_stmt|;
name|buffer
operator|.
name|setUsagePattern
argument_list|(
name|QGLBuffer
operator|::
name|UsagePattern
argument_list|(
name|usagePattern
argument_list|)
argument_list|)
expr_stmt|;
comment|// Check the initial state.
name|QVERIFY
argument_list|(
name|buffer
operator|.
name|type
argument_list|()
operator|==
name|type
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|buffer
operator|.
name|isCreated
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|buffer
operator|.
name|bufferId
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|buffer
operator|.
name|usagePattern
argument_list|()
operator|==
name|QGLBuffer
operator|::
name|UsagePattern
argument_list|(
name|usagePattern
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|buffer
operator|.
name|size
argument_list|()
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// Should not be able to bind it yet because it isn't created.
name|QVERIFY
argument_list|(
operator|!
name|buffer
operator|.
name|bind
argument_list|()
argument_list|)
expr_stmt|;
comment|// Create the buffer - if this fails, then assume that the
comment|// GL implementation does not support buffers at all.
if|if
condition|(
operator|!
name|buffer
operator|.
name|create
argument_list|()
condition|)
name|QSKIP
argument_list|(
literal|"Buffers are not supported on this platform"
argument_list|)
expr_stmt|;
comment|// Should now have a buffer id.
name|QVERIFY
argument_list|(
name|buffer
operator|.
name|bufferId
argument_list|()
operator|!=
literal|0
argument_list|)
expr_stmt|;
comment|// Bind the buffer and upload some data.
name|QVERIFY
argument_list|(
name|buffer
operator|.
name|bind
argument_list|()
argument_list|)
expr_stmt|;
specifier|static
name|GLfloat
specifier|const
name|data
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|,
literal|6
block|,
literal|7
block|,
literal|8
block|,
literal|9
block|}
decl_stmt|;
name|buffer
operator|.
name|allocate
argument_list|(
name|data
argument_list|,
sizeof|sizeof
argument_list|(
name|data
argument_list|)
argument_list|)
expr_stmt|;
comment|// Check the buffer size.
name|QCOMPARE
argument_list|(
name|buffer
operator|.
name|size
argument_list|()
argument_list|,
name|int
argument_list|(
sizeof|sizeof
argument_list|(
name|data
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|// Map the buffer and read back its contents.
name|bool
name|haveMap
init|=
literal|false
decl_stmt|;
name|GLfloat
modifier|*
name|mapped
init|=
cast|reinterpret_cast
argument_list|<
name|GLfloat
operator|*
argument_list|>
argument_list|(
name|buffer
operator|.
name|map
argument_list|(
name|QGLBuffer
operator|::
name|ReadOnly
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|mapped
condition|)
block|{
for|for
control|(
name|int
name|index
init|=
literal|0
init|;
name|index
operator|<
literal|9
condition|;
operator|++
name|index
control|)
name|QCOMPARE
argument_list|(
name|mapped
index|[
name|index
index|]
argument_list|,
name|data
index|[
name|index
index|]
argument_list|)
expr_stmt|;
name|buffer
operator|.
name|unmap
argument_list|()
expr_stmt|;
name|haveMap
operator|=
literal|true
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"QGLBuffer::map() is not supported on this platform"
argument_list|)
expr_stmt|;
block|}
comment|// Read back the buffer contents using read().
name|bool
name|haveRead
init|=
literal|false
decl_stmt|;
name|GLfloat
name|readdata
index|[
literal|9
index|]
decl_stmt|;
if|if
condition|(
name|buffer
operator|.
name|read
argument_list|(
literal|0
argument_list|,
name|readdata
argument_list|,
sizeof|sizeof
argument_list|(
name|readdata
argument_list|)
argument_list|)
condition|)
block|{
for|for
control|(
name|int
name|index
init|=
literal|0
init|;
name|index
operator|<
literal|9
condition|;
operator|++
name|index
control|)
name|QCOMPARE
argument_list|(
name|readdata
index|[
name|index
index|]
argument_list|,
name|data
index|[
name|index
index|]
argument_list|)
expr_stmt|;
name|haveRead
operator|=
literal|true
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"QGLBuffer::read() is not supported on this platform"
argument_list|)
expr_stmt|;
block|}
comment|// Write some different data to a specific location and check it.
specifier|static
name|GLfloat
specifier|const
name|diffdata
index|[]
init|=
block|{
literal|11
block|,
literal|12
block|,
literal|13
block|}
decl_stmt|;
name|buffer
operator|.
name|write
argument_list|(
sizeof|sizeof
argument_list|(
name|GLfloat
argument_list|)
operator|*
literal|3
argument_list|,
name|diffdata
argument_list|,
sizeof|sizeof
argument_list|(
name|diffdata
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|haveMap
condition|)
block|{
name|mapped
operator|=
cast|reinterpret_cast
argument_list|<
name|GLfloat
operator|*
argument_list|>
argument_list|(
name|buffer
operator|.
name|map
argument_list|(
name|QGLBuffer
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|mapped
operator|!=
literal|0
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|index
init|=
literal|0
init|;
name|index
operator|<
literal|9
condition|;
operator|++
name|index
control|)
block|{
if|if
condition|(
name|index
operator|>=
literal|3
operator|&&
name|index
operator|<=
literal|5
condition|)
name|QCOMPARE
argument_list|(
name|mapped
index|[
name|index
index|]
argument_list|,
name|diffdata
index|[
name|index
operator|-
literal|3
index|]
argument_list|)
expr_stmt|;
else|else
name|QCOMPARE
argument_list|(
name|mapped
index|[
name|index
index|]
argument_list|,
name|data
index|[
name|index
index|]
argument_list|)
expr_stmt|;
block|}
name|buffer
operator|.
name|unmap
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|haveRead
condition|)
block|{
name|QVERIFY
argument_list|(
name|buffer
operator|.
name|read
argument_list|(
literal|0
argument_list|,
name|readdata
argument_list|,
sizeof|sizeof
argument_list|(
name|readdata
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|index
init|=
literal|0
init|;
name|index
operator|<
literal|9
condition|;
operator|++
name|index
control|)
block|{
if|if
condition|(
name|index
operator|>=
literal|3
operator|&&
name|index
operator|<=
literal|5
condition|)
name|QCOMPARE
argument_list|(
name|readdata
index|[
name|index
index|]
argument_list|,
name|diffdata
index|[
name|index
operator|-
literal|3
index|]
argument_list|)
expr_stmt|;
else|else
name|QCOMPARE
argument_list|(
name|readdata
index|[
name|index
index|]
argument_list|,
name|data
index|[
name|index
index|]
argument_list|)
expr_stmt|;
block|}
block|}
comment|// Write to the buffer using the return value from map.
if|if
condition|(
name|haveMap
condition|)
block|{
name|mapped
operator|=
cast|reinterpret_cast
argument_list|<
name|GLfloat
operator|*
argument_list|>
argument_list|(
name|buffer
operator|.
name|map
argument_list|(
name|QGLBuffer
operator|::
name|WriteOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|mapped
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|mapped
index|[
literal|6
index|]
operator|=
literal|14
expr_stmt|;
name|buffer
operator|.
name|unmap
argument_list|()
expr_stmt|;
name|mapped
operator|=
cast|reinterpret_cast
argument_list|<
name|GLfloat
operator|*
argument_list|>
argument_list|(
name|buffer
operator|.
name|map
argument_list|(
name|QGLBuffer
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|mapped
operator|!=
literal|0
argument_list|)
expr_stmt|;
specifier|static
name|GLfloat
specifier|const
name|diff2data
index|[]
init|=
block|{
literal|11
block|,
literal|12
block|,
literal|13
block|,
literal|14
block|}
decl_stmt|;
for|for
control|(
name|int
name|index
init|=
literal|0
init|;
name|index
operator|<
literal|9
condition|;
operator|++
name|index
control|)
block|{
if|if
condition|(
name|index
operator|>=
literal|3
operator|&&
name|index
operator|<=
literal|6
condition|)
name|QCOMPARE
argument_list|(
name|mapped
index|[
name|index
index|]
argument_list|,
name|diff2data
index|[
name|index
operator|-
literal|3
index|]
argument_list|)
expr_stmt|;
else|else
name|QCOMPARE
argument_list|(
name|mapped
index|[
name|index
index|]
argument_list|,
name|data
index|[
name|index
index|]
argument_list|)
expr_stmt|;
block|}
name|buffer
operator|.
name|unmap
argument_list|()
expr_stmt|;
block|}
comment|// Resize the buffer.
name|buffer
operator|.
name|allocate
argument_list|(
sizeof|sizeof
argument_list|(
name|GLfloat
argument_list|)
operator|*
literal|20
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|buffer
operator|.
name|size
argument_list|()
argument_list|,
name|int
argument_list|(
sizeof|sizeof
argument_list|(
name|GLfloat
argument_list|)
operator|*
literal|20
argument_list|)
argument_list|)
expr_stmt|;
name|buffer
operator|.
name|allocate
argument_list|(
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|GLfloat
argument_list|)
operator|*
literal|32
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|buffer
operator|.
name|size
argument_list|()
argument_list|,
name|int
argument_list|(
sizeof|sizeof
argument_list|(
name|GLfloat
argument_list|)
operator|*
literal|32
argument_list|)
argument_list|)
expr_stmt|;
comment|// Release the buffer.
name|buffer
operator|.
name|release
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|bufferSharing
name|void
name|tst_QGLBuffer
operator|::
name|bufferSharing
parameter_list|()
block|{
name|QGLWidget
modifier|*
name|w1
init|=
operator|new
name|QGLWidget
argument_list|()
decl_stmt|;
name|w1
operator|->
name|makeCurrent
argument_list|()
expr_stmt|;
name|QGLWidget
modifier|*
name|w2
init|=
operator|new
name|QGLWidget
argument_list|(
literal|0
argument_list|,
name|w1
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|w2
operator|->
name|isSharing
argument_list|()
condition|)
block|{
operator|delete
name|w2
expr_stmt|;
operator|delete
name|w1
expr_stmt|;
name|QSKIP
argument_list|(
literal|"Context sharing is not supported on this platform"
argument_list|)
expr_stmt|;
block|}
comment|// Bind the buffer in the first context and write some data to it.
name|QGLBuffer
name|buffer
argument_list|(
name|QGLBuffer
operator|::
name|VertexBuffer
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|buffer
operator|.
name|create
argument_list|()
condition|)
name|QSKIP
argument_list|(
literal|"Buffers are not supported on this platform"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|buffer
operator|.
name|isCreated
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|buffer
operator|.
name|bind
argument_list|()
argument_list|)
expr_stmt|;
specifier|static
name|GLfloat
specifier|const
name|data
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|,
literal|6
block|,
literal|7
block|,
literal|8
block|,
literal|9
block|}
decl_stmt|;
name|buffer
operator|.
name|allocate
argument_list|(
name|data
argument_list|,
sizeof|sizeof
argument_list|(
name|data
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|buffer
operator|.
name|size
argument_list|()
argument_list|,
name|int
argument_list|(
sizeof|sizeof
argument_list|(
name|data
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|buffer
operator|.
name|release
argument_list|()
expr_stmt|;
comment|// Bind the buffer in the second context and read back the data.
name|w2
operator|->
name|makeCurrent
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|buffer
operator|.
name|bind
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|buffer
operator|.
name|size
argument_list|()
argument_list|,
name|int
argument_list|(
sizeof|sizeof
argument_list|(
name|data
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|GLfloat
name|readdata
index|[
literal|9
index|]
decl_stmt|;
if|if
condition|(
name|buffer
operator|.
name|read
argument_list|(
literal|0
argument_list|,
name|readdata
argument_list|,
sizeof|sizeof
argument_list|(
name|readdata
argument_list|)
argument_list|)
condition|)
block|{
for|for
control|(
name|int
name|index
init|=
literal|0
init|;
name|index
operator|<
literal|9
condition|;
operator|++
name|index
control|)
name|QCOMPARE
argument_list|(
name|readdata
index|[
name|index
index|]
argument_list|,
name|data
index|[
name|index
index|]
argument_list|)
expr_stmt|;
block|}
name|buffer
operator|.
name|release
argument_list|()
expr_stmt|;
comment|// Delete the first context.
operator|delete
name|w1
expr_stmt|;
comment|// Make the second context current again because deleting the first
comment|// one will call doneCurrent() even though it wasn't current!
name|w2
operator|->
name|makeCurrent
argument_list|()
expr_stmt|;
comment|// The buffer should still be valid in the second context.
name|QVERIFY
argument_list|(
name|buffer
operator|.
name|bufferId
argument_list|()
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|buffer
operator|.
name|isCreated
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|buffer
operator|.
name|bind
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|buffer
operator|.
name|size
argument_list|()
argument_list|,
name|int
argument_list|(
sizeof|sizeof
argument_list|(
name|data
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|buffer
operator|.
name|release
argument_list|()
expr_stmt|;
comment|// Delete the second context.
operator|delete
name|w2
expr_stmt|;
comment|// The buffer should now be invalid.
name|QVERIFY
argument_list|(
name|buffer
operator|.
name|bufferId
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|buffer
operator|.
name|isCreated
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QGLBuffer
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qglbuffer.moc"
end_include
end_unit
