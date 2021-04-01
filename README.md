# Compact NTFS

Utility to compress files with original NTFS compression or one of new EXE methods (XPress4K, XPress8K, XPress16K or LZX).

![](https://raw.githubusercontent.com/martin-kudlicka/compact-ntfs/master/web/mainwindow.png)

## Description
Compression is applied to all (except excluded) files in specified directories. When file is already compressed with desired method it is skipped.
Original NTFS compression is set by IO control *FSCTL_SET_COMPRESSION* call. EXE compression is set by IO control *FSCTL_SET_EXTERNAL_BACKING* call.

## Usage
`CompactNTFS.exe`

## Requirements
* Windows Vista (only original NTFS compression will work) or Windows 10 (for additional EXE methods)
* [Visual C++ Redistributable for Visual Studio 2019](https://support.microsoft.com/en-us/help/2977003/the-latest-supported-visual-c-downloads)

## Components
* [Qt](https://www.qt.io/)
