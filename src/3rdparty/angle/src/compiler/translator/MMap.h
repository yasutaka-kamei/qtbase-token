begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2010 The ANGLE Project Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_TRANSLATOR_MMAP_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_MMAP_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_MMAP_H_
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|// Encapsulate memory mapped files
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|TMMap
block|{
name|public
label|:
name|TMMap
argument_list|(
specifier|const
name|char
operator|*
name|fileName
argument_list|)
operator|:
name|fSize
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
comment|// -1 is the error value returned by GetFileSize()
name|fp
argument_list|(
name|NULL
argument_list|)
operator|,
name|fBuff
argument_list|(
literal|0
argument_list|)
comment|// 0 is the error value returned by MapViewOfFile()
block|{
if|if
condition|(
operator|(
name|fp
operator|=
name|fopen
argument_list|(
name|fileName
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return;
name|char
name|c
operator|=
name|getc
argument_list|(
name|fp
argument_list|)
expr_stmt|;
name|fSize
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|c
operator|!=
name|EOF
condition|)
block|{
name|fSize
operator|++
expr_stmt|;
name|c
operator|=
name|getc
argument_list|(
name|fp
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|c
operator|==
name|EOF
condition|)
name|fSize
operator|++
expr_stmt|;
name|rewind
argument_list|(
name|fp
argument_list|)
expr_stmt|;
name|fBuff
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|char
argument_list|)
operator|*
name|fSize
argument_list|)
expr_stmt|;
name|int
name|count
init|=
literal|0
decl_stmt|;
name|c
operator|=
name|getc
argument_list|(
name|fp
argument_list|)
expr_stmt|;
while|while
condition|(
name|c
operator|!=
name|EOF
condition|)
block|{
name|fBuff
index|[
name|count
operator|++
index|]
operator|=
name|c
expr_stmt|;
name|c
operator|=
name|getc
argument_list|(
name|fp
argument_list|)
expr_stmt|;
block|}
name|fBuff
index|[
name|count
operator|++
index|]
operator|=
name|c
expr_stmt|;
block|}
end_decl_stmt
begin_function
name|char
modifier|*
name|getData
parameter_list|()
block|{
return|return
name|fBuff
return|;
block|}
end_function
begin_function
name|int
name|getSize
parameter_list|()
block|{
return|return
name|fSize
return|;
block|}
end_function
begin_expr_stmt
operator|~
name|TMMap
argument_list|()
block|{
if|if
condition|(
name|fp
operator|!=
name|NULL
condition|)
name|fclose
argument_list|(
name|fp
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|int
name|fSize
decl_stmt|;
end_decl_stmt
begin_comment
comment|// size of file to map in
end_comment
begin_decl_stmt
name|FILE
modifier|*
name|fp
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|char
modifier|*
name|fBuff
decl_stmt|;
end_decl_stmt
begin_comment
comment|// the actual data;
end_comment
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_MMAP_H_
end_comment
end_unit
