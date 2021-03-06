begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"dialog.h"
end_include
begin_include
include|#
directive|include
file|<QFileDialog>
end_include
begin_include
include|#
directive|include
file|<QBuffer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_comment
comment|/*!   \class Dialog    \brief This class is a simple example of how to use QSharedMemory.    It is a simple dialog that presents a few buttons. To compile the   example, run make in qt/examples/ipc. Then run the executable twice   to create two processes running the dialog. In one of the processes,   press the button to load an image into a shared memory segment, and   then select an image file to load. Once the first process has loaded   and displayed the image, in the second process, press the button to   read the same image from shared memory. The second process displays   the same image loaded from its new loaction in shared memory. */
end_comment
begin_comment
comment|/*!   The class contains a data member \l {QSharedMemory} {sharedMemory},   which is initialized with the key "QSharedMemoryExample" to force   all instances of Dialog to access the same shared memory segment.   The constructor also connects the clicked() signal from each of the   three dialog buttons to the slot function appropriate for handling   each button. */
end_comment
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|Dialog
name|Dialog
operator|::
name|Dialog
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDialog
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|sharedMemory
argument_list|(
literal|"QSharedMemoryExample"
argument_list|)
block|{
name|ui
operator|.
name|setupUi
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ui
operator|.
name|loadFromFileButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|loadFromFile
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ui
operator|.
name|loadFromSharedMemoryButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|loadFromMemory
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"SharedMemory Example"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|/*!   This slot function is called when the \tt {Load Image From File...}   button is pressed on the firs Dialog process. First, it tests   whether the process is already connected to a shared memory segment   and, if so, detaches from that segment. This ensures that we always   start the example from the beginning if we run it multiple times   with the same two Dialog processes. After detaching from an existing   shared memory segment, the user is prompted to select an image file.   The selected file is loaded into a QImage. The QImage is displayed   in the Dialog and streamed into a QBuffer with a QDataStream.    Next, it gets a new shared memory segment from the system big enough   to hold the image data in the QBuffer, and it locks the segment to   prevent the second Dialog process from accessing it. Then it copies   the image from the QBuffer into the shared memory segment. Finally,   it unlocks the shared memory segment so the second Dialog process   can access it.    After this function runs, the user is expected to press the \tt   {Load Image from Shared Memory} button on the second Dialog process.    \sa loadFromMemory()  */
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|loadFromFile
name|void
name|Dialog
operator|::
name|loadFromFile
parameter_list|()
block|{
if|if
condition|(
name|sharedMemory
operator|.
name|isAttached
argument_list|()
condition|)
name|detach
argument_list|()
expr_stmt|;
name|ui
operator|.
name|label
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Select an image file"
argument_list|)
argument_list|)
expr_stmt|;
name|QString
name|fileName
init|=
name|QFileDialog
operator|::
name|getOpenFileName
argument_list|(
literal|0
argument_list|,
name|QString
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|,
name|tr
argument_list|(
literal|"Images (*.png *.xpm *.jpg)"
argument_list|)
argument_list|)
decl_stmt|;
name|QImage
name|image
decl_stmt|;
if|if
condition|(
operator|!
name|image
operator|.
name|load
argument_list|(
name|fileName
argument_list|)
condition|)
block|{
name|ui
operator|.
name|label
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Selected file is not an image, please select another."
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|ui
operator|.
name|label
operator|->
name|setPixmap
argument_list|(
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|image
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [1] //! [2]
comment|// load into shared memory
name|QBuffer
name|buffer
decl_stmt|;
name|buffer
operator|.
name|open
argument_list|(
name|QBuffer
operator|::
name|ReadWrite
argument_list|)
expr_stmt|;
name|QDataStream
name|out
argument_list|(
operator|&
name|buffer
argument_list|)
decl_stmt|;
name|out
operator|<<
name|image
expr_stmt|;
name|int
name|size
init|=
name|buffer
operator|.
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|sharedMemory
operator|.
name|create
argument_list|(
name|size
argument_list|)
condition|)
block|{
name|ui
operator|.
name|label
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Unable to create shared memory segment."
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|sharedMemory
operator|.
name|lock
argument_list|()
expr_stmt|;
name|char
modifier|*
name|to
init|=
operator|(
name|char
operator|*
operator|)
name|sharedMemory
operator|.
name|data
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
name|from
init|=
name|buffer
operator|.
name|data
argument_list|()
operator|.
name|data
argument_list|()
decl_stmt|;
name|memcpy
argument_list|(
name|to
argument_list|,
name|from
argument_list|,
name|qMin
argument_list|(
name|sharedMemory
operator|.
name|size
argument_list|()
argument_list|,
name|size
argument_list|)
argument_list|)
expr_stmt|;
name|sharedMemory
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|/*!   This slot function is called in the second Dialog process, when the   user presses the \tt {Load Image from Shared Memory} button. First,   it attaches the process to the shared memory segment created by the   first Dialog process. Then it locks the segment for exclusive   access, copies the image data from the segment into a QBuffer, and   streams the QBuffer into a QImage. Then it unlocks the shared memory   segment, detaches from it, and finally displays the QImage in the   Dialog.    \sa loadFromFile()  */
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|loadFromMemory
name|void
name|Dialog
operator|::
name|loadFromMemory
parameter_list|()
block|{
if|if
condition|(
operator|!
name|sharedMemory
operator|.
name|attach
argument_list|()
condition|)
block|{
name|ui
operator|.
name|label
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Unable to attach to shared memory segment.\n"
expr|\
literal|"Load an image first."
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|QBuffer
name|buffer
decl_stmt|;
name|QDataStream
name|in
argument_list|(
operator|&
name|buffer
argument_list|)
decl_stmt|;
name|QImage
name|image
decl_stmt|;
name|sharedMemory
operator|.
name|lock
argument_list|()
expr_stmt|;
name|buffer
operator|.
name|setData
argument_list|(
operator|(
name|char
operator|*
operator|)
name|sharedMemory
operator|.
name|constData
argument_list|()
argument_list|,
name|sharedMemory
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|buffer
operator|.
name|open
argument_list|(
name|QBuffer
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|in
operator|>>
name|image
expr_stmt|;
name|sharedMemory
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|sharedMemory
operator|.
name|detach
argument_list|()
expr_stmt|;
name|ui
operator|.
name|label
operator|->
name|setPixmap
argument_list|(
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|image
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|/*!   This private function is called by the destructor to detach the   process from its shared memory segment. When the last process   detaches from a shared memory segment, the system releases the   shared memory.  */
end_comment
begin_function
DECL|function|detach
name|void
name|Dialog
operator|::
name|detach
parameter_list|()
block|{
if|if
condition|(
operator|!
name|sharedMemory
operator|.
name|detach
argument_list|()
condition|)
name|ui
operator|.
name|label
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Unable to detach from shared memory."
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
