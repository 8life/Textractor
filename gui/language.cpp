/*  Copyright (C) 2010-2012  kaosu (qiupf2000@gmail.com)
 *  This file is part of the Interactive Text Hooker.

 *  Interactive Text Hooker is free software: you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License as published
 *  by the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.

 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.

 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
const wchar_t* Warning = L"���!";
//command.cpp
const wchar_t* ErrorSyntax = L"��ɾ� ����";
const wchar_t* Usage = L"��ɾ�:\r\n\
\r\n\
���� //������ ����մϴ�\r\n\
��� ���� // '���'�����忡�� '����'������� �����մϴ�\r\n\
����� // '���'�����忡 ����� ��ũ�� �����մϴ�\r\n\
\r\n\
'���'�� '����'���� 16����(����ڵ�) �������ȣ�� �Է��մϴ�. ������ ��ȣ�� �� �տ� �ִ� ù ��° ���ڿ��Դϴ�.\r\n\
\r\n\
�δ� �ɼ�:\r\n\
/P[{process_id|Nprocess_name}] //���μ����� ����\r\n\
\r\n\
H�ڵ� ��ŷ �ɼ�:\r\n\
/H[X]{A|B|W|S|Q}[N][data_offset[*drdo]][:sub_offset[*drso]]@addr[:module[:{name|#ordinal}]]\r\n\
\r\n\
(������ ������) /H�ڵ��� ��� ���ڴ� �ƹ��͵� ó������ ���� 16����(����ڵ�)�Դϴ�";

const wchar_t* ExtendedUsage = L"/H[X]{A|B|W|S|Q}[N][data_offset[*drdo]][:sub_offset[*drso]]@addr[:[module[:{name|#ordinal}]]]\r\n\
\r\n\
�߰� ��������� ��ŷ����\r\n\
\r\n\
��ŷ ���� :\r\n\
A - DBCS ����\r\n\
B - DBCS ����(big-endian)\r\n\
W - UCS2 ����\r\n\
S - MBCS ���ڿ�\r\n\
Q - UTF-16 ���ڿ�\r\n\
\r\n\
�Ű�����:\r\n\
X - �ϵ���� ��ȹ�� ���\r\n\
N - ������ ������� ����\r\n\
data_offset - stack offset to char / string pointer\r\n\
drdo - add a level of indirection to data_offset\r\n\
sub_offset - stack offset to subcontext\r\n\
drso - add a level of indirection to sub_offset\r\n\
addr - ��ŷ�� �ּ�\r\n\
module - name of the module to use as base for 'addr'\r\n\
name - name of the 'module' export to use as base for 'addr'\r\n\
ordinal - number of the 'module' export ordinal to use as base for 'addr'\r\n\
\r\n\
Negative values of 'data_offset' and 'sub_offset' refer to registers: \r\n\
- 4 for EAX, -8 for ECX, -C for EDX, -10 for EBX, -14 for ESP, -18 for EBP, -1C for ESI, -20 for EDI\r\n\
\r\n\
\"Add a level of indirection\" means in C/C++ style: (*(ESP+data_offset)+drdo) instead of (ESP+data_offset)\r\n\
\r\n\
All numbers except ordinal are hexadecimal without any prefixes";

//inject.cpp
const wchar_t* ErrorRemoteThread = L"���� �����带 ������ �� ����.";
const wchar_t* ErrorOpenProcess = L"���μ����� �� �� ����.";
const wchar_t* ErrorNoProcess = L"���μ����� ã�� �� ����";
const wchar_t* SelfAttach = L"ITH.exe�� �������� ���� �ּ���";
const wchar_t* AlreadyAttach = L"���μ����� �̹� ������.";
const wchar_t* FormatInject = L"���μ��� %d�� ������. ��� ��� %.8X";
//main.cpp
const wchar_t* NotAdmin = L"SeDebugPrevilege�� Ȱ��ȭ �� �� �����ϴ�. ITH�� ����� �۵����� ���մϴ�.\r\n\
������ �������� �����Ͻðų� UAC�� ���ð� ITH�� ������ �ּ���.";
//pipe.cpp
const wchar_t* ErrorCreatePipe = L"�ؽ�Ʈ �������� ������ �� ���ų�, ��û�� �ʹ� �����ϴ�.";
const wchar_t* FormatDetach = L"���μ��� %d�� Ż����.";
const wchar_t* ErrorCmdQueueFull = L"��ɾ� ��⿭�� ������.";
const wchar_t* ErrorNoAttach = L"���μ����� �������� ����.";

//profile.cpp
const wchar_t* ErrorMonitor = L"���μ����� ������ �� ����.";
//utility.cpp
const wchar_t* InitMessage = L"Copyright (C) 2010-2012  kaosu <qiupf2000@gmail.com>\r\n\
Copyright (C) 2015 zorkzero <zorkzero@hotmail.com>\r\n\
�ҽ��ڵ� <https://code.google.com/p/interactive-text-hooker/>\r\n\
�Ϲ���� <https://groups.google.com/forum/?fromgroups#!forum/interactive-text-hooker>\r\n\
�ѱ�ȭ @mireado<https://twitter.com/mireado>";
const wchar_t* BackgroundMsg = L"������ ���÷���, \"help\", \"����\"�̳� \"����\"�� �Է��ϼ���.";
const wchar_t* ErrorLinkExist = L"������ ������.";
const wchar_t* ErrorCylicLink = L"�������. ��ȯ������ ������ �ʽ��ϴ�.";
const wchar_t* FormatLink = L"��߽�����%.4x���� ����������%.4x�� ����.";
const wchar_t* ErrorLink = L"�������. ���/���� �����带 ã�� �� ����.";
const wchar_t* ErrorDeleteCombo = L"�ۻ��ڿ��� ����� ����.";

//window.cpp
const wchar_t* ClassName = L"ITH";
const wchar_t* ClassNameAdmin = L"ITH (������)";
const wchar_t* ErrorNotSplit = L"���� ���� �����⸦ Ȱ��ȭ���ּ���!";
const wchar_t* ErrorNotModule = L"���� ����� Ȱ��ȭ���ּ���!";
//Main window buttons
const wchar_t* ButtonTitleProcess = L"���μ���";
const wchar_t* ButtonTitleThread = L"������";
const wchar_t* ButtonTitleHook = L"��ŷ";
const wchar_t* ButtonTitleProfile = L"������";
const wchar_t* ButtonTitleOption = L"�ɼ�";
const wchar_t* ButtonTitleClear = L"�����";
const wchar_t* ButtonTitleSave = L"����";
const wchar_t* ButtonTitleTop = L"�׻���";
//Hook window
const wchar_t* SpecialHook = L"H�ڵ� ��ŷ, AGTH �ڵ�� �������� �ʽ��ϴ�.";
//Process window
const wchar_t* TabTitlePID = L"PID";
const wchar_t* TabTitleMemory = L"�޸�";
const wchar_t* TabTitleName = L"�̸�";
const wchar_t* TabTitleTID = L"TID";
const wchar_t* TabTitleStart = L"����";
const wchar_t* TabTitleModule = L"���";
const wchar_t* TabTitleState = L"����";
const wchar_t* SuccessAttach = L"���μ����� ITH ��������.";
const wchar_t* FailAttach = L"���μ����� ITH ��������.";
const wchar_t* SuccessDetach = L"���μ������� ITH Ż������.";
const wchar_t* FailDetach = L"ITH Ż������.";
//Profile window
const wchar_t* ProfileExist = L"�������� �̹� ������.";
const wchar_t* SuccessAddProfile = L"������ �߰���.";
const wchar_t* FailAddProfile = L"������ �߰�����";
const wchar_t* TabTitleNumber = L"No.";
const wchar_t* NoFile = L"������ ã�� �� ����.";
const wchar_t* PathDismatch = L"���μ��� �̸��� ��ġ���� �ʽ��ϴ�, ����Ͻðڽ��ϱ�?";
const wchar_t* SuccessImportProfile = L"������ �������� ����";
//const wchar_t* SuccessAddProfile=L"Profile added.";