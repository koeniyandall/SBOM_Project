
void Default_Handler(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}




void main(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 local_10;
  int iStack_c;
  
  iStack_c = 0;
  pbVar3 = DAT_08000060;
  do {
    bVar1 = (byte)iStack_c;
    iStack_c = iStack_c + 1;
    *pbVar3 = bVar1 & 0xf;
    pbVar3 = pbVar3 + 1;
  } while (iStack_c != 0x100);
  local_10 = 0x200;
  compress(DAT_08000064,&local_10,DAT_08000060,0x100);
  uncompress(DAT_08000068,&iStack_c,DAT_08000064,local_10);
  iVar2 = memcmp(DAT_08000060,DAT_08000068,0x100);
  *DAT_0800006c = (uint)(iVar2 == 0);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}




uint Reset_Handler(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte *extraout_r1;
  byte *pbVar9;
  uint uVar10;
  size_t __n;
  size_t n;
  uint extraout_r2;
  byte *pbVar11;
  uint uVar12;
  uint uVar13;
  int unaff_r4;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  
  __n = (DAT_080000ac + 3) - (int)DAT_080000b0 & 0xfffffffc;
  if (DAT_080000ac < (int)DAT_080000b0 - 3U) {
    __n = 0;
  }
  memcpy(DAT_080000b0,DAT_080000b4,__n);
  n = (DAT_080000b8 + 3) - (int)DAT_080000bc & 0xfffffffc;
  if (DAT_080000b8 < (int)DAT_080000bc - 3U) {
    n = 0;
  }
  memset(DAT_080000bc,0,n);
  main();
  *(undefined4 *)(unaff_r4 + 0x44) = 0;
  uVar13 = 0;
  uVar1 = 0;
  if (extraout_r2 == 1) {
    uVar1 = (uint)*extraout_r1;
    if (0xfff0 < uVar1) {
      uVar1 = uVar1 - 0xfff1;
    }
    uVar13 = uVar1;
    if (0xfff0 < uVar1) {
      uVar13 = uVar1 - 0xfff1;
    }
  }
  else {
    if (extraout_r1 == (byte *)0x0) {
      return 1;
    }
    pbVar9 = extraout_r1;
    uVar10 = extraout_r2;
    if (extraout_r2 < 0x10) {
      for (; pbVar9 != extraout_r1 + extraout_r2; pbVar9 = pbVar9 + 1) {
        uVar1 = uVar1 + *pbVar9;
        uVar13 = uVar13 + uVar1;
      }
      if (0xfff0 < uVar1) {
        uVar1 = uVar1 - 0xfff1;
      }
      uVar10 = 0xfff1;
      uVar12 = uVar13 / 0xfff1;
    }
    else {
      while (0x15af < uVar10) {
        uVar10 = uVar10 - 0x15b0;
        pbVar11 = pbVar9 + 0x10;
        do {
          iVar14 = pbVar11[-0x10] + uVar1;
          iVar19 = (uint)pbVar11[-0xf] + iVar14;
          iVar18 = (uint)pbVar11[-0xe] + iVar19;
          iVar2 = (uint)pbVar11[-0xd] + iVar18;
          iVar3 = (uint)pbVar11[-0xc] + iVar2;
          iVar4 = (uint)pbVar11[-0xb] + iVar3;
          iVar5 = (uint)pbVar11[-10] + iVar4;
          iVar6 = (uint)pbVar11[-9] + iVar5;
          iVar7 = (uint)pbVar11[-8] + iVar6;
          iVar8 = (uint)pbVar11[-7] + iVar7;
          iVar17 = (uint)pbVar11[-6] + iVar8;
          iVar16 = (uint)pbVar11[-5] + iVar17;
          iVar21 = (uint)pbVar11[-4] + iVar16;
          iVar20 = (uint)pbVar11[-3] + iVar21;
          iVar15 = (uint)pbVar11[-2] + iVar20;
          uVar1 = (uint)pbVar11[-1] + iVar15;
          uVar13 = uVar13 + iVar14 + iVar19 + iVar18 + iVar2 + iVar3 + iVar4 + iVar5 + iVar6 + iVar7
                            + iVar8 + iVar17 + iVar16 + iVar21 + iVar20 + iVar15 + uVar1;
          pbVar11 = pbVar11 + 0x10;
        } while (pbVar9 + 0x15c0 != pbVar11);
        pbVar9 = pbVar9 + 0x15b0;
        uVar1 = uVar1 % 0xfff1;
        uVar13 = uVar13 % 0xfff1;
      }
      if (uVar10 == 0) goto LAB_080000ee;
      pbVar11 = pbVar9;
      for (uVar12 = uVar10; 0xf < uVar12; uVar12 = uVar12 - 0x10) {
        iVar14 = *pbVar11 + uVar1;
        iVar2 = (uint)pbVar11[1] + iVar14;
        iVar15 = (uint)pbVar11[2] + iVar2;
        iVar3 = (uint)pbVar11[3] + iVar15;
        iVar16 = (uint)pbVar11[4] + iVar3;
        iVar4 = (uint)pbVar11[5] + iVar16;
        iVar17 = (uint)pbVar11[6] + iVar4;
        iVar5 = (uint)pbVar11[7] + iVar17;
        iVar18 = (uint)pbVar11[8] + iVar5;
        iVar6 = (uint)pbVar11[9] + iVar18;
        iVar19 = (uint)pbVar11[10] + iVar6;
        iVar7 = (uint)pbVar11[0xb] + iVar19;
        iVar20 = (uint)pbVar11[0xc] + iVar7;
        iVar8 = (uint)pbVar11[0xd] + iVar20;
        iVar21 = (uint)pbVar11[0xe] + iVar8;
        uVar1 = (uint)pbVar11[0xf] + iVar21;
        uVar13 = uVar13 + iVar14 + iVar2 + iVar15 + iVar3 + iVar16 + iVar4 + iVar17 + iVar5 + iVar18
                 + iVar6 + iVar19 + iVar7 + iVar20 + iVar8 + iVar21 + uVar1;
        pbVar11 = pbVar11 + 0x10;
      }
      pbVar9 = pbVar9 + (uVar10 & 0xfffffff0);
      pbVar11 = pbVar9 + (uVar10 & 0xf);
      for (; pbVar9 != pbVar11; pbVar9 = pbVar9 + 1) {
        uVar1 = uVar1 + *pbVar9;
        uVar13 = uVar13 + uVar1;
      }
      uVar12 = 0xfff1;
      uVar1 = uVar1 % 0xfff1;
      uVar10 = uVar13 / 0xfff1;
    }
    uVar13 = uVar13 - uVar12 * uVar10;
  }
LAB_080000ee:
  return uVar1 | uVar13 << 0x10;
}




uint adler32_z(uint param_1,byte *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  
  uVar11 = param_1 >> 0x10;
  param_1 = param_1 & 0xffff;
  if (param_3 == 1) {
    param_1 = param_1 + *param_2;
    if (0xfff0 < param_1) {
      param_1 = param_1 - 0xfff1;
    }
    uVar11 = uVar11 + param_1;
    if (0xfff0 < uVar11) {
      uVar11 = uVar11 - 0xfff1;
    }
  }
  else {
    if (param_2 == (byte *)0x0) {
      return 1;
    }
    if (param_3 < 0x10) {
      pbVar9 = param_2 + param_3;
      for (; param_2 != pbVar9; param_2 = param_2 + 1) {
        param_1 = param_1 + *param_2;
        uVar11 = uVar11 + param_1;
      }
      if (0xfff0 < param_1) {
        param_1 = param_1 - 0xfff1;
      }
      uVar8 = 0xfff1;
      uVar10 = uVar11 / 0xfff1;
    }
    else {
      while (0x15af < param_3) {
        param_3 = param_3 - 0x15b0;
        pbVar9 = param_2 + 0x10;
        do {
          iVar12 = pbVar9[-0x10] + param_1;
          iVar17 = (uint)pbVar9[-0xf] + iVar12;
          iVar16 = (uint)pbVar9[-0xe] + iVar17;
          iVar1 = (uint)pbVar9[-0xd] + iVar16;
          iVar2 = (uint)pbVar9[-0xc] + iVar1;
          iVar3 = (uint)pbVar9[-0xb] + iVar2;
          iVar4 = (uint)pbVar9[-10] + iVar3;
          iVar5 = (uint)pbVar9[-9] + iVar4;
          iVar6 = (uint)pbVar9[-8] + iVar5;
          iVar7 = (uint)pbVar9[-7] + iVar6;
          iVar15 = (uint)pbVar9[-6] + iVar7;
          iVar14 = (uint)pbVar9[-5] + iVar15;
          iVar19 = (uint)pbVar9[-4] + iVar14;
          iVar18 = (uint)pbVar9[-3] + iVar19;
          iVar13 = (uint)pbVar9[-2] + iVar18;
          param_1 = (uint)pbVar9[-1] + iVar13;
          uVar11 = uVar11 + iVar12 + iVar17 + iVar16 + iVar1 + iVar2 + iVar3 + iVar4 + iVar5 + iVar6
                            + iVar7 + iVar15 + iVar14 + iVar19 + iVar18 + iVar13 + param_1;
          pbVar9 = pbVar9 + 0x10;
        } while (param_2 + 0x15c0 != pbVar9);
        param_2 = param_2 + 0x15b0;
        param_1 = param_1 % 0xfff1;
        uVar11 = uVar11 % 0xfff1;
      }
      if (param_3 == 0) goto LAB_080000ee;
      pbVar9 = param_2;
      for (uVar8 = param_3; 0xf < uVar8; uVar8 = uVar8 - 0x10) {
        iVar12 = *pbVar9 + param_1;
        iVar1 = (uint)pbVar9[1] + iVar12;
        iVar13 = (uint)pbVar9[2] + iVar1;
        iVar2 = (uint)pbVar9[3] + iVar13;
        iVar14 = (uint)pbVar9[4] + iVar2;
        iVar3 = (uint)pbVar9[5] + iVar14;
        iVar15 = (uint)pbVar9[6] + iVar3;
        iVar4 = (uint)pbVar9[7] + iVar15;
        iVar16 = (uint)pbVar9[8] + iVar4;
        iVar5 = (uint)pbVar9[9] + iVar16;
        iVar17 = (uint)pbVar9[10] + iVar5;
        iVar6 = (uint)pbVar9[0xb] + iVar17;
        iVar18 = (uint)pbVar9[0xc] + iVar6;
        iVar7 = (uint)pbVar9[0xd] + iVar18;
        iVar19 = (uint)pbVar9[0xe] + iVar7;
        param_1 = (uint)pbVar9[0xf] + iVar19;
        uVar11 = uVar11 + iVar12 + iVar1 + iVar13 + iVar2 + iVar14 + iVar3 + iVar15 + iVar4 + iVar16
                 + iVar5 + iVar17 + iVar6 + iVar18 + iVar7 + iVar19 + param_1;
        pbVar9 = pbVar9 + 0x10;
      }
      param_2 = param_2 + (param_3 & 0xfffffff0);
      pbVar9 = param_2 + (param_3 & 0xf);
      for (; param_2 != pbVar9; param_2 = param_2 + 1) {
        param_1 = param_1 + *param_2;
        uVar11 = uVar11 + param_1;
      }
      uVar10 = 0xfff1;
      param_1 = param_1 % 0xfff1;
      uVar8 = uVar11 / 0xfff1;
    }
    uVar11 = uVar11 - uVar10 * uVar8;
  }
LAB_080000ee:
  return param_1 | uVar11 << 0x10;
}




uint adler32(uint param_1,byte *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  
  uVar11 = param_1 >> 0x10;
  param_1 = param_1 & 0xffff;
  if (param_3 == 1) {
    param_1 = param_1 + *param_2;
    if (0xfff0 < param_1) {
      param_1 = param_1 - 0xfff1;
    }
    uVar11 = uVar11 + param_1;
    if (0xfff0 < uVar11) {
      uVar11 = uVar11 - 0xfff1;
    }
  }
  else {
    if (param_2 == (byte *)0x0) {
      return 1;
    }
    if (param_3 < 0x10) {
      pbVar9 = param_2 + param_3;
      for (; param_2 != pbVar9; param_2 = param_2 + 1) {
        param_1 = param_1 + *param_2;
        uVar11 = uVar11 + param_1;
      }
      if (0xfff0 < param_1) {
        param_1 = param_1 - 0xfff1;
      }
      uVar8 = 0xfff1;
      uVar10 = uVar11 / 0xfff1;
    }
    else {
      while (0x15af < param_3) {
        param_3 = param_3 - 0x15b0;
        pbVar9 = param_2 + 0x10;
        do {
          iVar12 = pbVar9[-0x10] + param_1;
          iVar17 = (uint)pbVar9[-0xf] + iVar12;
          iVar16 = (uint)pbVar9[-0xe] + iVar17;
          iVar1 = (uint)pbVar9[-0xd] + iVar16;
          iVar2 = (uint)pbVar9[-0xc] + iVar1;
          iVar3 = (uint)pbVar9[-0xb] + iVar2;
          iVar4 = (uint)pbVar9[-10] + iVar3;
          iVar5 = (uint)pbVar9[-9] + iVar4;
          iVar6 = (uint)pbVar9[-8] + iVar5;
          iVar7 = (uint)pbVar9[-7] + iVar6;
          iVar15 = (uint)pbVar9[-6] + iVar7;
          iVar14 = (uint)pbVar9[-5] + iVar15;
          iVar19 = (uint)pbVar9[-4] + iVar14;
          iVar18 = (uint)pbVar9[-3] + iVar19;
          iVar13 = (uint)pbVar9[-2] + iVar18;
          param_1 = (uint)pbVar9[-1] + iVar13;
          uVar11 = uVar11 + iVar12 + iVar17 + iVar16 + iVar1 + iVar2 + iVar3 + iVar4 + iVar5 + iVar6
                            + iVar7 + iVar15 + iVar14 + iVar19 + iVar18 + iVar13 + param_1;
          pbVar9 = pbVar9 + 0x10;
        } while (param_2 + 0x15c0 != pbVar9);
        param_2 = param_2 + 0x15b0;
        param_1 = param_1 % 0xfff1;
        uVar11 = uVar11 % 0xfff1;
      }
      if (param_3 == 0) goto LAB_080000ee;
      pbVar9 = param_2;
      for (uVar8 = param_3; 0xf < uVar8; uVar8 = uVar8 - 0x10) {
        iVar12 = *pbVar9 + param_1;
        iVar1 = (uint)pbVar9[1] + iVar12;
        iVar13 = (uint)pbVar9[2] + iVar1;
        iVar2 = (uint)pbVar9[3] + iVar13;
        iVar14 = (uint)pbVar9[4] + iVar2;
        iVar3 = (uint)pbVar9[5] + iVar14;
        iVar15 = (uint)pbVar9[6] + iVar3;
        iVar4 = (uint)pbVar9[7] + iVar15;
        iVar16 = (uint)pbVar9[8] + iVar4;
        iVar5 = (uint)pbVar9[9] + iVar16;
        iVar17 = (uint)pbVar9[10] + iVar5;
        iVar6 = (uint)pbVar9[0xb] + iVar17;
        iVar18 = (uint)pbVar9[0xc] + iVar6;
        iVar7 = (uint)pbVar9[0xd] + iVar18;
        iVar19 = (uint)pbVar9[0xe] + iVar7;
        param_1 = (uint)pbVar9[0xf] + iVar19;
        uVar11 = uVar11 + iVar12 + iVar1 + iVar13 + iVar2 + iVar14 + iVar3 + iVar15 + iVar4 + iVar16
                 + iVar5 + iVar17 + iVar6 + iVar18 + iVar7 + iVar19 + param_1;
        pbVar9 = pbVar9 + 0x10;
      }
      param_2 = param_2 + (param_3 & 0xfffffff0);
      pbVar9 = param_2 + (param_3 & 0xf);
      for (; param_2 != pbVar9; param_2 = param_2 + 1) {
        param_1 = param_1 + *param_2;
        uVar11 = uVar11 + param_1;
      }
      uVar10 = 0xfff1;
      param_1 = param_1 % 0xfff1;
      uVar8 = uVar11 / 0xfff1;
    }
    uVar11 = uVar11 - uVar10 * uVar8;
  }
LAB_080000ee:
  return param_1 | uVar11 << 0x10;
}




int compress2(undefined4 param_1,int *param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_58;
  int local_54;
  undefined4 local_4c;
  int local_48;
  int local_44;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  
  iVar3 = *param_2;
  local_30 = 0;
  *param_2 = 0;
  local_38 = 0;
  uStack_34 = 0;
  iVar1 = deflateInit_(&local_58,param_5,DAT_08000364,0x38);
  if (iVar1 == 0) {
    local_54 = 0;
    local_48 = 0;
    local_58 = param_3;
    local_4c = param_1;
    do {
      iVar4 = iVar3;
      if (local_48 == 0) {
        iVar4 = local_48;
        local_48 = iVar3;
      }
      if (local_54 == 0) {
        iVar2 = 4;
        iVar3 = local_54;
        local_54 = param_4;
      }
      else {
        iVar2 = (uint)(param_4 == 0) << 2;
        iVar3 = param_4;
      }
      iVar2 = deflate(&local_58,iVar2);
      param_4 = iVar3;
      iVar3 = iVar4;
    } while (iVar2 == 0);
    *param_2 = local_44;
    deflateEnd(&local_58);
    if (iVar2 != 1) {
      iVar1 = iVar2;
    }
  }
  return iVar1;
}




void compress(void)

{
  compress2();
  return;
}




uint crc32_z(uint param_1,byte *param_2,uint param_3)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_2 == (byte *)0x0) {
    param_1 = 0;
  }
  else {
    param_1 = ~param_1;
    pbVar1 = param_2;
    for (uVar2 = param_3; 7 < uVar2; uVar2 = uVar2 - 8) {
      uVar3 = *(uint *)(DAT_0800043c + ((*pbVar1 ^ param_1) & 0xff) * 4) ^ param_1 >> 8;
      uVar3 = *(uint *)(DAT_0800043c + ((pbVar1[1] ^ uVar3) & 0xff) * 4) ^ uVar3 >> 8;
      uVar3 = *(uint *)(DAT_0800043c + ((pbVar1[2] ^ uVar3) & 0xff) * 4) ^ uVar3 >> 8;
      uVar3 = *(uint *)(DAT_0800043c + ((pbVar1[3] ^ uVar3) & 0xff) * 4) ^ uVar3 >> 8;
      uVar3 = *(uint *)(DAT_0800043c + ((pbVar1[4] ^ uVar3) & 0xff) * 4) ^ uVar3 >> 8;
      uVar3 = *(uint *)(DAT_0800043c + ((pbVar1[5] ^ uVar3) & 0xff) * 4) ^ uVar3 >> 8;
      uVar3 = *(uint *)(DAT_0800043c + ((pbVar1[6] ^ uVar3) & 0xff) * 4) ^ uVar3 >> 8;
      param_1 = *(uint *)(DAT_0800043c + ((pbVar1[7] ^ uVar3) & 0xff) * 4) ^ uVar3 >> 8;
      pbVar1 = pbVar1 + 8;
    }
    for (pbVar1 = param_2 + (param_3 & 0xfffffff8); pbVar1 != param_2 + param_3; pbVar1 = pbVar1 + 1
        ) {
      param_1 = *(uint *)(DAT_0800043c + ((*pbVar1 ^ param_1) & 0xff) * 4) ^ param_1 >> 8;
    }
    param_1 = ~param_1;
  }
  return param_1;
}




uint crc32(uint param_1,byte *param_2,uint param_3)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_2 == (byte *)0x0) {
    param_1 = 0;
  }
  else {
    param_1 = ~param_1;
    pbVar1 = param_2;
    for (uVar2 = param_3; 7 < uVar2; uVar2 = uVar2 - 8) {
      uVar3 = *(uint *)(DAT_0800043c + ((*pbVar1 ^ param_1) & 0xff) * 4) ^ param_1 >> 8;
      uVar3 = *(uint *)(DAT_0800043c + ((pbVar1[1] ^ uVar3) & 0xff) * 4) ^ uVar3 >> 8;
      uVar3 = *(uint *)(DAT_0800043c + ((pbVar1[2] ^ uVar3) & 0xff) * 4) ^ uVar3 >> 8;
      uVar3 = *(uint *)(DAT_0800043c + ((pbVar1[3] ^ uVar3) & 0xff) * 4) ^ uVar3 >> 8;
      uVar3 = *(uint *)(DAT_0800043c + ((pbVar1[4] ^ uVar3) & 0xff) * 4) ^ uVar3 >> 8;
      uVar3 = *(uint *)(DAT_0800043c + ((pbVar1[5] ^ uVar3) & 0xff) * 4) ^ uVar3 >> 8;
      uVar3 = *(uint *)(DAT_0800043c + ((pbVar1[6] ^ uVar3) & 0xff) * 4) ^ uVar3 >> 8;
      param_1 = *(uint *)(DAT_0800043c + ((pbVar1[7] ^ uVar3) & 0xff) * 4) ^ uVar3 >> 8;
      pbVar1 = pbVar1 + 8;
    }
    for (pbVar1 = param_2 + (param_3 & 0xfffffff8); pbVar1 != param_2 + param_3; pbVar1 = pbVar1 + 1
        ) {
      param_1 = *(uint *)(DAT_0800043c + ((*pbVar1 ^ param_1) & 0xff) * 4) ^ param_1 >> 8;
    }
    param_1 = ~param_1;
  }
  return param_1;
}




void slide_hash(int param_1)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  ushort uVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x4c);
  uVar3 = *(uint *)(param_1 + 0x2c);
  puVar2 = (ushort *)(*(int *)(param_1 + 0x44) + iVar5 * 2);
  do {
    puVar2 = puVar2 + -1;
    if (*puVar2 < uVar3) {
      uVar4 = 0;
    }
    else {
      uVar4 = *puVar2 - (short)uVar3;
    }
    iVar5 = iVar5 + -1;
    *puVar2 = uVar4;
  } while (iVar5 != 0);
  puVar2 = (ushort *)(*(int *)(param_1 + 0x40) + uVar3 * 2);
  uVar1 = uVar3;
  do {
    puVar2 = puVar2 + -1;
    if (*puVar2 < uVar3) {
      uVar4 = 0;
    }
    else {
      uVar4 = *puVar2 - (short)uVar3;
    }
    uVar1 = uVar1 - 1;
    *puVar2 = uVar4;
  } while (uVar1 != 0);
  return;
}




void putShortMSB(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x14);
  *(int *)(param_1 + 0x14) = iVar1 + 1;
  *(char *)(*(int *)(param_1 + 8) + iVar1) = (char)((uint)param_2 >> 8);
  iVar1 = *(int *)(param_1 + 0x14);
  *(int *)(param_1 + 0x14) = iVar1 + 1;
  *(char *)(*(int *)(param_1 + 8) + iVar1) = (char)param_2;
  return;
}




uint longest_match(int param_1,uint param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  uint uVar10;
  char cVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  
  uVar7 = *(uint *)(param_1 + 0x6c);
  iVar14 = *(int *)(param_1 + 0x38);
  uVar2 = *(uint *)(param_1 + 0x78);
  uVar10 = *(uint *)(param_1 + 0x7c);
  uVar12 = *(int *)(param_1 + 0x2c) - 0x106;
  uVar13 = uVar12;
  if (uVar12 < uVar7) {
    uVar13 = (uVar7 + 0x106) - *(int *)(param_1 + 0x2c);
  }
  pcVar9 = (char *)(iVar14 + uVar7);
  if (uVar7 <= uVar12) {
    uVar13 = 0;
  }
  cVar11 = pcVar9[uVar2 - 1];
  cVar1 = pcVar9[uVar2];
  uVar12 = *(uint *)(param_1 + 0x74);
  if (*(uint *)(param_1 + 0x8c) <= uVar2) {
    uVar10 = uVar10 >> 2;
  }
  pcVar8 = (char *)(uVar7 + 0x102 + iVar14);
  uVar7 = *(uint *)(param_1 + 0x90);
  if (uVar12 <= *(uint *)(param_1 + 0x90)) {
    uVar7 = uVar12;
  }
  do {
    pcVar3 = (char *)(iVar14 + param_2);
    if ((((pcVar3[uVar2] == cVar1) && (pcVar3[uVar2 - 1] == cVar11)) && (*pcVar3 == *pcVar9)) &&
       (pcVar3[1] == pcVar9[1])) {
      pcVar5 = pcVar9 + 2;
      pcVar3 = pcVar3 + 2;
      while( true ) {
        if (pcVar5[1] != pcVar3[1]) {
          pcVar5 = pcVar5 + 1;
          goto LAB_08000548;
        }
        if (pcVar5[2] != pcVar3[2]) break;
        if (pcVar5[3] != pcVar3[3]) {
          pcVar5 = pcVar5 + 3;
          goto LAB_08000548;
        }
        if (pcVar5[4] != pcVar3[4]) {
          pcVar5 = pcVar5 + 4;
          goto LAB_08000548;
        }
        if (pcVar5[5] != pcVar3[5]) {
          pcVar5 = pcVar5 + 5;
          goto LAB_08000548;
        }
        if (pcVar5[6] != pcVar3[6]) {
          pcVar5 = pcVar5 + 6;
          goto LAB_08000548;
        }
        if (pcVar5[7] != pcVar3[7]) {
          pcVar5 = pcVar5 + 7;
          goto LAB_08000548;
        }
        pcVar5 = pcVar5 + 8;
        if ((*pcVar5 != pcVar3[8]) || (pcVar3 = pcVar3 + 8, pcVar8 <= pcVar5)) goto LAB_08000548;
      }
      pcVar5 = pcVar5 + 2;
LAB_08000548:
      iVar6 = (int)pcVar8 - (int)pcVar5;
      uVar4 = 0x102 - iVar6;
      if ((int)uVar2 < (int)uVar4) {
        *(uint *)(param_1 + 0x70) = param_2;
        if ((int)uVar7 <= (int)uVar4) break;
        cVar11 = pcVar9[0x101 - iVar6];
        cVar1 = pcVar9[uVar4];
        uVar2 = uVar4;
      }
    }
    uVar4 = uVar2;
    param_2 = (uint)*(ushort *)
                     (*(int *)(param_1 + 0x40) + (param_2 & *(uint *)(param_1 + 0x34)) * 2);
    if (param_2 <= uVar13) break;
    uVar10 = uVar10 - 1;
    uVar2 = uVar4;
  } while (uVar10 != 0);
  if (uVar12 <= uVar4) {
    uVar4 = uVar12;
  }
  return uVar4;
}




uint read_buf(int *param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_1[1];
  if (uVar2 <= param_3) {
    param_3 = uVar2;
  }
  if (param_3 == 0) {
    return 0;
  }
  param_1[1] = uVar2 - param_3;
  zmemcpy(param_2,*param_1);
  if (*(int *)(param_1[7] + 0x18) == 1) {
    iVar1 = adler32(param_1[0xc],param_2,param_3);
  }
  else {
    if (*(int *)(param_1[7] + 0x18) != 2) goto LAB_08000628;
    iVar1 = crc32(param_1[0xc],param_2,param_3);
  }
  param_1[0xc] = iVar1;
LAB_08000628:
  *param_1 = *param_1 + param_3;
  param_1[2] = param_1[2] + param_3;
  return param_3;
}




void fill_window(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  
  iVar6 = param_1[0xb];
  while( true ) {
    uVar3 = param_1[0x1b];
    iVar8 = param_1[0xf] - (param_1[0x1d] + uVar3);
    if ((param_1[0xb] + iVar6) - 0x106U <= uVar3) {
      iVar5 = param_1[0x1d] + iVar6;
      zmemcpy(param_1[0xe],param_1[0xe] + iVar6,(uVar3 + iVar5) - param_1[0xf],iVar5,param_4);
      param_1[0x1c] = param_1[0x1c] - iVar6;
      param_1[0x17] = param_1[0x17] - iVar6;
      uVar3 = param_1[0x1b] - iVar6;
      param_1[0x1b] = uVar3;
      if (uVar3 < (uint)param_1[0x5ad]) {
        param_1[0x5ad] = uVar3;
      }
      slide_hash(param_1);
      iVar8 = iVar8 + iVar6;
    }
    if (*(int *)(*param_1 + 4) == 0) break;
    iVar8 = read_buf(*param_1,param_1[0x1b] + param_1[0x1d] + param_1[0xe],iVar8);
    uVar3 = iVar8 + param_1[0x1d];
    param_1[0x1d] = uVar3;
    if (2 < uVar3 + param_1[0x5ad]) {
      iVar8 = param_1[0xe];
      uVar9 = param_1[0x1b] - param_1[0x5ad];
      uVar7 = param_1[0x15];
      uVar11 = param_1[0x16];
      bVar1 = *(byte *)(iVar8 + uVar9);
      param_1[0x12] = (uint)bVar1;
      param_1[0x12] = ((uint)*(byte *)(iVar8 + uVar9 + 1) ^ (uint)bVar1 << (uVar11 & 0xff)) & uVar7;
      do {
        if (param_1[0x5ad] == 0) break;
        iVar10 = param_1[0x11];
        uVar4 = (param_1[0x12] << (uVar11 & 0xff) ^ (uint)*(byte *)(iVar8 + 2 + uVar9)) & uVar7;
        uVar2 = *(undefined2 *)(iVar10 + uVar4 * 2);
        param_1[0x12] = uVar4;
        iVar5 = param_1[0x5ad] + -1;
        *(undefined2 *)(param_1[0x10] + (param_1[0xd] & uVar9) * 2) = uVar2;
        *(short *)(iVar10 + uVar4 * 2) = (short)uVar9;
        param_1[0x5ad] = iVar5;
        uVar9 = uVar9 + 1;
      } while (2 < iVar5 + uVar3);
    }
    if ((0x105 < uVar3) || (*(int *)(*param_1 + 4) == 0)) break;
  }
  uVar3 = param_1[0x5b0];
  uVar9 = param_1[0xf];
  if (uVar3 < uVar9) {
    uVar7 = param_1[0x1b] + param_1[0x1d];
    if (uVar3 < uVar7) {
      uVar9 = uVar9 - uVar7;
      if (0x101 < uVar9) {
        uVar9 = 0x102;
      }
      zmemzero(param_1[0xe] + uVar7,uVar9);
      param_1[0x5b0] = uVar9 + uVar7;
    }
    else if (uVar3 < uVar7 + 0x102) {
      uVar7 = (uVar7 - uVar3) + 0x102;
      if (uVar9 - uVar3 <= uVar7) {
        uVar7 = uVar9 - uVar3;
      }
      zmemzero(param_1[0xe] + uVar3,uVar7);
      param_1[0x5b0] = param_1[0x5b0] + uVar7;
    }
  }
  return;
}




void flush_pending(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(param_1 + 0x1c);
  _tr_flush_bits(iVar2);
  uVar3 = *(uint *)(param_1 + 0x10);
  if (*(uint *)(iVar2 + 0x14) <= *(uint *)(param_1 + 0x10)) {
    uVar3 = *(uint *)(iVar2 + 0x14);
  }
  if (uVar3 != 0) {
    zmemcpy(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(iVar2 + 0x10),uVar3);
    *(uint *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + uVar3;
    *(uint *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + uVar3;
    *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + uVar3;
    *(uint *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) - uVar3;
    iVar1 = *(int *)(iVar2 + 0x14) - uVar3;
    *(int *)(iVar2 + 0x14) = iVar1;
    if (iVar1 == 0) {
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar2 + 8);
    }
  }
  return;
}




bool deflate_slow(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  
  iVar3 = DAT_080009dc;
LAB_080007fc:
  do {
    if ((uint)param_1[0x1d] < 0x106) {
      fill_window(param_1);
      if ((uint)param_1[0x1d] < 0x106) {
        if (param_2 == 0) {
          return false;
        }
        if (param_1[0x1d] == 0) {
          if (param_1[0x1a] != 0) {
            iVar3 = param_1[0x5a8];
            bVar1 = *(byte *)(param_1[0xe] + param_1[0x1b] + -1);
            param_1[0x5a8] = iVar3 + 1;
            *(undefined1 *)(param_1[0x5a6] + iVar3) = 0;
            iVar3 = param_1[0x5a8];
            param_1[0x5a8] = iVar3 + 1;
            *(undefined1 *)(param_1[0x5a6] + iVar3) = 0;
            iVar3 = param_1[0x5a8];
            param_1[0x5a8] = iVar3 + 1;
            *(byte *)(param_1[0x5a6] + iVar3) = bVar1;
            *(short *)(param_1 + bVar1 + 0x25) = (short)param_1[bVar1 + 0x25] + 1;
            param_1[0x1a] = 0;
          }
          uVar11 = param_1[0x1b];
          uVar8 = uVar11;
          if (1 < uVar11) {
            uVar8 = 2;
          }
          param_1[0x5ad] = uVar8;
          if (param_2 == 4) {
            iVar3 = param_1[0x17];
            if (iVar3 < 0) {
              iVar12 = 0;
            }
            else {
              iVar12 = param_1[0xe] + iVar3;
            }
            _tr_flush_block(param_1,iVar12,uVar11 - iVar3,1);
            param_1[0x17] = param_1[0x1b];
            flush_pending(*param_1);
            if (*(int *)(*param_1 + 0x10) == 0) {
              return (bool)2;
            }
            return (bool)3;
          }
          if (param_1[0x5a8] == 0) {
            return true;
          }
          iVar3 = param_1[0x17];
          if (iVar3 < 0) {
            iVar12 = 0;
          }
          else {
            iVar12 = param_1[0xe] + iVar3;
          }
          _tr_flush_block(param_1,iVar12,uVar11 - iVar3,0);
          param_1[0x17] = param_1[0x1b];
          flush_pending(*param_1);
          return *(int *)(*param_1 + 0x10) != 0;
        }
      }
    }
    uVar11 = param_1[0x1d];
    uVar8 = param_1[0x1b];
    if (uVar11 < 3) {
      uVar4 = 0;
    }
    else {
      iVar12 = param_1[0x11];
      uVar10 = ((uint)*(byte *)(param_1[0xe] + uVar8 + 2) ^ param_1[0x12] << (param_1[0x16] & 0xffU)
               ) & param_1[0x15];
      uVar2 = *(ushort *)(iVar12 + uVar10 * 2);
      uVar4 = (uint)uVar2;
      param_1[0x12] = uVar10;
      *(ushort *)(param_1[0x10] + (param_1[0xd] & uVar8) * 2) = uVar2;
      *(short *)(iVar12 + uVar10 * 2) = (short)uVar8;
    }
    uVar10 = param_1[0x18];
    iVar12 = param_1[0x1c];
    param_1[0x1e] = uVar10;
    param_1[0x19] = iVar12;
    param_1[0x18] = 2;
    if (((uVar4 == 0) || ((uint)param_1[0x20] <= uVar10)) || (param_1[0xb] - 0x106U < uVar8 - uVar4)
       ) {
LAB_08000868:
      if (uVar10 < 3) goto LAB_08000870;
LAB_080009ee:
      iVar6 = param_1[0x5a8];
      uVar9 = uVar8 - iVar12 & 0xffff;
      param_1[0x5a8] = iVar6 + 1;
      uVar4 = uVar9 - 1 & 0xffff;
      *(char *)(param_1[0x5a6] + iVar6) = (char)uVar4;
      iVar12 = param_1[0x5a8];
      param_1[0x5a8] = iVar12 + 1;
      *(char *)(param_1[0x5a6] + iVar12) = (char)(uVar4 >> 8);
      iVar12 = param_1[0x5a8];
      param_1[0x5a8] = iVar12 + 1;
      *(char *)(param_1[0x5a6] + iVar12) = (char)(uVar10 - 3);
      bVar1 = *(byte *)(iVar3 + (uVar10 - 3 & 0xff));
      *(short *)(param_1 + bVar1 + 0x126) = (short)param_1[bVar1 + 0x126] + 1;
      uVar4 = uVar9 - 2 & 0xffff;
      if (uVar4 < 0x100) {
        bVar1 = *(byte *)(DAT_08000b54 + uVar4);
      }
      else {
        bVar1 = *(byte *)(DAT_08000b54 + (uVar4 >> 7) + 0x100);
      }
      *(short *)(param_1 + bVar1 + 0x262) = (short)param_1[bVar1 + 0x262] + 1;
      iVar6 = param_1[0x5a8];
      iVar12 = param_1[0x5a9];
      param_1[0x1d] = (param_1[0x1d] + 1) - param_1[0x1e];
      param_1[0x1e] = param_1[0x1e] + -2;
      do {
        iVar7 = param_1[0x1b];
        uVar4 = iVar7 + 1;
        param_1[0x1b] = uVar4;
        if (uVar4 <= (uVar11 + uVar8) - 3) {
          uVar10 = ((uint)*(byte *)(param_1[0xe] + iVar7 + 3) ^
                   param_1[0x12] << (param_1[0x16] & 0xffU)) & param_1[0x15];
          iVar5 = param_1[0x11];
          param_1[0x12] = uVar10;
          *(undefined2 *)(param_1[0x10] + (uVar4 & param_1[0xd]) * 2) =
               *(undefined2 *)(iVar5 + uVar10 * 2);
          *(short *)(iVar5 + uVar10 * 2) = (short)uVar4;
        }
        iVar5 = param_1[0x1e];
        param_1[0x1e] = iVar5 + -1;
      } while (iVar5 + -1 != 0);
      param_1[0x1a] = 0;
      param_1[0x18] = 2;
      param_1[0x1b] = iVar7 + 2;
      if (iVar6 != iVar12) goto LAB_080007fc;
      iVar6 = param_1[0x17];
      iVar12 = 0;
      if (-1 < iVar6) {
        iVar12 = param_1[0xe] + iVar6;
      }
      _tr_flush_block(param_1,iVar12,(iVar7 + 2) - iVar6,0,param_4);
      param_1[0x17] = param_1[0x1b];
      flush_pending(*param_1);
    }
    else {
      uVar4 = longest_match(param_1);
      param_1[0x18] = uVar4;
      if (uVar4 < 6) {
        if (param_1[0x22] != 1) {
          if (uVar4 != 3) goto LAB_080009e0;
          if (uVar8 - param_1[0x1c] < 0x1001) goto LAB_08000868;
        }
        param_1[0x18] = 2;
        goto LAB_08000868;
      }
LAB_080009e0:
      if ((2 < uVar10) && (uVar4 <= uVar10)) goto LAB_080009ee;
LAB_08000870:
      if (param_1[0x1a] == 0) {
        param_1[0x1a] = 1;
        param_1[0x1b] = uVar8 + 1;
        param_1[0x1d] = uVar11 - 1;
        goto LAB_080007fc;
      }
      iVar6 = param_1[0x5a8];
      bVar1 = *(byte *)(param_1[0xe] + uVar8 + -1);
      param_1[0x5a8] = iVar6 + 1;
      iVar12 = 0;
      *(undefined1 *)(param_1[0x5a6] + iVar6) = 0;
      iVar6 = param_1[0x5a8];
      param_1[0x5a8] = iVar6 + 1;
      *(undefined1 *)(param_1[0x5a6] + iVar6) = 0;
      iVar6 = param_1[0x5a8];
      param_1[0x5a8] = iVar6 + 1;
      *(byte *)(param_1[0x5a6] + iVar6) = bVar1;
      *(short *)(param_1 + bVar1 + 0x25) = (short)param_1[bVar1 + 0x25] + 1;
      if (param_1[0x5a8] == param_1[0x5a9]) {
        iVar6 = param_1[0x17];
        if (-1 < iVar6) {
          iVar12 = param_1[0xe] + iVar6;
        }
        _tr_flush_block(param_1,iVar12,param_1[0x1b] - iVar6,0,param_4);
        param_1[0x17] = param_1[0x1b];
        flush_pending(*param_1);
      }
      param_1[0x1b] = param_1[0x1b] + 1;
      param_1[0x1d] = param_1[0x1d] + -1;
    }
    if (*(int *)(*param_1 + 0x10) == 0) {
      return false;
    }
  } while( true );
}




bool deflate_fast(int *param_1,int *param_2,undefined4 param_3)

{
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  int *piVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  bool bVar16;
  
  piVar8 = param_1;
  piVar9 = param_2;
  do {
    if ((uint)param_1[0x1d] < 0x106) {
      fill_window(param_1);
      uVar5 = param_1[0x1d];
      if (0x105 < uVar5) goto LAB_08000b8e;
      if (param_2 == (int *)0x0) {
        return false;
      }
      if (uVar5 == 0) {
        uVar7 = param_1[0x1b];
        uVar5 = uVar7;
        if (1 < uVar7) {
          uVar5 = 2;
        }
        param_1[0x5ad] = uVar5;
        if (param_2 != (int *)0x4) {
          if (param_1[0x5a8] == 0) {
            return true;
          }
          iVar6 = param_1[0x17];
          iVar12 = 0;
          if (-1 < iVar6) {
            iVar12 = param_1[0xe];
          }
          if (-1 < iVar6) {
            iVar12 = iVar12 + iVar6;
          }
          _tr_flush_block(param_1,iVar12,uVar7 - iVar6,0);
          param_1[0x17] = param_1[0x1b];
          flush_pending(*param_1);
          return *(int *)(*param_1 + 0x10) != 0;
        }
        iVar6 = param_1[0x17];
        iVar12 = 0;
        if (-1 < iVar6) {
          iVar12 = param_1[0xe];
        }
        if (-1 < iVar6) {
          iVar12 = iVar12 + iVar6;
        }
        _tr_flush_block(param_1,iVar12,uVar7 - iVar6,1);
        param_1[0x17] = param_1[0x1b];
        flush_pending(*param_1);
        if (*(int *)(*param_1 + 0x10) == 0) {
          return (bool)2;
        }
        return (bool)3;
      }
      if (2 < uVar5) goto LAB_08000b8e;
    }
    else {
LAB_08000b8e:
      uVar5 = param_1[0x1b];
      iVar12 = param_1[0x11];
      uVar7 = ((uint)*(byte *)(param_1[0xe] + uVar5 + 2) ^ param_1[0x12] << (param_1[0x16] & 0xffU))
              & param_1[0x15];
      uVar2 = *(ushort *)(iVar12 + uVar7 * 2);
      param_1[0x12] = uVar7;
      *(ushort *)(param_1[0x10] + (param_1[0xd] & uVar5) * 2) = uVar2;
      *(short *)(iVar12 + uVar7 * 2) = (short)uVar5;
      if ((uVar2 != 0) && (uVar5 - uVar2 <= param_1[0xb] - 0x106U)) {
        iVar12 = longest_match(param_1);
        param_1[0x18] = iVar12;
      }
    }
    iVar12 = param_1[0x5a8];
    if ((uint)param_1[0x18] < 3) {
      bVar1 = *(byte *)(param_1[0xe] + param_1[0x1b]);
      param_1[0x5a8] = iVar12 + 1;
      *(undefined1 *)(param_1[0x5a6] + iVar12) = 0;
      iVar12 = param_1[0x5a8];
      param_1[0x5a8] = iVar12 + 1;
      *(undefined1 *)(param_1[0x5a6] + iVar12) = 0;
      iVar12 = param_1[0x5a8];
      param_1[0x5a8] = iVar12 + 1;
      *(byte *)(param_1[0x5a6] + iVar12) = bVar1;
      *(short *)(param_1 + bVar1 + 0x25) = (short)param_1[bVar1 + 0x25] + 1;
      param_1[0x1d] = param_1[0x1d] + -1;
      param_1[0x1b] = param_1[0x1b] + 1;
      bVar16 = param_1[0x5a8] == param_1[0x5a9];
    }
    else {
      uVar5 = param_1[0x18] - 3;
      param_1[0x5a8] = iVar12 + 1;
      uVar7 = param_1[0x1b] - param_1[0x1c] & 0xffff;
      *(char *)(param_1[0x5a6] + iVar12) = (char)uVar7;
      iVar12 = DAT_08000de0;
      iVar6 = param_1[0x5a8];
      param_1[0x5a8] = iVar6 + 1;
      *(char *)(param_1[0x5a6] + iVar6) = (char)(uVar7 >> 8);
      iVar6 = param_1[0x5a8];
      bVar1 = *(byte *)(iVar12 + (uVar5 & 0xff));
      param_1[0x5a8] = iVar6 + 1;
      *(char *)(param_1[0x5a6] + iVar6) = (char)uVar5;
      *(short *)(param_1 + bVar1 + 0x126) = (short)param_1[bVar1 + 0x126] + 1;
      uVar5 = uVar7 - 1 & 0xffff;
      if (uVar5 < 0x100) {
        bVar1 = *(byte *)(DAT_08000de4 + uVar5);
      }
      else {
        bVar1 = *(byte *)(DAT_08000de4 + (uVar5 >> 7) + 0x100);
      }
      *(short *)(param_1 + bVar1 + 0x262) = (short)param_1[bVar1 + 0x262] + 1;
      piVar8 = (int *)param_1[0x5a8];
      piVar9 = (int *)param_1[0x5a9];
      uVar5 = param_1[0x18];
      iVar12 = param_1[0x1d];
      iVar6 = param_1[0xe];
      uVar7 = param_1[0x15];
      uVar15 = param_1[0x16];
      param_1[0x1d] = iVar12 - uVar5;
      if (((uint)param_1[0x20] < uVar5) || (iVar12 - uVar5 < 3)) {
        iVar12 = uVar5 + param_1[0x1b];
        param_1[0x1b] = iVar12;
        param_1[0x18] = 0;
        bVar1 = *(byte *)(iVar6 + iVar12);
        param_1[0x12] = (uint)bVar1;
        param_1[0x12] =
             ((uint)*(byte *)(iVar6 + iVar12 + 1) ^ (uint)bVar1 << (uVar15 & 0xff)) & uVar7;
      }
      else {
        iVar13 = param_1[0x10];
        iVar12 = param_1[0x11];
        uVar14 = param_1[0xd];
        param_1[0x18] = uVar5 - 1;
        do {
          iVar4 = param_1[0x1b];
          uVar5 = iVar4 + 1;
          param_1[0x1b] = uVar5;
          uVar10 = ((uint)*(byte *)(iVar6 + iVar4 + 3) ^ param_1[0x12] << (uVar15 & 0xff)) & uVar7;
          uVar3 = *(undefined2 *)(iVar12 + uVar10 * 2);
          param_1[0x12] = uVar10;
          *(undefined2 *)(iVar13 + (uVar5 & uVar14) * 2) = uVar3;
          *(short *)(iVar12 + uVar10 * 2) = (short)uVar5;
          iVar11 = param_1[0x18];
          param_1[0x18] = iVar11 + -1;
        } while (iVar11 + -1 != 0);
        param_1[0x1b] = iVar4 + 2;
      }
      bVar16 = piVar8 == piVar9;
    }
    if (bVar16) {
      iVar12 = param_1[0x17];
      if (iVar12 < 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = param_1[0xe] + iVar12;
      }
      _tr_flush_block(param_1,iVar6,param_1[0x1b] - iVar12,0,piVar8,piVar9,param_3);
      param_1[0x17] = param_1[0x1b];
      flush_pending(*param_1);
      if (*(int *)(*param_1 + 0x10) == 0) {
        return false;
      }
    }
  } while( true );
}




int deflate_stored(int *param_1,uint param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  int *piVar11;
  
  uVar7 = param_1[3] - 5U;
  if ((uint)param_1[0xb] <= param_1[3] - 5U) {
    uVar7 = param_1[0xb];
  }
  iVar9 = *(int *)(*param_1 + 4);
  piVar11 = param_1;
  do {
    uVar3 = *(uint *)(*param_1 + 0x10);
    uVar5 = param_1[0x5af] + 0x2a >> 3;
    if (uVar3 < uVar5) {
LAB_0800102e:
      bVar10 = false;
      goto LAB_08000e54;
    }
    uVar6 = param_1[0x1b] - param_1[0x17];
    uVar4 = *(int *)(*param_1 + 4) + uVar6;
    uVar3 = uVar3 - uVar5;
    uVar5 = uVar4;
    if (0xfffe < uVar4) {
      uVar5 = 0xffff;
    }
    if (uVar3 <= uVar5) {
      uVar5 = uVar3;
    }
    if (uVar5 < uVar7) {
      if (uVar5 != 0) {
        if ((param_2 == 0) || (uVar4 != uVar5)) goto LAB_0800102e;
        goto LAB_08000f74;
      }
      bVar10 = false;
      if ((param_2 != 4) || (uVar4 != 0)) goto LAB_08000e54;
LAB_08000f7a:
      bVar10 = uVar4 == uVar5;
    }
    else {
LAB_08000f74:
      if (param_2 == 4) goto LAB_08000f7a;
      bVar10 = false;
    }
    _tr_stored_block(param_1,0,0,bVar10,piVar11,uVar7,param_3);
    *(byte *)(param_1[2] + param_1[5] + -4) = (byte)uVar5;
    bVar1 = (byte)(uVar5 >> 8);
    *(byte *)(param_1[2] + param_1[5] + -3) = bVar1;
    *(byte *)(param_1[2] + param_1[5] + -2) = ~(byte)uVar5;
    *(byte *)(param_1[2] + param_1[5] + -1) = ~bVar1;
    flush_pending(*param_1);
    if (uVar6 != 0) {
      if (uVar5 <= uVar6) {
        uVar6 = uVar5;
      }
      zmemcpy(*(undefined4 *)(*param_1 + 0xc),param_1[0x17] + param_1[0xe],uVar6);
      iVar8 = *param_1;
      *(uint *)(iVar8 + 0xc) = *(int *)(iVar8 + 0xc) + uVar6;
      *(uint *)(iVar8 + 0x10) = *(int *)(iVar8 + 0x10) - uVar6;
      *(uint *)(iVar8 + 0x14) = *(int *)(iVar8 + 0x14) + uVar6;
      param_1[0x17] = param_1[0x17] + uVar6;
      uVar5 = uVar5 - uVar6;
    }
    if (uVar5 != 0) {
      read_buf(*param_1,*(undefined4 *)(*param_1 + 0xc),uVar5);
      iVar8 = *param_1;
      *(uint *)(iVar8 + 0xc) = *(int *)(iVar8 + 0xc) + uVar5;
      *(uint *)(iVar8 + 0x10) = *(int *)(iVar8 + 0x10) - uVar5;
      *(uint *)(iVar8 + 0x14) = *(int *)(iVar8 + 0x14) + uVar5;
    }
  } while (bVar10 == false);
  bVar10 = true;
LAB_08000e54:
  iVar8 = ((int *)*param_1)[1];
  uVar7 = iVar9 - iVar8;
  if (uVar7 != 0) {
    uVar5 = param_1[0xb];
    iVar2 = param_1[0xe];
    if (uVar7 < uVar5) {
      if ((uint)(param_1[0xf] - param_1[0x1b]) <= uVar7) {
        param_1[0x1b] = param_1[0x1b] - uVar5;
        zmemcpy(iVar2,iVar2 + uVar5);
        if ((uint)param_1[0x5ac] < 2) {
          param_1[0x5ac] = param_1[0x5ac] + 1;
        }
        if ((uint)param_1[0x1b] < (uint)param_1[0x5ad]) {
          param_1[0x5ad] = param_1[0x1b];
        }
      }
      zmemcpy(param_1[0xe] + param_1[0x1b],*(int *)*param_1 + (iVar8 - iVar9),uVar7);
      param_1[0x1b] = param_1[0x1b] + uVar7;
      uVar5 = param_1[0xb] - param_1[0x5ad];
      if (uVar7 < uVar5) {
        uVar5 = uVar7;
      }
      iVar9 = param_1[0x5ad] + uVar5;
    }
    else {
      param_1[0x5ac] = 2;
      zmemcpy(iVar2,*(int *)*param_1 - uVar5,uVar5);
      iVar9 = param_1[0xb];
      param_1[0x1b] = iVar9;
    }
    param_1[0x5ad] = iVar9;
    param_1[0x17] = param_1[0x1b];
  }
  uVar7 = param_1[0x1b];
  if ((uint)param_1[0x5b0] < uVar7) {
    param_1[0x5b0] = uVar7;
  }
  if (bVar10) {
    return 3;
  }
  if ((((param_2 & 0xfffffffb) != 0) && (*(uint *)(*param_1 + 4) == 0)) && (uVar7 == param_1[0x17]))
  {
    return 1;
  }
  uVar5 = param_1[0xf] - uVar7;
  if (uVar5 < *(uint *)(*param_1 + 4)) {
    iVar9 = param_1[0xb];
    if (iVar9 <= param_1[0x17]) {
      param_1[0x17] = param_1[0x17] - iVar9;
      param_1[0x1b] = uVar7 - iVar9;
      zmemcpy(param_1[0xe],iVar9 + param_1[0xe]);
      if ((uint)param_1[0x5ac] < 2) {
        param_1[0x5ac] = param_1[0x5ac] + 1;
      }
      if ((uint)param_1[0x1b] < (uint)param_1[0x5ad]) {
        param_1[0x5ad] = param_1[0x1b];
      }
      uVar5 = uVar5 + param_1[0xb];
    }
  }
  uVar7 = *(uint *)(*param_1 + 4);
  if (uVar7 <= uVar5) {
    uVar5 = uVar7;
  }
  if (uVar5 != 0) {
    read_buf(*param_1,param_1[0xe] + param_1[0x1b],uVar5);
    param_1[0x1b] = param_1[0x1b] + uVar5;
    uVar7 = param_1[0xb] - param_1[0x5ad];
    if (uVar5 < uVar7) {
      uVar7 = uVar5;
    }
    param_1[0x5ad] = param_1[0x5ad] + uVar7;
  }
  uVar7 = param_1[0x1b];
  if ((uint)param_1[0x5b0] < uVar7) {
    param_1[0x5b0] = uVar7;
  }
  uVar5 = param_1[3] - (param_1[0x5af] + 0x2a >> 3);
  if (0xfffe < uVar5) {
    uVar5 = 0xffff;
  }
  uVar7 = uVar7 - param_1[0x17];
  uVar3 = param_1[0xb];
  if (uVar5 <= (uint)param_1[0xb]) {
    uVar3 = uVar5;
  }
  if (uVar7 < uVar3) {
    if (uVar7 == 0) {
      if (param_2 == 4) {
LAB_08001098:
        if (*(int *)(*param_1 + 4) == 0) {
          if (uVar5 < uVar7) {
            return 0;
          }
          goto LAB_080010a6;
        }
      }
    }
    else if (param_2 != 0) goto LAB_08001098;
    iVar9 = 0;
  }
  else {
LAB_080010a6:
    uVar3 = uVar5;
    if (uVar7 <= uVar5) {
      uVar3 = uVar7;
    }
    if ((param_2 == 4) && (*(int *)(*param_1 + 4) == 0)) {
      if (uVar5 < uVar7) {
        iVar9 = 0;
      }
      else {
        iVar9 = 1;
      }
    }
    else {
      iVar9 = 0;
    }
    _tr_stored_block(param_1,param_1[0x17] + param_1[0xe],uVar3,iVar9);
    param_1[0x17] = param_1[0x17] + uVar3;
    flush_pending(*param_1);
    iVar9 = iVar9 << 1;
  }
  return iVar9;
}




uint deflateStateCheck(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if ((((param_1 != 0) && (*(int *)(param_1 + 0x20) != 0)) && (*(int *)(param_1 + 0x24) != 0)) &&
     ((piVar2 = *(int **)(param_1 + 0x1c), piVar2 != (int *)0x0 && (param_1 == *piVar2)))) {
    iVar1 = piVar2[1];
    if (0x71 < iVar1) {
      return (uint)(iVar1 != 0x29a);
    }
    if (0x5a < iVar1) {
      return DAT_08001154 >> (iVar1 - 0x5bU & 0xff) & 1 ^ 1;
    }
    if (iVar1 == 0x2a) {
      return 0;
    }
    if (iVar1 - 0x39U < 0x11) {
      return DAT_08001158 >> (iVar1 - 0x39U & 0xff) & 1 ^ 1;
    }
  }
  return 1;
}




undefined4 deflateResetKeep(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  
  iVar1 = deflateStateCheck();
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x1c);
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 2;
    uVar2 = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(iVar1 + 0x10) = uVar2;
    *(undefined4 *)(iVar1 + 0x14) = 0;
    if (*(int *)(iVar1 + 0x18) < 0) {
      *(int *)(iVar1 + 0x18) = -*(int *)(iVar1 + 0x18);
    }
    bVar3 = *(int *)(iVar1 + 0x18) != 2;
    if (bVar3) {
      uVar2 = 0x2a;
    }
    else {
      uVar2 = 0x39;
    }
    *(undefined4 *)(iVar1 + 4) = uVar2;
    if (bVar3) {
      uVar2 = adler32(0,0);
    }
    else {
      uVar2 = crc32();
    }
    *(undefined4 *)(param_1 + 0x30) = uVar2;
    *(undefined4 *)(iVar1 + 0x28) = 0xfffffffe;
    _tr_init(iVar1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xfffffffe;
  }
  return uVar2;
}




int deflateReset(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = deflateResetKeep();
  if (iVar1 == 0) {
    iVar5 = *(int *)(param_1 + 0x1c);
    iVar3 = *(int *)(iVar5 + 0x4c);
    iVar2 = *(int *)(iVar5 + 0x44);
    *(int *)(iVar5 + 0x3c) = *(int *)(iVar5 + 0x2c) << 1;
    *(undefined2 *)(iVar2 + (iVar3 + 0x7fffffff) * 2) = 0;
    zmemzero(iVar2,(iVar3 + -1) * 2);
    iVar2 = DAT_08001224;
    *(undefined4 *)(iVar5 + 0x6c) = 0;
    iVar4 = *(int *)(iVar5 + 0x84) * 0xc;
    iVar3 = iVar2 + iVar4;
    *(uint *)(iVar5 + 0x8c) = (uint)*(ushort *)(iVar2 + iVar4);
    *(uint *)(iVar5 + 0x90) = (uint)*(ushort *)(iVar3 + 4);
    *(uint *)(iVar5 + 0x7c) = (uint)*(ushort *)(iVar3 + 6);
    *(uint *)(iVar5 + 0x80) = (uint)*(ushort *)(iVar3 + 2);
    *(undefined4 *)(iVar5 + 0x5c) = 0;
    *(undefined4 *)(iVar5 + 0x74) = 0;
    *(undefined4 *)(iVar5 + 0x16b4) = 0;
    *(undefined4 *)(iVar5 + 0x78) = 2;
    *(undefined4 *)(iVar5 + 0x60) = 2;
    *(undefined4 *)(iVar5 + 0x68) = 0;
    *(undefined4 *)(iVar5 + 0x48) = 0;
  }
  return iVar1;
}




uint deflate(int *param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  char *pcVar10;
  char cVar11;
  int iVar12;
  int extraout_r3;
  char *pcVar13;
  uint uVar14;
  int iVar15;
  int *piVar16;
  int iVar17;
  int *piVar18;
  bool bVar19;
  ulonglong uVar20;
  int *piVar21;
  
  piVar21 = param_1;
  uVar20 = deflateStateCheck();
  iVar15 = (int)(uVar20 >> 0x20);
  if (((int)uVar20 != 0) || (0x5ffffffff < uVar20)) {
    return 0xfffffffe;
  }
  piVar16 = (int *)param_1[7];
  if (((param_1[3] == 0) || ((iVar12 = param_1[1], iVar12 != 0 && (*param_1 == 0)))) ||
     ((piVar16[1] == 0x29a && (iVar15 != 4)))) {
    param_1[6] = *(int *)(DAT_08001350 + 0x10);
    return 0xfffffffe;
  }
  if (param_1[4] == 0) {
LAB_0800126e:
    param_1[6] = *(int *)(DAT_08001350 + 0x1c);
    return 0xfffffffb;
  }
  iVar8 = piVar16[10];
  piVar16[10] = iVar15;
  if (piVar16[5] == 0) {
    if (iVar12 == 0) {
      if (iVar15 == 5) {
        iVar12 = 9;
      }
      else {
        iVar12 = 0;
      }
      if (iVar8 < 5) {
        iVar6 = 0;
      }
      else {
        iVar6 = 9;
      }
      if ((iVar15 * 2 - iVar12 <= iVar8 * 2 - iVar6) && (iVar15 != 4)) goto LAB_0800126e;
    }
  }
  else {
    flush_pending(param_1);
    if (param_1[4] == 0) goto LAB_0800128c;
  }
  if (piVar16[1] == 0x29a) {
    if (param_1[1] != 0) goto LAB_0800126e;
LAB_080012c6:
    iVar12 = piVar16[1];
    if (iVar12 == 0x45) goto LAB_0800144a;
    if (iVar12 == 0x49) goto LAB_080014a8;
    if (iVar12 == 0x5b) goto LAB_0800151c;
    if (iVar12 == 0x67) goto LAB_0800158c;
  }
  else {
    if (piVar16[1] == 0x2a) {
      if (piVar16[6] == 0) {
        piVar16[1] = 0x71;
        goto LAB_080012c6;
      }
      if ((piVar16[0x22] < 2) && (iVar12 = piVar16[0x21], 1 < iVar12)) {
        if (iVar12 < 6) {
          iVar12 = 1;
        }
        else if (iVar12 == 6) {
          iVar12 = 2;
        }
        else {
          iVar12 = 3;
        }
      }
      else {
        iVar12 = 0;
      }
      uVar5 = piVar16[0xc] * 0x1000 - 0x7800U | iVar12 << 6;
      if (piVar16[0x1b] != 0) {
        uVar5 = uVar5 | 0x20;
      }
      uVar7 = putShortMSB(piVar16,(uVar5 / 0x1f) * 0x1f + 0x1f,0x29a,0x1f,piVar21,param_2,param_3);
      if (piVar16[0x1b] != 0) {
        uVar7 = putShortMSB(uVar7,*(undefined2 *)((int)param_1 + 0x32));
        putShortMSB(uVar7,(short)param_1[0xc]);
      }
      iVar12 = adler32(0,0);
      param_1[0xc] = iVar12;
      piVar16[1] = 0x71;
      flush_pending(param_1);
      if (piVar16[5] != 0) goto LAB_0800128c;
    }
    if (piVar16[1] != 0x39) goto LAB_080012c6;
    iVar12 = crc32(0,0);
    iVar6 = piVar16[5];
    iVar8 = piVar16[2];
    param_1[0xc] = iVar12;
    piVar16[5] = iVar6 + 1;
    *(undefined1 *)(iVar8 + iVar6) = 0x1f;
    iVar12 = piVar16[5];
    piVar16[5] = iVar12 + 1;
    *(undefined1 *)(piVar16[2] + iVar12) = 0x8b;
    iVar12 = piVar16[5];
    piVar16[5] = iVar12 + 1;
    *(undefined1 *)(piVar16[2] + iVar12) = 8;
    piVar18 = (int *)piVar16[7];
    iVar12 = piVar16[5];
    if (piVar18 == (int *)0x0) {
      piVar16[5] = iVar12 + 1;
      *(undefined1 *)(piVar16[2] + iVar12) = 0;
      iVar12 = piVar16[5];
      piVar16[5] = iVar12 + 1;
      *(undefined1 *)(piVar16[2] + iVar12) = 0;
      iVar12 = piVar16[5];
      piVar16[5] = iVar12 + 1;
      *(undefined1 *)(piVar16[2] + iVar12) = 0;
      iVar12 = piVar16[5];
      piVar16[5] = iVar12 + 1;
      *(undefined1 *)(piVar16[2] + iVar12) = 0;
      iVar12 = piVar16[5];
      piVar16[5] = iVar12 + 1;
      *(undefined1 *)(piVar16[2] + iVar12) = 0;
      if (piVar16[0x21] == 9) {
        cVar11 = '\x02';
      }
      else if (piVar16[0x22] < 2) {
        cVar11 = (piVar16[0x21] < 2) << 2;
      }
      else {
        cVar11 = '\x04';
      }
      iVar12 = piVar16[5];
      piVar16[5] = iVar12 + 1;
      *(char *)(piVar16[2] + iVar12) = cVar11;
      iVar12 = piVar16[5];
      piVar16[5] = iVar12 + 1;
      *(undefined1 *)(piVar16[2] + iVar12) = 3;
      piVar16[1] = 0x71;
      flush_pending(param_1);
      if (piVar16[5] != 0) goto LAB_0800128c;
      goto LAB_080012c6;
    }
    cVar11 = (piVar18[0xb] != 0) * '\x02' + (piVar18[4] != 0) * '\x04';
    if (*piVar18 != 0) {
      cVar11 = cVar11 + '\x01';
    }
    iVar8 = piVar18[7];
    iVar6 = piVar18[9];
    piVar16[5] = iVar12 + 1;
    *(char *)(piVar16[2] + iVar12) = cVar11 + (iVar8 != 0) * '\b' + (iVar6 != 0) * '\x10';
    uVar7 = *(undefined4 *)(piVar16[7] + 4);
    iVar12 = piVar16[5];
    piVar16[5] = iVar12 + 1;
    *(char *)(piVar16[2] + iVar12) = (char)uVar7;
    iVar12 = piVar16[5];
    uVar7 = *(undefined4 *)(piVar16[7] + 4);
    piVar16[5] = iVar12 + 1;
    *(char *)(piVar16[2] + iVar12) = (char)((uint)uVar7 >> 8);
    uVar2 = *(undefined2 *)(piVar16[7] + 6);
    iVar12 = piVar16[5];
    piVar16[5] = iVar12 + 1;
    *(char *)(piVar16[2] + iVar12) = (char)uVar2;
    uVar3 = *(undefined1 *)(piVar16[7] + 7);
    iVar12 = piVar16[5];
    piVar16[5] = iVar12 + 1;
    *(undefined1 *)(piVar16[2] + iVar12) = uVar3;
    if (piVar16[0x21] == 9) {
      cVar11 = '\x02';
    }
    else if (piVar16[0x22] < 2) {
      cVar11 = (piVar16[0x21] < 2) << 2;
    }
    else {
      cVar11 = '\x04';
    }
    iVar12 = piVar16[5];
    piVar16[5] = iVar12 + 1;
    *(char *)(piVar16[2] + iVar12) = cVar11;
    uVar7 = *(undefined4 *)(piVar16[7] + 0xc);
    iVar12 = piVar16[5];
    piVar16[5] = iVar12 + 1;
    *(char *)(piVar16[2] + iVar12) = (char)uVar7;
    if (*(int *)(piVar16[7] + 0x10) != 0) {
      uVar7 = *(undefined4 *)(piVar16[7] + 0x14);
      iVar12 = piVar16[5];
      piVar16[5] = iVar12 + 1;
      *(char *)(piVar16[2] + iVar12) = (char)uVar7;
      iVar12 = piVar16[5];
      uVar7 = *(undefined4 *)(piVar16[7] + 0x14);
      piVar16[5] = iVar12 + 1;
      *(char *)(piVar16[2] + iVar12) = (char)((uint)uVar7 >> 8);
    }
    if (*(int *)(piVar16[7] + 0x2c) != 0) {
      iVar12 = crc32(param_1[0xc],piVar16[2],piVar16[5]);
      param_1[0xc] = iVar12;
    }
    piVar16[8] = 0;
    piVar16[1] = 0x45;
LAB_0800144a:
    iVar12 = *(int *)(piVar16[7] + 0x10);
    if (iVar12 != 0) {
      uVar5 = piVar16[5];
      iVar8 = (uint)*(ushort *)(piVar16[7] + 0x14) - piVar16[8];
      while( true ) {
        iVar17 = piVar16[5];
        uVar14 = piVar16[3];
        iVar6 = *(int *)(piVar16[7] + 0x10) + piVar16[8];
        if ((uint)(iVar17 + iVar8) <= uVar14) break;
        param_2 = uVar14 - iVar17;
        zmemcpy(piVar16[2] + iVar17,iVar6,param_2,param_2,piVar21,param_2);
        uVar9 = piVar16[3];
        iVar12 = *(int *)(piVar16[7] + 0x2c);
        piVar16[5] = uVar9;
        if ((iVar12 != 0) && (uVar5 < uVar9)) {
          iVar12 = crc32(param_1[0xc],piVar16[2] + uVar5,uVar9 - uVar5);
          param_1[0xc] = iVar12;
        }
        piVar16[8] = piVar16[8] + (uVar14 - iVar17);
        flush_pending(param_1);
        if (piVar16[5] != 0) goto LAB_0800128c;
        iVar8 = iVar8 + (iVar17 - uVar14);
        uVar5 = 0;
        iVar12 = extraout_r3;
      }
      zmemcpy(piVar16[2] + iVar17,iVar6,iVar8,iVar12,piVar21,param_2);
      iVar12 = *(int *)(piVar16[7] + 0x2c);
      uVar14 = piVar16[5] + iVar8;
      piVar16[5] = uVar14;
      if ((iVar12 != 0) && (uVar5 < uVar14)) {
        iVar12 = crc32(param_1[0xc],piVar16[2] + uVar5,uVar14 - uVar5);
        param_1[0xc] = iVar12;
      }
      piVar16[8] = 0;
    }
    piVar16[1] = 0x49;
LAB_080014a8:
    if (*(int *)(piVar16[7] + 0x1c) != 0) {
      uVar5 = piVar16[5];
      do {
        uVar14 = piVar16[5];
        if (uVar14 == piVar16[3]) {
          if ((*(int *)(piVar16[7] + 0x2c) != 0) && (uVar5 < uVar14)) {
            iVar12 = crc32(param_1[0xc],piVar16[2] + uVar5,uVar14 - uVar5);
            param_1[0xc] = iVar12;
          }
          flush_pending(param_1);
          uVar5 = piVar16[5];
          if (uVar5 != 0) goto LAB_0800128c;
        }
        iVar12 = *(int *)(piVar16[7] + 0x1c);
        iVar8 = piVar16[8];
        piVar16[8] = iVar8 + 1;
        cVar11 = *(char *)(iVar12 + iVar8);
        iVar12 = piVar16[5];
        piVar16[5] = iVar12 + 1;
        *(char *)(piVar16[2] + iVar12) = cVar11;
      } while (cVar11 != '\0');
      if ((*(int *)(piVar16[7] + 0x2c) != 0) && (uVar5 < (uint)piVar16[5])) {
        iVar12 = crc32(param_1[0xc],piVar16[2] + uVar5,piVar16[5] - uVar5);
        param_1[0xc] = iVar12;
      }
      piVar16[8] = 0;
    }
    piVar16[1] = 0x5b;
LAB_0800151c:
    if (*(int *)(piVar16[7] + 0x24) != 0) {
      uVar5 = piVar16[5];
      do {
        uVar14 = piVar16[5];
        if (uVar14 == piVar16[3]) {
          if ((*(int *)(piVar16[7] + 0x2c) != 0) && (uVar5 < uVar14)) {
            iVar12 = crc32(param_1[0xc],piVar16[2] + uVar5,uVar14 - uVar5);
            param_1[0xc] = iVar12;
          }
          flush_pending(param_1);
          uVar5 = piVar16[5];
          if (uVar5 != 0) goto LAB_0800128c;
        }
        iVar12 = *(int *)(piVar16[7] + 0x24);
        iVar8 = piVar16[8];
        piVar16[8] = iVar8 + 1;
        cVar11 = *(char *)(iVar12 + iVar8);
        iVar12 = piVar16[5];
        piVar16[5] = iVar12 + 1;
        *(char *)(piVar16[2] + iVar12) = cVar11;
      } while (cVar11 != '\0');
      if ((*(int *)(piVar16[7] + 0x2c) != 0) && (uVar5 < (uint)piVar16[5])) {
        iVar12 = crc32(param_1[0xc],piVar16[2] + uVar5,piVar16[5] - uVar5);
        param_1[0xc] = iVar12;
      }
    }
    piVar16[1] = 0x67;
LAB_0800158c:
    if (*(int *)(piVar16[7] + 0x2c) != 0) {
      if (((uint)piVar16[3] < piVar16[5] + 2U) && (flush_pending(param_1), piVar16[5] != 0))
      goto LAB_0800128c;
      iVar8 = piVar16[5];
      iVar12 = param_1[0xc];
      piVar16[5] = iVar8 + 1;
      *(char *)(piVar16[2] + iVar8) = (char)iVar12;
      iVar12 = piVar16[5];
      iVar8 = param_1[0xc];
      piVar16[5] = iVar12 + 1;
      *(char *)(piVar16[2] + iVar12) = (char)((uint)iVar8 >> 8);
      iVar12 = crc32(0,0);
      param_1[0xc] = iVar12;
    }
    piVar16[1] = 0x71;
    flush_pending(param_1);
    if (piVar16[5] != 0) goto LAB_0800128c;
  }
  pbVar4 = DAT_08001990;
  iVar12 = DAT_0800198c;
  if ((param_1[1] == 0) && (piVar16[0x1d] == 0)) {
    if (iVar15 == 0) {
      return 0;
    }
    if (piVar16[1] == 0x29a) goto LAB_080019ba;
  }
  if (piVar16[0x21] == 0) {
    uVar5 = deflate_stored(piVar16,iVar15);
  }
  else {
    if (piVar16[0x22] == 2) {
      do {
        do {
          if ((piVar16[0x1d] == 0) && (fill_window(piVar16), piVar16[0x1d] == 0)) {
            if (iVar15 != 0) goto LAB_08001800;
            goto LAB_0800165e;
          }
          piVar16[0x18] = 0;
          bVar1 = *(byte *)(piVar16[0xe] + piVar16[0x1b]);
          iVar12 = piVar16[0x5a8];
          piVar16[0x5a8] = iVar12 + 1;
          *(undefined1 *)(piVar16[0x5a6] + iVar12) = 0;
          iVar12 = piVar16[0x5a8];
          piVar16[0x5a8] = iVar12 + 1;
          *(undefined1 *)(piVar16[0x5a6] + iVar12) = 0;
          iVar12 = piVar16[0x5a8];
          piVar16[0x5a8] = iVar12 + 1;
          *(byte *)(piVar16[0x5a6] + iVar12) = bVar1;
          *(short *)(piVar16 + bVar1 + 0x25) = (short)piVar16[bVar1 + 0x25] + 1;
          iVar12 = piVar16[0x5a9];
          iVar8 = piVar16[0x1b];
          piVar16[0x1d] = piVar16[0x1d] + -1;
          piVar16[0x1b] = iVar8 + 1;
        } while (piVar16[0x5a8] != iVar12);
        iVar6 = piVar16[0x17];
        if (-1 < iVar6) {
          iVar12 = piVar16[0xe];
        }
        if (-1 < iVar6) {
          iVar12 = iVar12 + iVar6;
        }
        else {
          iVar12 = 0;
        }
        _tr_flush_block(piVar16,iVar12,(iVar8 + 1) - iVar6,0);
        piVar16[0x17] = piVar16[0x1b];
        flush_pending(*piVar16);
      } while (*(int *)(*piVar16 + 0x10) != 0);
    }
    else {
      if (piVar16[0x22] != 3) {
        uVar5 = (**(code **)(piVar16[0x21] * 0xc + DAT_08001994 + 8))(piVar16,iVar15);
        goto LAB_0800130a;
      }
      do {
        do {
          if ((uint)piVar16[0x1d] < 0x103) {
            fill_window(piVar16);
            if ((uint)piVar16[0x1d] < 0x103) {
              if (iVar15 == 0) goto LAB_0800165e;
              if (piVar16[0x1d] == 0) goto LAB_08001800;
            }
          }
          uVar5 = piVar16[0x1d];
          piVar16[0x18] = 0;
          if ((2 < uVar5) && (iVar8 = piVar16[0x1b], iVar8 != 0)) {
            iVar17 = piVar16[0xe];
            iVar6 = iVar17 + iVar8 + -1;
            cVar11 = *(char *)(iVar17 + iVar8 + -1);
            if ((*(char *)(iVar6 + 1) == cVar11) &&
               ((*(char *)(iVar6 + 2) == cVar11 && (*(char *)(iVar6 + 3) == cVar11)))) {
              pcVar13 = (char *)(iVar6 + 3);
              pcVar10 = (char *)(iVar8 + 0x102 + iVar17);
              while( true ) {
                if (pcVar13[1] != cVar11) {
                  pcVar13 = pcVar13 + 1;
                  goto LAB_0800188e;
                }
                if (pcVar13[2] != cVar11) break;
                if (pcVar13[3] != cVar11) {
                  pcVar13 = pcVar13 + 3;
                  goto LAB_0800188e;
                }
                if (pcVar13[4] != cVar11) {
                  pcVar13 = pcVar13 + 4;
                  goto LAB_0800188e;
                }
                if (pcVar13[5] != cVar11) {
                  pcVar13 = pcVar13 + 5;
                  goto LAB_0800188e;
                }
                if (pcVar13[6] != cVar11) {
                  pcVar13 = pcVar13 + 6;
                  goto LAB_0800188e;
                }
                if (pcVar13[7] != cVar11) {
                  pcVar13 = pcVar13 + 7;
                  goto LAB_0800188e;
                }
                pcVar13 = pcVar13 + 8;
                if ((*pcVar13 != cVar11) || (pcVar10 <= pcVar13)) goto LAB_0800188e;
              }
              pcVar13 = pcVar13 + 2;
LAB_0800188e:
              uVar14 = 0x102 - ((int)pcVar10 - (int)pcVar13);
              if (uVar5 < uVar14) {
                piVar16[0x18] = uVar5;
              }
              else {
                piVar16[0x18] = uVar14;
              }
            }
          }
          uVar5 = piVar16[0x18];
          iVar8 = piVar16[0x5a8];
          if (uVar5 < 3) {
            bVar1 = *(byte *)(piVar16[0xe] + piVar16[0x1b]);
            piVar16[0x5a8] = iVar8 + 1;
            *(undefined1 *)(piVar16[0x5a6] + iVar8) = 0;
            iVar8 = piVar16[0x5a8];
            piVar16[0x5a8] = iVar8 + 1;
            *(undefined1 *)(piVar16[0x5a6] + iVar8) = 0;
            iVar8 = piVar16[0x5a8];
            piVar16[0x5a8] = iVar8 + 1;
            *(byte *)(piVar16[0x5a6] + iVar8) = bVar1;
            *(short *)(piVar16 + bVar1 + 0x25) = (short)piVar16[bVar1 + 0x25] + 1;
            bVar19 = piVar16[0x5a8] == piVar16[0x5a9];
            piVar16[0x1d] = piVar16[0x1d] + -1;
            piVar16[0x1b] = piVar16[0x1b] + 1;
          }
          else {
            piVar16[0x5a8] = iVar8 + 1;
            *(undefined1 *)(piVar16[0x5a6] + iVar8) = 1;
            iVar8 = piVar16[0x5a8];
            piVar16[0x5a8] = iVar8 + 1;
            *(undefined1 *)(piVar16[0x5a6] + iVar8) = 0;
            iVar8 = piVar16[0x5a8];
            uVar5 = uVar5 - 3;
            piVar16[0x5a8] = iVar8 + 1;
            *(char *)(piVar16[0x5a6] + iVar8) = (char)uVar5;
            bVar1 = *(byte *)(iVar12 + (uVar5 & 0xff));
            *(short *)(piVar16 + bVar1 + 0x126) = (short)piVar16[bVar1 + 0x126] + 1;
            *(short *)(piVar16 + *pbVar4 + 0x262) = (short)piVar16[*pbVar4 + 0x262] + 1;
            bVar19 = piVar16[0x5a8] == piVar16[0x5a9];
            iVar8 = piVar16[0x18];
            piVar16[0x18] = 0;
            piVar16[0x1d] = piVar16[0x1d] - iVar8;
            piVar16[0x1b] = piVar16[0x1b] + iVar8;
          }
        } while (!bVar19);
        iVar8 = piVar16[0x17];
        if (iVar8 < 0) {
          iVar6 = 0;
        }
        else {
          iVar6 = piVar16[0xe] + iVar8;
        }
        _tr_flush_block(piVar16,iVar6,piVar16[0x1b] - iVar8,0);
        piVar16[0x17] = piVar16[0x1b];
        flush_pending(*piVar16);
      } while (*(int *)(*piVar16 + 0x10) != 0);
    }
LAB_0800165e:
    uVar5 = 0;
  }
LAB_0800130a:
  if ((uVar5 - 2 & 0xff) < 2) {
    piVar16[1] = 0x29a;
    if (uVar5 != 2) goto LAB_080019ba;
  }
  else if (uVar5 != 0) {
    if (uVar5 != 1) {
LAB_080019ba:
      if (iVar15 != 4) {
        return 0;
      }
      if (piVar16[6] < 1) {
        return 1;
      }
      uVar5 = param_1[0xc];
      if (piVar16[6] == 2) {
        iVar15 = piVar16[5];
        piVar16[5] = iVar15 + 1;
        *(char *)(piVar16[2] + iVar15) = (char)uVar5;
        iVar15 = piVar16[5];
        iVar12 = param_1[0xc];
        piVar16[5] = iVar15 + 1;
        *(char *)(piVar16[2] + iVar15) = (char)((uint)iVar12 >> 8);
        iVar15 = piVar16[5];
        uVar2 = *(undefined2 *)((int)param_1 + 0x32);
        piVar16[5] = iVar15 + 1;
        *(char *)(piVar16[2] + iVar15) = (char)uVar2;
        iVar15 = piVar16[5];
        uVar3 = *(undefined1 *)((int)param_1 + 0x33);
        piVar16[5] = iVar15 + 1;
        *(undefined1 *)(piVar16[2] + iVar15) = uVar3;
        iVar12 = piVar16[5];
        iVar15 = param_1[2];
        piVar16[5] = iVar12 + 1;
        *(char *)(piVar16[2] + iVar12) = (char)iVar15;
        iVar15 = piVar16[5];
        iVar12 = param_1[2];
        piVar16[5] = iVar15 + 1;
        *(char *)(piVar16[2] + iVar15) = (char)((uint)iVar12 >> 8);
        iVar15 = piVar16[5];
        uVar2 = *(undefined2 *)((int)param_1 + 10);
        piVar16[5] = iVar15 + 1;
        *(char *)(piVar16[2] + iVar15) = (char)uVar2;
        iVar15 = piVar16[5];
        uVar3 = *(undefined1 *)((int)param_1 + 0xb);
        piVar16[5] = iVar15 + 1;
        *(undefined1 *)(piVar16[2] + iVar15) = uVar3;
      }
      else {
        uVar7 = putShortMSB(piVar16,uVar5 >> 0x10);
        putShortMSB(uVar7,(short)param_1[0xc]);
      }
      flush_pending(param_1);
      if (0 < piVar16[6]) {
        piVar16[6] = -piVar16[6];
      }
      return (uint)(piVar16[5] == 0);
    }
    if (iVar15 == 1) {
      _tr_align(piVar16);
    }
    else if ((iVar15 != 5) && (_tr_stored_block(piVar16,0,0), iVar15 == 3)) {
      iVar8 = piVar16[0x13];
      iVar12 = piVar16[0x11];
      *(undefined2 *)(iVar12 + (iVar8 + 0x7fffffff) * 2) = 0;
      zmemzero(iVar12,(iVar8 + -1) * 2);
      if (piVar16[0x1d] == 0) {
        piVar16[0x1b] = 0;
        piVar16[0x17] = 0;
        piVar16[0x5ad] = 0;
      }
    }
    flush_pending(param_1);
    if (param_1[4] != 0) goto LAB_080019ba;
    goto LAB_0800128c;
  }
  if (param_1[4] != 0) {
    return 0;
  }
LAB_0800128c:
  piVar16[10] = -1;
  return 0;
LAB_08001800:
  iVar12 = 0;
  piVar16[0x5ad] = 0;
  if (iVar15 == 4) {
    iVar8 = piVar16[0x17];
    if (-1 < iVar8) {
      iVar12 = piVar16[0xe] + iVar8;
    }
    _tr_flush_block(piVar16,iVar12,piVar16[0x1b] - iVar8,1);
    piVar16[0x17] = piVar16[0x1b];
    flush_pending(*piVar16);
    if (*(int *)(*piVar16 + 0x10) == 0) {
      uVar5 = 2;
    }
    else {
      uVar5 = 3;
    }
  }
  else if (piVar16[0x5a8] == 0) {
    uVar5 = 1;
  }
  else {
    iVar8 = piVar16[0x17];
    if (-1 < iVar8) {
      iVar12 = piVar16[0xe] + iVar8;
    }
    _tr_flush_block(piVar16,iVar12,piVar16[0x1b] - iVar8,0);
    piVar16[0x17] = piVar16[0x1b];
    flush_pending(*piVar16);
    uVar5 = (uint)(*(int *)(*piVar16 + 0x10) != 0);
  }
  goto LAB_0800130a;
}




undefined4 deflateEnd(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = deflateStateCheck();
  if (iVar1 == 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x1c) + 4);
    if (*(int *)(*(int *)(param_1 + 0x1c) + 8) != 0) {
      (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28));
    }
    if (*(int *)(*(int *)(param_1 + 0x1c) + 0x44) != 0) {
      (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28));
    }
    if (*(int *)(*(int *)(param_1 + 0x1c) + 0x40) != 0) {
      (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28));
    }
    if (*(int *)(*(int *)(param_1 + 0x1c) + 0x38) != 0) {
      (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28));
    }
    (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x1c));
    *(undefined4 *)(param_1 + 0x1c) = 0;
    uVar2 = 0;
    if (iVar1 == 0x71) {
      uVar2 = 0xfffffffd;
    }
  }
  else {
    uVar2 = 0xfffffffe;
  }
  return uVar2;
}




undefined4
deflateInit2_(int param_1,uint param_2,int param_3,uint param_4,int param_5,uint param_6,
             char *param_7,int param_8)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  
  if (((param_7 == (char *)0x0) || (*param_7 != '1')) || (param_8 != 0x38)) {
    return 0xfffffffa;
  }
  if (param_1 != 0) {
    iVar5 = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    if ((*(code **)(param_1 + 0x20) != (code *)0x0) && (*(int *)(param_1 + 0x24) != 0)) {
      if (param_2 == 0xffffffff) {
        param_2 = 6;
      }
      if ((int)param_4 < 0) {
        if ((int)param_4 < -0xf) {
          return 0xfffffffe;
        }
        uVar6 = -param_4;
      }
      else if ((int)param_4 < 0x10) {
        iVar5 = 1;
        uVar6 = param_4;
      }
      else {
        iVar5 = 2;
        uVar6 = param_4 - 0x10;
      }
      if (((param_5 - 1U < 9) && (param_3 == 8)) &&
         ((uVar6 - 8 < 8 && ((param_2 < 10 && (param_6 < 5)))))) {
        if (uVar6 == 8) {
          if (iVar5 != 1) {
            return 0xfffffffe;
          }
          uVar6 = 9;
        }
        piVar1 = (int *)(**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),1,0x16c4);
        if (piVar1 != (int *)0x0) {
          *(int **)(param_1 + 0x1c) = piVar1;
          piVar1[6] = iVar5;
          iVar5 = 1 << (uVar6 & 0xff);
          piVar1[1] = 0x2a;
          piVar1[0xd] = iVar5 + -1;
          piVar1[0x14] = param_5 + 7U;
          iVar3 = 1 << (param_5 + 7U & 0xff);
          piVar1[0x13] = iVar3;
          piVar1[0xc] = uVar6;
          piVar1[0xb] = iVar5;
          piVar1[0x15] = iVar3 + -1;
          *piVar1 = param_1;
          piVar1[7] = 0;
          piVar1[0x16] = (param_5 + 9U) / 3;
          iVar5 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),iVar5,2);
          pcVar4 = *(code **)(param_1 + 0x20);
          piVar1[0xe] = iVar5;
          iVar5 = (*pcVar4)(*(undefined4 *)(param_1 + 0x28),piVar1[0xb],2);
          pcVar4 = *(code **)(param_1 + 0x20);
          piVar1[0x10] = iVar5;
          iVar5 = (*pcVar4)(*(undefined4 *)(param_1 + 0x28),piVar1[0x13],2);
          iVar3 = 1 << (param_5 + 6U & 0xff);
          piVar1[0x11] = iVar5;
          pcVar4 = *(code **)(param_1 + 0x20);
          uVar2 = *(undefined4 *)(param_1 + 0x28);
          piVar1[0x5b0] = 0;
          piVar1[0x5a7] = iVar3;
          uVar7 = (*pcVar4)(uVar2,iVar3,4);
          iVar5 = (int)uVar7;
          iVar3 = piVar1[0x5a7];
          piVar1[2] = iVar5;
          piVar1[3] = iVar3 << 2;
          if ((((piVar1[0xe] != 0) && (piVar1[0x10] != 0)) && (piVar1[0x11] != 0)) && (iVar5 != 0))
          {
            piVar1[0x5a9] = iVar3 * 3 + -3;
            piVar1[0x5a6] = iVar5 + iVar3;
            *(undefined1 *)(piVar1 + 9) = 8;
            piVar1[0x21] = param_2;
            piVar1[0x22] = param_6;
            uVar2 = deflateReset(param_1,(int)((ulonglong)uVar7 >> 0x20),piVar1[0x11],param_4);
            return uVar2;
          }
          piVar1[1] = 0x29a;
          *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(DAT_08001db8 + 0x18);
          deflateEnd(param_1);
        }
        return 0xfffffffc;
      }
    }
  }
  return 0xfffffffe;
}




void deflateInit_(void)

{
  deflateInit2_();
  return;
}




undefined4 updatewindow(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x1c);
  if (*(int *)(iVar3 + 0x38) == 0) {
    iVar4 = (**(code **)(param_1 + 0x20))
                      (*(undefined4 *)(param_1 + 0x28),1 << (*(uint *)(iVar3 + 0x28) & 0xff),1);
    *(int *)(iVar3 + 0x38) = iVar4;
    if (iVar4 == 0) {
      return 1;
    }
  }
  if (*(int *)(iVar3 + 0x2c) == 0) {
    *(undefined4 *)(iVar3 + 0x30) = 0;
    *(undefined4 *)(iVar3 + 0x34) = 0;
    *(int *)(iVar3 + 0x2c) = 1 << (*(uint *)(iVar3 + 0x28) & 0xff);
  }
  uVar1 = *(uint *)(iVar3 + 0x2c);
  if (param_3 < uVar1) {
    uVar1 = uVar1 - *(int *)(iVar3 + 0x34);
    if (param_3 <= uVar1) {
      uVar1 = param_3;
    }
    zmemcpy(*(int *)(iVar3 + 0x38) + *(int *)(iVar3 + 0x34),param_2 - param_3,uVar1);
    iVar4 = param_3 - uVar1;
    if (iVar4 == 0) {
      uVar2 = *(int *)(iVar3 + 0x34) + uVar1;
      if (uVar2 == *(uint *)(iVar3 + 0x2c)) {
        uVar2 = 0;
      }
      *(uint *)(iVar3 + 0x34) = uVar2;
      if (*(uint *)(iVar3 + 0x30) < *(uint *)(iVar3 + 0x2c)) {
        *(uint *)(iVar3 + 0x30) = uVar1 + *(uint *)(iVar3 + 0x30);
        return 0;
      }
      return 0;
    }
    zmemcpy(*(undefined4 *)(iVar3 + 0x38),(uVar1 - param_3) + param_2,iVar4);
    *(int *)(iVar3 + 0x34) = iVar4;
  }
  else {
    zmemcpy(*(int *)(iVar3 + 0x38),param_2 - uVar1);
    *(undefined4 *)(iVar3 + 0x34) = 0;
  }
  *(undefined4 *)(iVar3 + 0x30) = *(undefined4 *)(iVar3 + 0x2c);
  return 0;
}




bool inflateStateCheck(int param_1)

{
  int *piVar1;
  
  if ((((param_1 == 0) || (*(int *)(param_1 + 0x20) == 0)) || (*(int *)(param_1 + 0x24) == 0)) ||
     ((piVar1 = *(int **)(param_1 + 0x1c), piVar1 == (int *)0x0 || (param_1 != *piVar1)))) {
    return true;
  }
  return 0x1f < (ushort)((short)piVar1[1] + 0xc0ccU);
}




undefined4 inflateResetKeep(undefined4 param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  
  uVar5 = inflateStateCheck(param_1,param_1);
  iVar3 = (int)((ulonglong)uVar5 >> 0x20);
  if ((int)uVar5 == 0) {
    iVar4 = *(int *)(iVar3 + 0x1c);
    uVar2 = *(uint *)(iVar4 + 0xc);
    *(undefined4 *)(iVar4 + 0x20) = 0;
    *(undefined4 *)(iVar3 + 0x14) = 0;
    *(undefined4 *)(iVar3 + 8) = 0;
    *(undefined4 *)(iVar3 + 0x18) = 0;
    if (uVar2 != 0) {
      *(uint *)(iVar3 + 0x30) = uVar2 & 1;
    }
    *(undefined2 *)(iVar4 + 4) = 0x3f34;
    *(undefined4 *)(iVar4 + 0x3c) = 0;
    *(undefined4 *)(iVar4 + 0x40) = 0;
    *(undefined4 *)(iVar4 + 8) = 0;
    *(undefined4 *)(iVar4 + 0x10) = 0;
    *(undefined4 *)(iVar4 + 0x24) = 0;
    iVar3 = iVar4 + 0x534;
    *(int *)(iVar4 + 0x50) = iVar3;
    *(int *)(iVar4 + 0x54) = iVar3;
    *(int *)(iVar4 + 0x70) = iVar3;
    *(undefined4 *)(iVar4 + 0x14) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x18) = 0x8000;
    *(undefined4 *)(iVar4 + 0x1bc4) = 1;
    *(undefined4 *)(iVar4 + 0x1bc8) = 0xffffffff;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}




undefined4 inflateReset(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_r2;
  int iVar3;
  undefined8 uVar4;
  
  uVar4 = inflateStateCheck(param_1,param_1);
  iVar2 = (int)((ulonglong)uVar4 >> 0x20);
  if ((int)uVar4 == 0) {
    iVar3 = *(int *)(iVar2 + 0x1c);
    *(undefined4 *)(iVar3 + 0x2c) = 0;
    *(undefined4 *)(iVar3 + 0x30) = 0;
    *(undefined4 *)(iVar3 + 0x34) = 0;
    uVar1 = inflateResetKeep(iVar2,iVar2,extraout_r2,param_4);
    return uVar1;
  }
  return 0xfffffffe;
}




undefined4 inflateReset2(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  uint uVar3;
  int iVar4;
  int iVar5;
  ulonglong uVar6;
  
  uVar6 = inflateStateCheck();
  uVar3 = (uint)(uVar6 >> 0x20);
  if ((int)uVar6 == 0) {
    iVar5 = *(int *)(param_1 + 0x1c);
    if ((longlong)uVar6 < 0) {
      if ((longlong)uVar6 < -0xf00000000) {
        return 0xfffffffe;
      }
      uVar3 = -uVar3;
      iVar4 = 0;
    }
    else {
      iVar4 = ((int)uVar3 >> 4) + 5;
      if (((longlong)uVar6 < 0x3000000000) && (uVar3 = uVar3 & 0xf, (uVar6 & 0xf00000000) == 0))
      goto LAB_08001f56;
    }
    if (uVar3 - 8 < 8) {
LAB_08001f56:
      iVar2 = *(int *)(iVar5 + 0x38);
      uVar1 = extraout_r2;
      if ((iVar2 != 0) && (*(uint *)(iVar5 + 0x28) != uVar3)) {
        (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28));
        *(undefined4 *)(iVar5 + 0x38) = 0;
        iVar2 = extraout_r1;
        uVar1 = extraout_r2_00;
      }
      *(int *)(iVar5 + 0xc) = iVar4;
      *(uint *)(iVar5 + 0x28) = uVar3;
      uVar1 = inflateReset(param_1,iVar2,uVar1,param_4);
      return uVar1;
    }
  }
  return 0xfffffffe;
}




int inflateInit2_(int param_1,undefined4 param_2,char *param_3,int param_4)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  
  if (((param_3 == (char *)0x0) || (*param_3 != '1')) || (param_4 != 0x38)) {
    iVar3 = -6;
  }
  else {
    if (param_1 != 0) {
      pcVar2 = *(code **)(param_1 + 0x20);
      *(undefined4 *)(param_1 + 0x18) = 0;
      if ((pcVar2 != (code *)0x0) && (*(int *)(param_1 + 0x24) != 0)) {
        piVar1 = (int *)(*pcVar2)(*(undefined4 *)(param_1 + 0x28),1,0x1bd0,pcVar2,0x38);
        if (piVar1 == (int *)0x0) {
          return -4;
        }
        *(int **)(param_1 + 0x1c) = piVar1;
        *piVar1 = param_1;
        piVar1[0xe] = 0;
        *(undefined2 *)(piVar1 + 1) = 0x3f34;
        iVar3 = inflateReset2(param_1,param_2);
        if (iVar3 == 0) {
          return 0;
        }
        (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),piVar1);
        *(undefined4 *)(param_1 + 0x1c) = 0;
        return iVar3;
      }
    }
    iVar3 = -2;
  }
  return iVar3;
}




void inflateInit_(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  inflateInit2_(param_1,0xf,param_2,param_3);
  return;
}




int inflate(undefined4 *param_1,int param_2)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined2 *puVar8;
  uint uVar9;
  uint uVar10;
  undefined2 uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  undefined1 *puVar15;
  undefined1 *puVar17;
  undefined1 *puVar16;
  uint uVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  byte *pbVar24;
  uint uVar25;
  uint uVar26;
  int local_4c;
  undefined1 *local_48;
  uint local_44;
  uint local_2c [2];
  
  iVar3 = inflateStateCheck();
  if ((iVar3 != 0) || (local_48 = (undefined1 *)param_1[3], local_48 == (undefined1 *)0x0)) {
switchD_0800204c_default:
    return -2;
  }
  pbVar24 = (byte *)*param_1;
  uVar12 = param_1[1];
  if ((pbVar24 == (byte *)0x0) && (uVar12 != 0)) goto switchD_0800204c_default;
  iVar3 = param_1[7];
  uVar26 = param_1[4];
  uVar19 = *(uint *)(iVar3 + 0x40);
  local_4c = 0;
  uVar21 = *(uint *)(iVar3 + 0x3c);
  uVar23 = uVar12;
  local_44 = uVar26;
  if (*(short *)(iVar3 + 4) == 0x3f3f) {
    *(undefined2 *)(iVar3 + 4) = 0x3f40;
  }
LAB_08002040:
  switch(*(undefined2 *)(iVar3 + 4)) {
  case 0x3f34:
    iVar13 = *(int *)(iVar3 + 0xc);
    if (iVar13 == 0) {
      uVar11 = 0x3f40;
      goto LAB_08002098;
    }
    for (; uVar19 < 0x10; uVar19 = uVar19 + 8) {
      if (uVar23 == 0) goto LAB_08002362;
      uVar23 = uVar23 - 1;
      uVar21 = uVar21 + ((uint)*pbVar24 << (uVar19 & 0xff));
      pbVar24 = pbVar24 + 1;
    }
    if ((-1 < iVar13 << 0x1e) || (uVar21 != 0x8b1f)) {
      if (*(int *)(iVar3 + 0x24) != 0) {
        *(undefined4 *)(*(int *)(iVar3 + 0x24) + 0x30) = 0xffffffff;
      }
      if ((-1 < iVar13 << 0x1f) ||
         (uVar18 = (uVar21 & 0xff) * 0x100 + (uVar21 >> 8), uVar18 != (uVar18 / 0x1f) * 0x1f)) {
        uVar4 = DAT_08002198;
        break;
      }
      if ((uVar21 & 0xf) != 8) goto LAB_08002140;
      uVar21 = uVar21 >> 4;
      uVar19 = uVar19 - 4;
      uVar18 = (uVar21 & 0xf) + 8;
      if (*(uint *)(iVar3 + 0x28) == 0) {
        *(uint *)(iVar3 + 0x28) = uVar18;
        if (uVar18 < 0x10) goto LAB_08002164;
      }
      else if ((uVar18 < 0x10) && (uVar18 <= *(uint *)(iVar3 + 0x28))) {
LAB_08002164:
        *(int *)(iVar3 + 0x18) = 1 << uVar18;
        *(undefined4 *)(iVar3 + 0x14) = 0;
        uVar4 = adler32(0,0,0);
        uVar11 = 0x3f3f;
        if ((uVar21 & 0x200) != 0) {
          uVar11 = 0x3f3d;
        }
        *(undefined4 *)(iVar3 + 0x1c) = uVar4;
        param_1[0xc] = uVar4;
        *(undefined2 *)(iVar3 + 4) = uVar11;
        goto LAB_0800210c;
      }
      uVar4 = DAT_080021a0;
      break;
    }
    if (*(int *)(iVar3 + 0x28) == 0) {
      *(undefined4 *)(iVar3 + 0x28) = 0xf;
    }
    uVar4 = crc32(0,0);
    *(undefined4 *)(iVar3 + 0x1c) = uVar4;
    local_2c[0] = CONCAT22(local_2c[0]._2_2_,0x8b1f);
    uVar4 = crc32(uVar4,local_2c,2);
    *(undefined4 *)(iVar3 + 0x1c) = uVar4;
    *(undefined2 *)(iVar3 + 4) = 0x3f35;
LAB_0800210c:
    uVar19 = 0;
    uVar21 = uVar19;
    goto LAB_08002040;
  case 0x3f35:
    for (; uVar19 < 0x10; uVar19 = uVar19 + 8) {
      if (uVar23 == 0) goto LAB_08002362;
      uVar23 = uVar23 - 1;
      uVar21 = uVar21 + ((uint)*pbVar24 << (uVar19 & 0xff));
      pbVar24 = pbVar24 + 1;
    }
    *(uint *)(iVar3 + 0x14) = uVar21;
    if ((uVar21 & 0xff) == 8) {
      if ((uVar21 & 0xe000) == 0) {
        if (*(uint **)(iVar3 + 0x24) != (uint *)0x0) {
          **(uint **)(iVar3 + 0x24) = (uVar21 & 0x1ff) >> 8;
        }
        if (((int)(uVar21 << 0x16) < 0) && (*(int *)(iVar3 + 0xc) << 0x1d < 0)) {
          local_2c[0] = CONCAT22(local_2c[0]._2_2_,(short)uVar21);
          uVar4 = crc32(*(undefined4 *)(iVar3 + 0x1c),local_2c,2);
          *(undefined4 *)(iVar3 + 0x1c) = uVar4;
        }
        uVar19 = 0;
        *(undefined2 *)(iVar3 + 4) = 0x3f36;
        uVar21 = 0;
        goto switchD_0800204c_caseD_3f36;
      }
      uVar4 = DAT_08002194;
    }
    else {
LAB_08002140:
      uVar4 = DAT_0800219c;
    }
    break;
  case 0x3f36:
switchD_0800204c_caseD_3f36:
    for (; uVar19 < 0x20; uVar19 = uVar19 + 8) {
      if (uVar23 == 0) goto LAB_08002362;
      uVar23 = uVar23 - 1;
      uVar21 = uVar21 + ((uint)*pbVar24 << (uVar19 & 0xff));
      pbVar24 = pbVar24 + 1;
    }
    if (*(int *)(iVar3 + 0x24) != 0) {
      *(uint *)(*(int *)(iVar3 + 0x24) + 4) = uVar21;
    }
    if ((*(int *)(iVar3 + 0x14) << 0x16 < 0) && (*(int *)(iVar3 + 0xc) << 0x1d < 0)) {
      local_2c[0] = uVar21;
      uVar4 = crc32(*(undefined4 *)(iVar3 + 0x1c),local_2c,4);
      *(undefined4 *)(iVar3 + 0x1c) = uVar4;
    }
    uVar19 = 0;
    *(undefined2 *)(iVar3 + 4) = 0x3f37;
    uVar21 = 0;
  case 0x3f37:
    for (; uVar19 < 0x10; uVar19 = uVar19 + 8) {
      if (uVar23 == 0) goto LAB_08002362;
      uVar23 = uVar23 - 1;
      uVar21 = uVar21 + ((uint)*pbVar24 << (uVar19 & 0xff));
      pbVar24 = pbVar24 + 1;
    }
    iVar13 = *(int *)(iVar3 + 0x24);
    if (iVar13 != 0) {
      *(uint *)(iVar13 + 8) = uVar21 & 0xff;
      *(uint *)(iVar13 + 0xc) = uVar21 >> 8;
    }
    if ((*(int *)(iVar3 + 0x14) << 0x16 < 0) && (*(int *)(iVar3 + 0xc) << 0x1d < 0)) {
      local_2c[0] = CONCAT22(local_2c[0]._2_2_,(short)uVar21);
      uVar4 = crc32(*(undefined4 *)(iVar3 + 0x1c),local_2c,2);
      *(undefined4 *)(iVar3 + 0x1c) = uVar4;
    }
    uVar19 = 0;
    *(undefined2 *)(iVar3 + 4) = 0x3f38;
    uVar21 = 0;
switchD_0800204c_caseD_3f38:
    uVar18 = *(uint *)(iVar3 + 0x14);
    if ((uVar18 & 0x400) == 0) {
      if (*(int *)(iVar3 + 0x24) != 0) {
        *(undefined4 *)(*(int *)(iVar3 + 0x24) + 0x10) = 0;
      }
    }
    else {
      for (; uVar19 < 0x10; uVar19 = uVar19 + 8) {
        if (uVar23 == 0) goto LAB_08002362;
        uVar23 = uVar23 - 1;
        uVar21 = uVar21 + ((uint)*pbVar24 << (uVar19 & 0xff));
        pbVar24 = pbVar24 + 1;
      }
      *(uint *)(iVar3 + 0x44) = uVar21;
      if (*(int *)(iVar3 + 0x24) != 0) {
        *(uint *)(*(int *)(iVar3 + 0x24) + 0x14) = uVar21;
      }
      if (((int)(uVar18 << 0x16) < 0) && (*(int *)(iVar3 + 0xc) << 0x1d < 0)) {
        local_2c[0] = CONCAT22(local_2c[0]._2_2_,(short)uVar21);
        uVar4 = crc32(*(undefined4 *)(iVar3 + 0x1c),local_2c,2);
        *(undefined4 *)(iVar3 + 0x1c) = uVar4;
      }
      uVar19 = 0;
      uVar21 = 0;
    }
    *(undefined2 *)(iVar3 + 4) = 0x3f39;
switchD_0800204c_caseD_3f39:
    if (*(int *)(iVar3 + 0x14) << 0x15 < 0) {
      uVar10 = *(uint *)(iVar3 + 0x44);
      uVar18 = uVar23;
      if (uVar10 <= uVar23) {
        uVar18 = uVar10;
      }
      if (uVar18 != 0) {
        iVar13 = *(int *)(iVar3 + 0x24);
        if ((iVar13 != 0) && (*(int *)(iVar13 + 0x10) != 0)) {
          uVar9 = *(uint *)(iVar13 + 0x18);
          uVar6 = *(int *)(iVar13 + 0x14) - uVar10;
          if (uVar6 < uVar9) {
            if (uVar9 < uVar6 + uVar18) {
              uVar10 = (uVar9 + uVar10) - *(int *)(iVar13 + 0x14);
            }
            else {
              uVar10 = uVar18;
            }
            zmemcpy(*(int *)(iVar13 + 0x10) + uVar6,pbVar24,uVar10);
          }
        }
        if ((*(int *)(iVar3 + 0x14) << 0x16 < 0) && (*(int *)(iVar3 + 0xc) << 0x1d < 0)) {
          uVar4 = crc32(*(undefined4 *)(iVar3 + 0x1c),pbVar24,uVar18);
          *(undefined4 *)(iVar3 + 0x1c) = uVar4;
        }
        uVar23 = uVar23 - uVar18;
        pbVar24 = pbVar24 + uVar18;
        *(uint *)(iVar3 + 0x44) = *(int *)(iVar3 + 0x44) - uVar18;
      }
      if (*(int *)(iVar3 + 0x44) != 0) goto LAB_08002362;
    }
    *(undefined4 *)(iVar3 + 0x44) = 0;
    *(undefined2 *)(iVar3 + 4) = 0x3f3a;
switchD_0800204c_caseD_3f3a:
    if ((*(uint *)(iVar3 + 0x14) & 0x800) == 0) {
      if (*(int *)(iVar3 + 0x24) != 0) {
        *(undefined4 *)(*(int *)(iVar3 + 0x24) + 0x1c) = 0;
      }
    }
    else {
      if (uVar23 == 0) goto LAB_08002362;
      pbVar5 = pbVar24 + -1;
      uVar18 = 0;
      do {
        iVar13 = *(int *)(iVar3 + 0x24);
        pbVar5 = pbVar5 + 1;
        uVar10 = (uint)*pbVar5;
        uVar18 = uVar18 + 1;
        if ((iVar13 != 0) && (iVar20 = *(int *)(iVar13 + 0x1c), iVar20 != 0)) {
          uVar9 = *(uint *)(iVar13 + 0x20);
          uVar25 = *(uint *)(iVar3 + 0x44);
          uVar6 = uVar9;
          if (uVar25 < uVar9) {
            *(uint *)(iVar3 + 0x44) = uVar25 + 1;
            uVar6 = uVar10;
          }
          if (uVar25 < uVar9) {
            *(char *)(iVar20 + uVar25) = (char)uVar6;
          }
        }
      } while ((uVar10 != 0) && (uVar23 != uVar18));
      if ((*(int *)(iVar3 + 0x14) << 0x16 < 0) && (*(int *)(iVar3 + 0xc) << 0x1d < 0)) {
        uVar4 = crc32(*(undefined4 *)(iVar3 + 0x1c),pbVar24,uVar18);
        *(undefined4 *)(iVar3 + 0x1c) = uVar4;
      }
      uVar23 = uVar23 - uVar18;
      pbVar24 = pbVar24 + uVar18;
      if (uVar10 != 0) goto LAB_08002362;
    }
    *(undefined4 *)(iVar3 + 0x44) = 0;
    *(undefined2 *)(iVar3 + 4) = 0x3f3b;
switchD_0800204c_caseD_3f3b:
    if ((*(uint *)(iVar3 + 0x14) & 0x1000) == 0) {
      if (*(int *)(iVar3 + 0x24) != 0) {
        *(undefined4 *)(*(int *)(iVar3 + 0x24) + 0x24) = 0;
      }
    }
    else {
      if (uVar23 == 0) goto LAB_08002362;
      pbVar5 = pbVar24 + -1;
      uVar18 = 0;
      do {
        iVar13 = *(int *)(iVar3 + 0x24);
        pbVar5 = pbVar5 + 1;
        uVar10 = (uint)*pbVar5;
        uVar18 = uVar18 + 1;
        if ((iVar13 != 0) && (iVar20 = *(int *)(iVar13 + 0x24), iVar20 != 0)) {
          uVar9 = *(uint *)(iVar13 + 0x28);
          uVar25 = *(uint *)(iVar3 + 0x44);
          uVar6 = uVar9;
          if (uVar25 < uVar9) {
            *(uint *)(iVar3 + 0x44) = uVar25 + 1;
            uVar6 = uVar10;
          }
          if (uVar25 < uVar9) {
            *(char *)(iVar20 + uVar25) = (char)uVar6;
          }
        }
      } while ((uVar10 != 0) && (uVar23 != uVar18));
      if ((*(int *)(iVar3 + 0x14) << 0x16 < 0) && (*(int *)(iVar3 + 0xc) << 0x1d < 0)) {
        uVar4 = crc32(*(undefined4 *)(iVar3 + 0x1c),pbVar24,uVar18);
        *(undefined4 *)(iVar3 + 0x1c) = uVar4;
      }
      uVar23 = uVar23 - uVar18;
      pbVar24 = pbVar24 + uVar18;
      if (uVar10 != 0) goto LAB_08002362;
    }
    *(undefined2 *)(iVar3 + 4) = 0x3f3c;
switchD_0800204c_caseD_3f3c:
    if ((int)(*(uint *)(iVar3 + 0x14) << 0x16) < 0) {
      for (; uVar19 < 0x10; uVar19 = uVar19 + 8) {
        if (uVar23 == 0) goto LAB_08002362;
        uVar23 = uVar23 - 1;
        uVar21 = uVar21 + ((uint)*pbVar24 << (uVar19 & 0xff));
        pbVar24 = pbVar24 + 1;
      }
      if (((*(uint *)(iVar3 + 0xc) & 4) != 0) && (*(ushort *)(iVar3 + 0x1c) != uVar21)) {
        uVar4 = DAT_0800274c;
        break;
      }
      uVar19 = 0;
      uVar21 = 0;
    }
    iVar13 = *(int *)(iVar3 + 0x24);
    if (iVar13 != 0) {
      *(uint *)(iVar13 + 0x2c) = (*(uint *)(iVar3 + 0x14) & 0x3ff) >> 9;
      *(undefined4 *)(iVar13 + 0x30) = 1;
    }
    uVar4 = crc32(0,0);
    *(undefined4 *)(iVar3 + 0x1c) = uVar4;
    param_1[0xc] = uVar4;
    goto LAB_080024ea;
  case 0x3f38:
    goto switchD_0800204c_caseD_3f38;
  case 0x3f39:
    goto switchD_0800204c_caseD_3f39;
  case 0x3f3a:
    goto switchD_0800204c_caseD_3f3a;
  case 0x3f3b:
    goto switchD_0800204c_caseD_3f3b;
  case 0x3f3c:
    goto switchD_0800204c_caseD_3f3c;
  case 0x3f3d:
    for (; uVar19 < 0x20; uVar19 = uVar19 + 8) {
      if (uVar23 == 0) goto LAB_08002362;
      uVar23 = uVar23 - 1;
      uVar21 = uVar21 + ((uint)*pbVar24 << (uVar19 & 0xff));
      pbVar24 = pbVar24 + 1;
    }
    uVar21 = uVar21 << 0x18 | (uVar21 >> 8 & 0xff) << 0x10 | (uVar21 >> 0x10 & 0xff) << 8 |
             uVar21 >> 0x18;
    *(uint *)(iVar3 + 0x1c) = uVar21;
    param_1[0xc] = uVar21;
    uVar21 = 0;
    *(undefined2 *)(iVar3 + 4) = 0x3f3e;
    uVar19 = 0;
  case 0x3f3e:
    if (*(int *)(iVar3 + 0x10) == 0) {
      *param_1 = pbVar24;
      param_1[1] = uVar23;
      param_1[3] = local_48;
      param_1[4] = uVar26;
      *(uint *)(iVar3 + 0x3c) = uVar21;
      *(uint *)(iVar3 + 0x40) = uVar19;
      return 2;
    }
    uVar4 = adler32(0,0);
    *(undefined4 *)(iVar3 + 0x1c) = uVar4;
    param_1[0xc] = uVar4;
    *(undefined2 *)(iVar3 + 4) = 0x3f3f;
switchD_0800204c_caseD_3f3f:
    if (param_2 - 5U < 2) goto LAB_08002362;
switchD_0800204c_caseD_3f40:
    if (*(int *)(iVar3 + 8) != 0) {
      uVar21 = uVar21 >> (uVar19 & 7);
      uVar19 = uVar19 & 0xfffffff8;
      uVar11 = 0x3f4e;
      goto LAB_08002098;
    }
    for (; uVar19 < 3; uVar19 = uVar19 + 8) {
      if (uVar23 == 0) goto LAB_08002362;
      uVar23 = uVar23 - 1;
      uVar21 = uVar21 + ((uint)*pbVar24 << (uVar19 & 0xff));
      pbVar24 = pbVar24 + 1;
    }
    *(uint *)(iVar3 + 8) = uVar21 & 1;
    uVar18 = (uVar21 & 7) >> 1;
    uVar21 = uVar21 >> 3;
    if (uVar18 == 2) {
      uVar11 = 0x3f44;
LAB_08002596:
      *(undefined2 *)(iVar3 + 4) = uVar11;
    }
    else {
      if (uVar18 == 3) {
        param_1[6] = DAT_08002758;
        uVar11 = 0x3f51;
        goto LAB_08002596;
      }
      if (uVar18 != 1) {
        uVar11 = 0x3f41;
        goto LAB_08002596;
      }
      *(undefined4 *)(iVar3 + 0x50) = DAT_08002750;
      *(undefined4 *)(iVar3 + 0x58) = 9;
      *(undefined4 *)(iVar3 + 0x54) = DAT_08002754;
      *(undefined4 *)(iVar3 + 0x5c) = 5;
      *(undefined2 *)(iVar3 + 4) = 0x3f47;
      if (param_2 == 6) {
        uVar19 = uVar19 - 3;
        goto LAB_08002362;
      }
    }
    uVar19 = uVar19 - 3;
    goto LAB_08002040;
  case 0x3f3f:
    goto switchD_0800204c_caseD_3f3f;
  case 0x3f40:
    goto switchD_0800204c_caseD_3f40;
  case 0x3f41:
    uVar21 = uVar21 >> (uVar19 & 7);
    for (uVar19 = uVar19 & 0xfffffff8; uVar19 < 0x20; uVar19 = uVar19 + 8) {
      if (uVar23 == 0) goto LAB_08002362;
      uVar23 = uVar23 - 1;
      uVar21 = uVar21 + ((uint)*pbVar24 << (uVar19 & 0xff));
      pbVar24 = pbVar24 + 1;
    }
    if ((uVar21 & 0xffff) == (uVar21 >> 0x10 ^ 0xffff)) {
      *(undefined2 *)(iVar3 + 4) = 0x3f42;
      *(uint *)(iVar3 + 0x44) = uVar21 & 0xffff;
      uVar19 = 0;
      uVar21 = 0;
      if (param_2 != 6) goto switchD_0800204c_caseD_3f42;
      goto LAB_08002362;
    }
    uVar4 = DAT_0800275c;
    break;
  case 0x3f42:
switchD_0800204c_caseD_3f42:
    *(undefined2 *)(iVar3 + 4) = 0x3f43;
  case 0x3f43:
    uVar18 = *(uint *)(iVar3 + 0x44);
    if (uVar18 == 0) goto LAB_080024ea;
    if (uVar26 <= uVar18) {
      uVar18 = uVar26;
    }
    if (uVar23 <= uVar18) {
      uVar18 = uVar23;
    }
    if (uVar18 == 0) goto LAB_08002362;
    zmemcpy(local_48,pbVar24,uVar18);
    local_48 = local_48 + uVar18;
    uVar23 = uVar23 - uVar18;
    pbVar24 = pbVar24 + uVar18;
    uVar26 = uVar26 - uVar18;
    *(uint *)(iVar3 + 0x44) = *(int *)(iVar3 + 0x44) - uVar18;
    goto LAB_08002040;
  case 0x3f44:
    for (; uVar19 < 0xe; uVar19 = uVar19 + 8) {
      if (uVar23 == 0) goto LAB_08002362;
      uVar23 = uVar23 - 1;
      uVar21 = uVar21 + ((uint)*pbVar24 << (uVar19 & 0xff));
      pbVar24 = pbVar24 + 1;
    }
    uVar18 = (uVar21 & 0x1f) + 0x101;
    uVar10 = ((uVar21 & 0x3ff) >> 5) + 1;
    *(uint *)(iVar3 + 100) = uVar18;
    *(uint *)(iVar3 + 0x68) = uVar10;
    *(uint *)(iVar3 + 0x60) = ((uVar21 & 0x3fff) >> 10) + 4;
    uVar21 = uVar21 >> 0xe;
    uVar19 = uVar19 - 0xe;
    if ((uVar18 < 0x11f) && (uVar10 < 0x1f)) {
      *(undefined4 *)(iVar3 + 0x6c) = 0;
      *(undefined2 *)(iVar3 + 4) = 0x3f45;
      goto switchD_0800204c_caseD_3f45;
    }
    uVar4 = DAT_08002760;
    break;
  case 0x3f45:
switchD_0800204c_caseD_3f45:
    uVar18 = *(uint *)(iVar3 + 0x60);
    while( true ) {
      iVar13 = DAT_08002764;
      uVar10 = *(uint *)(iVar3 + 0x6c);
      if (uVar18 <= uVar10) break;
      for (; uVar19 < 3; uVar19 = uVar19 + 8) {
        if (uVar23 == 0) goto LAB_08002362;
        uVar23 = uVar23 - 1;
        uVar21 = uVar21 + ((uint)*pbVar24 << (uVar19 & 0xff));
        pbVar24 = pbVar24 + 1;
      }
      *(uint *)(iVar3 + 0x6c) = uVar10 + 1;
      *(ushort *)(iVar3 + (uint)*(ushort *)(DAT_08002764 + uVar10 * 2) * 2 + 0x74) =
           (ushort)uVar21 & 7;
      uVar21 = uVar21 >> 3;
      uVar19 = uVar19 - 3;
    }
    while (uVar18 = *(uint *)(iVar3 + 0x6c), uVar18 < 0x13) {
      uVar2 = *(ushort *)(iVar13 + uVar18 * 2);
      *(uint *)(iVar3 + 0x6c) = uVar18 + 1;
      *(undefined2 *)(iVar3 + (uVar2 + 0x38) * 2 + 4) = 0;
    }
    *(int *)(iVar3 + 0x70) = iVar3 + 0x534;
    *(int *)(iVar3 + 0x50) = iVar3 + 0x534;
    *(undefined4 *)(iVar3 + 0x58) = 7;
    local_4c = inflate_table(0,iVar3 + 0x74,0x13,iVar3 + 0x70,iVar3 + 0x58,iVar3 + 0x2f4);
    if (local_4c == 0) {
      *(undefined4 *)(iVar3 + 0x6c) = 0;
      *(undefined2 *)(iVar3 + 4) = 0x3f46;
switchD_0800204c_caseD_3f46:
      iVar13 = *(int *)(iVar3 + 100);
      uVar18 = *(int *)(iVar3 + 0x68) + iVar13;
LAB_08002782:
      do {
        uVar10 = *(uint *)(iVar3 + 0x6c);
        if (uVar18 <= uVar10) goto LAB_080027de;
        while( true ) {
          iVar20 = *(int *)(iVar3 + 0x50) + (~(-1 << (*(uint *)(iVar3 + 0x58) & 0xff)) & uVar21) * 4
          ;
          uVar6 = (uint)*(byte *)(iVar20 + 1);
          uVar2 = *(ushort *)(iVar20 + 2);
          if (uVar6 <= uVar19) break;
          if (uVar23 == 0) goto LAB_08002362;
          uVar23 = uVar23 - 1;
          uVar21 = uVar21 + ((uint)*pbVar24 << (uVar19 & 0xff));
          uVar19 = uVar19 + 8;
          pbVar24 = pbVar24 + 1;
        }
        if (0xf < uVar2) {
          if (uVar2 == 0x10) {
            for (; uVar19 < uVar6 + 2; uVar19 = uVar19 + 8) {
              if (uVar23 == 0) goto LAB_08002362;
              uVar23 = uVar23 - 1;
              uVar21 = uVar21 + ((uint)*pbVar24 << (uVar19 & 0xff));
              pbVar24 = pbVar24 + 1;
            }
            uVar21 = uVar21 >> uVar6;
            uVar19 = uVar19 - uVar6;
            if (uVar10 != 0) {
              uVar11 = *(undefined2 *)(iVar3 + uVar10 * 2 + 0x72);
              iVar20 = (uVar21 & 3) + 3;
              uVar21 = uVar21 >> 2;
              uVar19 = uVar19 - 2;
              goto LAB_08002824;
            }
          }
          else {
            if (uVar2 == 0x11) {
              for (; uVar19 < uVar6 + 3; uVar19 = uVar19 + 8) {
                if (uVar23 == 0) goto LAB_08002362;
                uVar23 = uVar23 - 1;
                uVar21 = uVar21 + ((uint)*pbVar24 << (uVar19 & 0xff));
                pbVar24 = pbVar24 + 1;
              }
              iVar20 = (uVar21 >> uVar6 & 7) + 3;
              uVar21 = (uVar21 >> uVar6) >> 3;
              uVar19 = (uVar19 - uVar6) - 3;
            }
            else {
              for (; uVar19 < uVar6 + 7; uVar19 = uVar19 + 8) {
                if (uVar23 == 0) goto LAB_08002362;
                uVar23 = uVar23 - 1;
                uVar21 = uVar21 + ((uint)*pbVar24 << (uVar19 & 0xff));
                pbVar24 = pbVar24 + 1;
              }
              iVar20 = (uVar21 >> uVar6 & 0x7f) + 0xb;
              uVar21 = (uVar21 >> uVar6) >> 7;
              uVar19 = (uVar19 - uVar6) - 7;
            }
            uVar11 = 0;
LAB_08002824:
            uVar6 = uVar10 + iVar20;
            if (uVar6 <= uVar18) {
              puVar8 = (undefined2 *)(iVar3 + (uVar10 + 0x39) * 2);
              do {
                iVar20 = iVar20 + -1;
                puVar8 = puVar8 + 1;
                *puVar8 = uVar11;
              } while (iVar20 != 0);
              *(uint *)(iVar3 + 0x6c) = uVar6;
              goto LAB_08002782;
            }
          }
          param_1[6] = DAT_08002acc;
          *(undefined2 *)(iVar3 + 4) = 0x3f51;
          goto LAB_080027de;
        }
        uVar21 = uVar21 >> uVar6;
        uVar19 = uVar19 - uVar6;
        *(uint *)(iVar3 + 0x6c) = uVar10 + 1;
        *(ushort *)(iVar3 + uVar10 * 2 + 0x74) = uVar2;
      } while( true );
    }
    uVar4 = DAT_08002768;
    break;
  case 0x3f46:
    goto switchD_0800204c_caseD_3f46;
  case 0x3f47:
    goto switchD_0800204c_caseD_3f47;
  case 0x3f48:
    goto switchD_0800204c_caseD_3f48;
  case 0x3f49:
    goto switchD_0800204c_caseD_3f49;
  case 0x3f4a:
    goto switchD_0800204c_caseD_3f4a;
  case 0x3f4b:
    goto switchD_0800204c_caseD_3f4b;
  case 0x3f4c:
    goto switchD_0800204c_caseD_3f4c;
  case 0x3f4d:
    if (uVar26 == 0) goto LAB_08002362;
    *local_48 = (char)*(undefined4 *)(iVar3 + 0x44);
    uVar26 = uVar26 - 1;
    *(undefined2 *)(iVar3 + 4) = 0x3f48;
    local_48 = local_48 + 1;
    goto LAB_08002040;
  case 0x3f4e:
    iVar13 = *(int *)(iVar3 + 0xc);
    if (iVar13 == 0) {
LAB_08002c5e:
      *(undefined2 *)(iVar3 + 4) = 0x3f4f;
      goto switchD_0800204c_caseD_3f4f;
    }
    for (; uVar19 < 0x20; uVar19 = uVar19 + 8) {
      if (uVar23 == 0) goto LAB_08002362;
      uVar23 = uVar23 - 1;
      uVar21 = uVar21 + ((uint)*pbVar24 << (uVar19 & 0xff));
      pbVar24 = pbVar24 + 1;
    }
    iVar20 = local_44 - uVar26;
    param_1[5] = param_1[5] + iVar20;
    *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + iVar20;
    if (-1 < iVar13 << 0x1d) {
LAB_08002cee:
      uVar19 = 0;
      uVar21 = 0;
      local_44 = uVar26;
      goto LAB_08002c5e;
    }
    if (iVar20 != 0) {
      if (*(int *)(iVar3 + 0x14) == 0) {
        uVar4 = adler32(*(undefined4 *)(iVar3 + 0x1c),local_48 + (uVar26 - local_44));
      }
      else {
        uVar4 = crc32();
      }
      iVar13 = *(int *)(iVar3 + 0xc);
      *(undefined4 *)(iVar3 + 0x1c) = uVar4;
      param_1[0xc] = uVar4;
      if (-1 < iVar13 << 0x1d) goto LAB_08002cee;
    }
    if (*(int *)(iVar3 + 0x14) == 0) {
      uVar18 = uVar21 << 0x18 | (uVar21 >> 8 & 0xff) << 0x10 | (uVar21 >> 0x10 & 0xff) << 8 |
               uVar21 >> 0x18;
    }
    else {
      uVar18 = uVar21;
    }
    if (*(uint *)(iVar3 + 0x1c) == uVar18) goto LAB_08002cee;
    param_1[6] = DAT_08002de4;
    *(undefined2 *)(iVar3 + 4) = 0x3f51;
    local_44 = uVar26;
    goto LAB_08002040;
  case 0x3f4f:
switchD_0800204c_caseD_3f4f:
    if ((*(uint *)(iVar3 + 0xc) != 0) && (*(int *)(iVar3 + 0x14) != 0)) {
      for (; uVar19 < 0x20; uVar19 = uVar19 + 8) {
        if (uVar23 == 0) goto LAB_08002362;
        uVar23 = uVar23 - 1;
        uVar21 = uVar21 + ((uint)*pbVar24 << (uVar19 & 0xff));
        pbVar24 = pbVar24 + 1;
      }
      if (((*(uint *)(iVar3 + 0xc) & 4) != 0) && (*(uint *)(iVar3 + 0x20) != uVar21)) {
        uVar4 = DAT_08002de8;
        break;
      }
      uVar19 = 0;
      uVar21 = 0;
    }
    *(undefined2 *)(iVar3 + 4) = 0x3f50;
  case 0x3f50:
    goto switchD_0800204c_caseD_3f50;
  case 0x3f51:
    local_4c = -3;
    goto LAB_08002362;
  case 0x3f52:
    goto switchD_0800204c_caseD_3f52;
  default:
    goto switchD_0800204c_default;
  }
  goto LAB_08002090;
switchD_0800204c_caseD_3f50:
  local_4c = 1;
LAB_08002362:
  param_1[3] = local_48;
  param_1[4] = uVar26;
  iVar13 = *(int *)(iVar3 + 0x2c);
  *param_1 = pbVar24;
  param_1[1] = uVar23;
  *(uint *)(iVar3 + 0x3c) = uVar21;
  *(uint *)(iVar3 + 0x40) = uVar19;
  if (((iVar13 == 0) &&
      (((uVar26 == local_44 || (0x3f50 < *(ushort *)(iVar3 + 4))) ||
       ((0x3f4d < *(ushort *)(iVar3 + 4) && (param_2 == 4)))))) ||
     (iVar13 = updatewindow(param_1,local_48,local_44 - uVar26), iVar13 == 0)) {
    iVar20 = param_1[1];
    iVar13 = param_1[4];
    iVar22 = local_44 - iVar13;
    param_1[2] = param_1[2] + (uVar12 - iVar20);
    param_1[5] = param_1[5] + iVar22;
    *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + iVar22;
    if ((*(int *)(iVar3 + 0xc) << 0x1d < 0) && (iVar22 != 0)) {
      if (*(int *)(iVar3 + 0x14) == 0) {
        uVar4 = adler32(*(undefined4 *)(iVar3 + 0x1c),param_1[3] + (iVar13 - local_44),iVar22);
      }
      else {
        uVar4 = crc32();
      }
      *(undefined4 *)(iVar3 + 0x1c) = uVar4;
      param_1[0xc] = uVar4;
    }
    sVar1 = *(short *)(iVar3 + 4);
    if (sVar1 == 0x3f47) {
      iVar13 = 0x100;
    }
    else {
      iVar13 = (uint)(sVar1 == 0x3f42) * 0x100;
    }
    param_1[0xb] = iVar13 + *(int *)(iVar3 + 0x40) + (uint)(*(int *)(iVar3 + 8) != 0) * 0x40 +
                            (uint)(sVar1 == 0x3f3f) * 0x80;
    if ((iVar22 != 0 || uVar12 - iVar20 != 0) && (param_2 != 4)) {
      return local_4c;
    }
    if (local_4c == 0) {
      return -5;
    }
    return local_4c;
  }
  *(undefined2 *)(iVar3 + 4) = 0x3f52;
  goto switchD_0800204c_caseD_3f52;
LAB_080027de:
  if (*(short *)(iVar3 + 4) == 0x3f51) goto LAB_08002040;
  if (*(short *)(iVar3 + 0x274) == 0) {
    uVar4 = DAT_08002ad0;
LAB_080027f4:
    param_1[6] = uVar4;
    *(undefined2 *)(iVar3 + 4) = 0x3f51;
    goto LAB_08002040;
  }
  *(int *)(iVar3 + 0x70) = iVar3 + 0x534;
  *(int *)(iVar3 + 0x50) = iVar3 + 0x534;
  *(undefined4 *)(iVar3 + 0x58) = 9;
  local_4c = inflate_table(1,iVar3 + 0x74,iVar13,iVar3 + 0x70,iVar3 + 0x58,iVar3 + 0x2f4);
  if (local_4c != 0) {
    uVar4 = DAT_08002ad4;
    goto LAB_080027f4;
  }
  *(undefined4 *)(iVar3 + 0x54) = *(undefined4 *)(iVar3 + 0x70);
  *(undefined4 *)(iVar3 + 0x5c) = 6;
  local_4c = inflate_table(2,iVar3 + 0x74 + *(int *)(iVar3 + 100) * 2,*(undefined4 *)(iVar3 + 0x68),
                           iVar3 + 0x70,iVar3 + 0x5c,iVar3 + 0x2f4);
  if (local_4c != 0) {
    uVar4 = DAT_08002ad8;
    goto LAB_080027f4;
  }
  *(undefined2 *)(iVar3 + 4) = 0x3f47;
  if (param_2 == 6) goto LAB_08002362;
switchD_0800204c_caseD_3f47:
  *(undefined2 *)(iVar3 + 4) = 0x3f48;
switchD_0800204c_caseD_3f48:
  if ((5 < uVar23) && (0x101 < uVar26)) {
    param_1[3] = local_48;
    param_1[4] = uVar26;
    *param_1 = pbVar24;
    param_1[1] = uVar23;
    *(uint *)(iVar3 + 0x3c) = uVar21;
    *(uint *)(iVar3 + 0x40) = uVar19;
    inflate_fast(param_1,local_44);
    local_48 = (undefined1 *)param_1[3];
    pbVar24 = (byte *)*param_1;
    uVar23 = param_1[1];
    uVar19 = *(uint *)(iVar3 + 0x40);
    uVar26 = param_1[4];
    uVar21 = *(uint *)(iVar3 + 0x3c);
    if (*(short *)(iVar3 + 4) == 0x3f3f) {
      *(undefined4 *)(iVar3 + 0x1bc8) = 0xffffffff;
    }
    goto LAB_08002040;
  }
  *(undefined4 *)(iVar3 + 0x1bc8) = 0;
  iVar13 = *(int *)(iVar3 + 0x50);
  while( true ) {
    uVar18 = ~(-1 << (*(uint *)(iVar3 + 0x58) & 0xff)) & uVar21;
    iVar20 = iVar13 + uVar18 * 4;
    uVar10 = (uint)*(byte *)(iVar13 + uVar18 * 4);
    uVar18 = (uint)*(byte *)(iVar20 + 1);
    uVar6 = (uint)*(ushort *)(iVar20 + 2);
    if (uVar18 <= uVar19) break;
    if (uVar23 == 0) goto LAB_08002362;
    uVar23 = uVar23 - 1;
    uVar21 = uVar21 + ((uint)*pbVar24 << (uVar19 & 0xff));
    uVar19 = uVar19 + 8;
    pbVar24 = pbVar24 + 1;
  }
  uVar9 = uVar18;
  uVar25 = uVar6;
  if ((uVar10 != 0) && (uVar10 < 0x10)) {
    uVar14 = uVar10 + uVar18;
    while( true ) {
      iVar20 = ((~(-1 << (uVar14 & 0xff)) & uVar21) >> uVar18) + uVar6;
      iVar22 = iVar13 + iVar20 * 4;
      uVar10 = (uint)*(byte *)(iVar13 + iVar20 * 4);
      uVar9 = (uint)*(byte *)(iVar22 + 1);
      uVar25 = (uint)*(ushort *)(iVar22 + 2);
      if (uVar9 + uVar18 <= uVar19) break;
      if (uVar23 == 0) goto LAB_08002362;
      uVar23 = uVar23 - 1;
      uVar21 = uVar21 + ((uint)*pbVar24 << (uVar19 & 0xff));
      uVar19 = uVar19 + 8;
      pbVar24 = pbVar24 + 1;
    }
    uVar21 = uVar21 >> uVar18;
    uVar19 = uVar19 - uVar18;
    *(uint *)(iVar3 + 0x1bc8) = uVar18;
  }
  uVar21 = uVar21 >> uVar9;
  *(uint *)(iVar3 + 0x1bc8) = *(int *)(iVar3 + 0x1bc8) + uVar9;
  uVar19 = uVar19 - uVar9;
  *(uint *)(iVar3 + 0x44) = uVar25;
  if (uVar10 == 0) {
    uVar11 = 0x3f4d;
    goto LAB_08002098;
  }
  if ((int)(uVar10 << 0x1a) < 0) {
    *(undefined4 *)(iVar3 + 0x1bc8) = 0xffffffff;
LAB_080024ea:
    uVar11 = 0x3f3f;
    goto LAB_08002098;
  }
  if ((int)(uVar10 << 0x19) < 0) {
    uVar4 = DAT_08002adc;
  }
  else {
    *(uint *)(iVar3 + 0x4c) = uVar10 & 0xf;
    *(undefined2 *)(iVar3 + 4) = 0x3f49;
switchD_0800204c_caseD_3f49:
    uVar18 = *(uint *)(iVar3 + 0x4c);
    if (uVar18 != 0) {
      for (; uVar19 < uVar18; uVar19 = uVar19 + 8) {
        if (uVar23 == 0) goto LAB_08002362;
        uVar23 = uVar23 - 1;
        uVar21 = uVar21 + ((uint)*pbVar24 << (uVar19 & 0xff));
        pbVar24 = pbVar24 + 1;
      }
      *(uint *)(iVar3 + 0x44) = *(int *)(iVar3 + 0x44) + (uVar21 & ~(-1 << (uVar18 & 0xff)));
      uVar21 = uVar21 >> (uVar18 & 0xff);
      uVar19 = uVar19 - uVar18;
      *(uint *)(iVar3 + 0x1bc8) = *(int *)(iVar3 + 0x1bc8) + uVar18;
    }
    *(undefined4 *)(iVar3 + 0x1bcc) = *(undefined4 *)(iVar3 + 0x44);
    *(undefined2 *)(iVar3 + 4) = 0x3f4a;
switchD_0800204c_caseD_3f4a:
    iVar13 = *(int *)(iVar3 + 0x54);
    while( true ) {
      uVar18 = ~(-1 << (*(uint *)(iVar3 + 0x5c) & 0xff)) & uVar21;
      iVar20 = iVar13 + uVar18 * 4;
      uVar10 = (uint)*(byte *)(iVar13 + uVar18 * 4);
      uVar18 = (uint)*(byte *)(iVar20 + 1);
      uVar6 = (uint)*(ushort *)(iVar20 + 2);
      if (uVar18 <= uVar19) break;
      if (uVar23 == 0) goto LAB_08002362;
      uVar23 = uVar23 - 1;
      uVar21 = uVar21 + ((uint)*pbVar24 << (uVar19 & 0xff));
      uVar19 = uVar19 + 8;
      pbVar24 = pbVar24 + 1;
    }
    uVar9 = uVar18;
    uVar25 = uVar6;
    if (uVar10 < 0x10) {
      uVar14 = uVar10 + uVar18;
      while( true ) {
        iVar20 = ((~(-1 << (uVar14 & 0xff)) & uVar21) >> uVar18) + uVar6;
        iVar22 = iVar13 + iVar20 * 4;
        uVar10 = (uint)*(byte *)(iVar13 + iVar20 * 4);
        uVar9 = (uint)*(byte *)(iVar22 + 1);
        uVar25 = (uint)*(ushort *)(iVar22 + 2);
        if (uVar9 + uVar18 <= uVar19) break;
        if (uVar23 == 0) goto LAB_08002362;
        uVar23 = uVar23 - 1;
        uVar21 = uVar21 + ((uint)*pbVar24 << (uVar19 & 0xff));
        uVar19 = uVar19 + 8;
        pbVar24 = pbVar24 + 1;
      }
      uVar21 = uVar21 >> uVar18;
      uVar19 = uVar19 - uVar18;
      *(uint *)(iVar3 + 0x1bc8) = *(int *)(iVar3 + 0x1bc8) + uVar18;
    }
    uVar21 = uVar21 >> uVar9;
    *(uint *)(iVar3 + 0x1bc8) = *(int *)(iVar3 + 0x1bc8) + uVar9;
    uVar19 = uVar19 - uVar9;
    if (-1 < (int)(uVar10 << 0x19)) {
      *(uint *)(iVar3 + 0x4c) = uVar10 & 0xf;
      *(uint *)(iVar3 + 0x48) = uVar25;
      *(undefined2 *)(iVar3 + 4) = 0x3f4b;
switchD_0800204c_caseD_3f4b:
      uVar18 = *(uint *)(iVar3 + 0x4c);
      if (uVar18 != 0) {
        for (; uVar19 < uVar18; uVar19 = uVar19 + 8) {
          if (uVar23 == 0) goto LAB_08002362;
          uVar23 = uVar23 - 1;
          uVar21 = uVar21 + ((uint)*pbVar24 << (uVar19 & 0xff));
          pbVar24 = pbVar24 + 1;
        }
        *(uint *)(iVar3 + 0x48) = *(int *)(iVar3 + 0x48) + (uVar21 & ~(-1 << (uVar18 & 0xff)));
        uVar21 = uVar21 >> (uVar18 & 0xff);
        uVar19 = uVar19 - uVar18;
        *(uint *)(iVar3 + 0x1bc8) = *(int *)(iVar3 + 0x1bc8) + uVar18;
      }
      *(undefined2 *)(iVar3 + 4) = 0x3f4c;
switchD_0800204c_caseD_3f4c:
      if (uVar26 == 0) goto LAB_08002362;
      uVar18 = *(uint *)(iVar3 + 0x48);
      if (local_44 - uVar26 < uVar18) {
        uVar10 = (uVar18 + uVar26) - local_44;
        if ((*(uint *)(iVar3 + 0x30) < uVar10) && (*(int *)(iVar3 + 0x1bc4) != 0)) {
          uVar4 = DAT_08002de0;
          goto LAB_08002090;
        }
        uVar6 = *(uint *)(iVar3 + 0x34);
        if (uVar6 < uVar10) {
          uVar10 = uVar10 - uVar6;
          uVar6 = uVar6 + *(int *)(iVar3 + 0x2c);
        }
        puVar15 = (undefined1 *)(*(int *)(iVar3 + 0x38) + uVar6 + (local_44 - (uVar18 + uVar26)));
        if (*(uint *)(iVar3 + 0x44) <= uVar10) {
          uVar10 = *(uint *)(iVar3 + 0x44);
        }
      }
      else {
        puVar15 = local_48 + -uVar18;
        uVar10 = *(uint *)(iVar3 + 0x44);
      }
      if (uVar26 <= uVar10) {
        uVar10 = uVar26;
      }
      *(uint *)(iVar3 + 0x44) = *(int *)(iVar3 + 0x44) - uVar10;
      uVar26 = uVar26 - uVar10;
      puVar7 = local_48 + -1;
      puVar17 = puVar15;
      do {
        puVar16 = puVar17 + 1;
        puVar7 = puVar7 + 1;
        *puVar7 = *puVar17;
        puVar17 = puVar16;
      } while (puVar16 != puVar15 + uVar10);
      local_48 = local_48 + uVar10;
      if (*(int *)(iVar3 + 0x44) != 0) goto LAB_08002040;
      uVar11 = 0x3f48;
      goto LAB_08002098;
    }
    uVar4 = DAT_08002ddc;
  }
LAB_08002090:
  param_1[6] = uVar4;
  uVar11 = 0x3f51;
LAB_08002098:
  *(undefined2 *)(iVar3 + 4) = uVar11;
  goto LAB_08002040;
switchD_0800204c_caseD_3f52:
  return -4;
}




undefined4 inflateEnd(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar2;
  
  iVar1 = inflateStateCheck();
  if (iVar1 == 0) {
    uVar2 = extraout_r2;
    if (*(int *)(*(int *)(param_1 + 0x1c) + 0x38) != 0) {
      (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28));
      uVar2 = extraout_r2_00;
    }
    (**(code **)(param_1 + 0x24))
              (*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x1c),uVar2,
               *(code **)(param_1 + 0x24),param_4);
    *(undefined4 *)(param_1 + 0x1c) = 0;
    uVar2 = 0;
  }
  else {
    uVar2 = 0xfffffffe;
  }
  return uVar2;
}




void inflate_fast(undefined4 *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined2 uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  undefined4 uVar20;
  undefined1 *puVar21;
  undefined1 *puVar22;
  undefined1 *puVar23;
  uint uVar24;
  uint uVar25;
  byte *pbVar26;
  uint uVar27;
  uint uVar28;
  int iVar29;
  uint uVar30;
  
  pbVar8 = (byte *)*param_1;
  pbVar9 = pbVar8 + param_1[1] + -5;
  puVar10 = (undefined1 *)param_1[3];
  iVar14 = param_1[4];
  iVar2 = param_1[7];
  puVar3 = puVar10 + iVar14 + -0x101;
  iVar15 = *(int *)(iVar2 + 0x50);
  iVar4 = *(int *)(iVar2 + 0x2c);
  uVar5 = *(uint *)(iVar2 + 0x30);
  iVar16 = *(int *)(iVar2 + 0x54);
  uVar30 = *(uint *)(iVar2 + 0x34);
  puVar6 = *(undefined1 **)(iVar2 + 0x38);
  uVar17 = *(uint *)(iVar2 + 0x5c);
  uVar18 = *(uint *)(iVar2 + 0x58);
  uVar24 = *(uint *)(iVar2 + 0x3c);
  uVar7 = *(uint *)(iVar2 + 0x40);
  puVar12 = puVar10;
LAB_08002e70:
  if (uVar7 < 0xf) {
    uVar24 = uVar24 + ((uint)pbVar8[1] << (uVar7 + 8 & 0xff)) + ((uint)*pbVar8 << (uVar7 & 0xff));
    uVar7 = uVar7 + 0x10;
    pbVar8 = pbVar8 + 2;
  }
  uVar25 = ~(-1 << (uVar18 & 0xff)) & uVar24;
  while( true ) {
    pbVar26 = (byte *)(iVar15 + uVar25 * 4);
    uVar24 = uVar24 >> (uint)pbVar26[1];
    uVar7 = uVar7 - pbVar26[1];
    uVar25 = (uint)*pbVar26;
    if (uVar25 == 0) break;
    if ((int)(uVar25 << 0x1b) < 0) {
      uVar25 = uVar25 & 0xf;
      uVar27 = (uint)*(ushort *)(pbVar26 + 2);
      if ((*pbVar26 & 0xf) != 0) {
        if (uVar7 < uVar25) {
          uVar24 = uVar24 + ((uint)*pbVar8 << (uVar7 & 0xff));
          pbVar8 = pbVar8 + 1;
        }
        if (uVar7 < uVar25) {
          uVar7 = uVar7 + 8;
        }
        uVar27 = uVar27 + (uVar24 & ~(-1 << uVar25));
        uVar24 = uVar24 >> uVar25;
        uVar7 = uVar7 - uVar25;
      }
      if (uVar7 < 0xf) {
        uVar24 = uVar24 + ((uint)pbVar8[1] << (uVar7 + 8 & 0xff)) +
                          ((uint)*pbVar8 << (uVar7 & 0xff));
        uVar7 = uVar7 + 0x10;
        pbVar8 = pbVar8 + 2;
      }
      uVar25 = uVar24 & ~(-1 << (uVar17 & 0xff));
      goto LAB_08002f0e;
    }
    if ((int)(uVar25 << 0x19) < 0) {
      if ((int)(uVar25 << 0x1a) < 0) {
        uVar13 = 0x3f3f;
        goto LAB_08002f88;
      }
      uVar20 = DAT_08003178;
      goto LAB_08002f80;
    }
    uVar25 = (uVar24 & ~(-1 << uVar25)) + (uint)*(ushort *)(pbVar26 + 2);
  }
  puVar11 = puVar12 + 1;
  *puVar12 = (char)*(undefined2 *)(pbVar26 + 2);
  goto LAB_08002ea4;
LAB_08002f0e:
  pbVar26 = (byte *)(iVar16 + uVar25 * 4);
  uVar24 = uVar24 >> (uint)pbVar26[1];
  uVar7 = uVar7 - pbVar26[1];
  bVar1 = *pbVar26;
  if ((bVar1 & 0x10) != 0) goto code_r0x08002f1e;
  if ((bVar1 & 0x40) != 0) {
    uVar20 = DAT_08003174;
    goto LAB_08002f80;
  }
  uVar25 = (uVar24 & ~(-1 << (uint)bVar1)) + (uint)*(ushort *)(pbVar26 + 2);
  goto LAB_08002f0e;
code_r0x08002f1e:
  uVar19 = bVar1 & 0xf;
  uVar25 = uVar7;
  if (uVar7 < uVar19) {
    uVar25 = uVar7 + 8;
    uVar24 = uVar24 + ((uint)*pbVar8 << (uVar7 & 0xff));
    if (uVar25 < uVar19) {
      uVar24 = uVar24 + ((uint)pbVar8[1] << (uVar25 & 0xff));
      uVar25 = uVar7 + 0x10;
      pbVar8 = pbVar8 + 2;
    }
    else {
      pbVar8 = pbVar8 + 1;
    }
  }
  uVar28 = uVar24 & ~(-1 << uVar19);
  uVar7 = uVar25 - uVar19;
  uVar24 = uVar24 >> uVar19;
  uVar28 = uVar28 + *(ushort *)(pbVar26 + 2);
  uVar25 = (int)puVar12 - (int)(puVar10 + (iVar14 - param_2));
  if (uVar28 <= uVar25) {
    puVar21 = puVar12 + -uVar28;
    do {
      puVar22 = puVar21;
      puVar23 = puVar12;
      *puVar23 = *puVar22;
      puVar23[1] = puVar22[1];
      uVar27 = uVar27 - 3;
      puVar11 = puVar23 + 3;
      puVar23[2] = puVar22[2];
      puVar12 = puVar11;
      puVar21 = puVar22 + 3;
    } while (2 < uVar27);
    if (uVar27 != 0) {
      puVar23[3] = puVar22[3];
      if (uVar27 == 2) {
        puVar23[4] = puVar22[4];
        puVar11 = puVar23 + 5;
      }
      else {
        puVar11 = puVar23 + 4;
      }
    }
    goto LAB_08002ea4;
  }
  uVar19 = uVar28 - uVar25;
  if ((uVar5 < uVar19) && (*(int *)(iVar2 + 0x1bc4) != 0)) {
    uVar20 = DAT_08003170;
LAB_08002f80:
    param_1[6] = uVar20;
    uVar13 = 0x3f51;
LAB_08002f88:
    *(undefined2 *)(iVar2 + 4) = uVar13;
    puVar11 = puVar12;
LAB_08002f8a:
    pbVar8 = pbVar8 + -(uVar7 >> 3);
    *param_1 = pbVar8;
    param_1[3] = puVar11;
    if (pbVar8 < pbVar9) {
      iVar4 = (int)pbVar9 - (int)pbVar8;
    }
    else {
      iVar4 = -((int)pbVar8 - (int)pbVar9);
    }
    param_1[1] = iVar4 + 5;
    if (puVar11 < puVar3) {
      iVar4 = (int)puVar3 - (int)puVar11;
    }
    else {
      iVar4 = -((int)puVar11 - (int)puVar3);
    }
    param_1[4] = iVar4 + 0x101;
    *(uint *)(iVar2 + 0x3c) = uVar24 & ~(-1 << (uVar7 & 7));
    *(uint *)(iVar2 + 0x40) = uVar7 & 7;
    return;
  }
  iVar29 = uVar25 - uVar28;
  if (uVar30 == 0) {
    puVar21 = puVar6 + iVar4 + iVar29;
    if (uVar19 < uVar27) {
      uVar27 = uVar27 + iVar29;
      puVar11 = puVar12 + -1;
      puVar23 = puVar21;
      do {
        puVar22 = puVar23 + 1;
        puVar11 = puVar11 + 1;
        *puVar11 = *puVar23;
        puVar23 = puVar22;
      } while (puVar22 != puVar21 + uVar19);
LAB_08003010:
      puVar12 = puVar12 + uVar19;
      puVar21 = puVar12 + -uVar28;
    }
  }
  else if (uVar30 < uVar19) {
    puVar21 = puVar6 + iVar4 + uVar30 + iVar29;
    uVar25 = uVar19 - uVar30;
    if (uVar25 < uVar27) {
      uVar27 = uVar27 + uVar30 + iVar29;
      puVar11 = puVar12 + -1;
      puVar23 = puVar21;
      do {
        puVar22 = puVar23 + 1;
        puVar11 = puVar11 + 1;
        *puVar11 = *puVar23;
        puVar23 = puVar22;
      } while (puVar22 != puVar21 + uVar25);
      if (uVar30 < uVar27) {
        uVar27 = uVar27 - uVar30;
        puVar11 = puVar12 + uVar25 + -1;
        puVar21 = puVar6;
        do {
          puVar23 = puVar21 + 1;
          puVar11 = puVar11 + 1;
          *puVar11 = *puVar21;
          puVar21 = puVar23;
        } while (puVar23 != puVar6 + uVar30);
        goto LAB_08003010;
      }
      puVar12 = puVar12 + uVar25;
      puVar21 = puVar6;
    }
  }
  else {
    puVar21 = puVar6 + uVar30 + iVar29;
    if (uVar19 < uVar27) {
      uVar27 = uVar27 + iVar29;
      puVar11 = puVar12 + -1;
      puVar23 = puVar21;
      do {
        puVar22 = puVar23 + 1;
        puVar11 = puVar11 + 1;
        *puVar11 = *puVar23;
        puVar23 = puVar22;
      } while (puVar22 != puVar21 + uVar19);
      goto LAB_08003010;
    }
  }
  puVar11 = puVar12;
  while( true ) {
    if (uVar27 < 3) break;
    *puVar11 = *puVar21;
    puVar11[1] = puVar21[1];
    puVar11[2] = puVar21[2];
    uVar27 = uVar27 - 3;
    puVar21 = puVar21 + 3;
    puVar11 = puVar11 + 3;
  }
  if (uVar27 != 0) {
    *puVar11 = *puVar21;
    if (uVar27 == 2) {
      puVar11[1] = puVar21[1];
      puVar11 = puVar11 + 2;
    }
    else {
      puVar11 = puVar11 + 1;
    }
  }
LAB_08002ea4:
  if ((pbVar9 <= pbVar8) || (puVar12 = puVar11, puVar3 <= puVar11)) goto LAB_08002f8a;
  goto LAB_08002e70;
}




undefined4
inflate_table(int param_1,ushort *param_2,int param_3,int *param_4,uint *param_5,ushort *param_6)

{
  char cVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  ushort *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined2 *puVar10;
  uint uVar11;
  undefined1 *puVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  ushort uVar16;
  ushort *puVar17;
  uint uVar18;
  uint uVar19;
  bool bVar20;
  bool bVar21;
  uint local_9c;
  uint local_94;
  ushort *local_84;
  uint local_7c;
  ushort *local_78;
  ushort *local_74;
  ushort auStack_68 [16];
  ushort auStack_48 [18];
  
  memset(auStack_68,0,0x20);
  for (puVar6 = param_2; param_2 + param_3 != puVar6; puVar6 = puVar6 + 1) {
    auStack_68[*puVar6] = auStack_68[*puVar6] + 1;
  }
  uVar3 = *param_5;
  uVar5 = 0xf;
  while (auStack_68[uVar5] == 0) {
    uVar5 = uVar5 - 1;
    if (uVar5 == 0) {
      puVar10 = (undefined2 *)*param_4;
      *puVar10 = 0x140;
      puVar10[1] = 0;
      uVar3 = 1;
      *param_4 = (int)(puVar10 + 4);
      puVar10[2] = 0x140;
      puVar10[3] = 0;
LAB_08003464:
      *param_5 = uVar3;
      return 0;
    }
  }
  puVar17 = auStack_68;
  uVar11 = 1;
  puVar6 = puVar17;
  while ((uVar5 != uVar11 && (puVar6 = puVar6 + 1, *puVar6 == 0))) {
    uVar11 = uVar11 + 1;
  }
  iVar7 = 2 - (uint)auStack_68[1];
  if (iVar7 < 0) {
    return 0xffffffff;
  }
  iVar14 = 1;
  while (iVar14 = iVar14 + 1, iVar14 != 0x10) {
    iVar7 = iVar7 * 2 - (uint)auStack_68[iVar14];
    if (iVar7 < 0) {
      return 0xffffffff;
    }
  }
  if (iVar7 != 0) {
    if (param_1 == 0) {
      return 0xffffffff;
    }
    if (uVar5 != 1) {
      return 0xffffffff;
    }
  }
  auStack_48[1] = 0;
  iVar7 = 1;
  puVar6 = auStack_48;
  do {
    puVar17 = puVar17 + 1;
    iVar7 = iVar7 + 1;
    puVar6[2] = puVar6[1] + *puVar17;
    puVar6 = puVar6 + 1;
  } while (iVar7 != 0xf);
  for (iVar7 = 0; iVar7 != param_3; iVar7 = iVar7 + 1) {
    uVar13 = (uint)param_2[iVar7];
    if (uVar13 != 0) {
      uVar16 = auStack_48[uVar13];
      param_6[uVar16] = (ushort)iVar7;
      auStack_48[uVar13] = uVar16 + 1;
    }
  }
  if (param_1 == 0) {
    local_78 = param_6;
    local_74 = param_6;
    local_94 = 0x14;
  }
  else {
    local_94 = 0x101;
    if (param_1 == 1) {
      local_78 = DAT_08003480;
      local_74 = DAT_08003478;
    }
    else {
      local_94 = 0;
      local_78 = DAT_08003484;
      local_74 = DAT_0800347c;
    }
  }
  if (uVar5 <= uVar3) {
    uVar3 = uVar5;
  }
  iVar7 = *param_4;
  if (uVar3 < uVar11) {
    uVar3 = uVar11;
  }
  uVar13 = 1 << (uVar3 & 0xff);
  if (param_1 == 1) {
    bVar21 = 0x353 < uVar13;
    bVar20 = uVar13 == 0x354;
LAB_0800327a:
    if (bVar21 && !bVar20) {
      return 1;
    }
  }
  else if (param_1 == 2) {
    bVar21 = 0x24f < uVar13;
    bVar20 = uVar13 == 0x250;
    goto LAB_0800327a;
  }
  uVar8 = uVar13 - 1;
  local_84 = param_6;
  local_7c = 0xffffffff;
  local_9c = 0;
  uVar9 = uVar3;
  iVar14 = iVar7;
  uVar19 = 0;
  do {
    cVar1 = (char)uVar11 - (char)local_9c;
    uVar16 = *local_84;
    uVar18 = (uint)uVar16;
    if (uVar18 + 1 < local_94) {
      uVar2 = 0;
    }
    else if (uVar18 < local_94) {
      uVar16 = 0;
      uVar2 = 0x60;
    }
    else {
      uVar2 = (undefined1)local_74[uVar18 - local_94];
      uVar16 = local_78[uVar18 - local_94];
    }
    iVar4 = 1 << (uVar11 - local_9c & 0xff);
    iVar15 = 1 << (uVar9 & 0xff);
    puVar12 = (undefined1 *)(iVar14 + (((uVar19 >> (local_9c & 0xff)) + iVar15) - iVar4) * 4);
    do {
      *puVar12 = uVar2;
      puVar12[1] = cVar1;
      *(ushort *)(puVar12 + 2) = uVar16;
      iVar15 = iVar15 - iVar4;
      puVar12 = puVar12 + (-4 << (uVar11 - local_9c & 0xff));
    } while (iVar15 != 0);
    for (uVar18 = 1 << (uVar11 - 1 & 0xff); (uVar19 & uVar18) != 0; uVar18 = uVar18 >> 1) {
    }
    if (uVar18 != 0) {
      uVar18 = uVar18 + (uVar18 - 1 & uVar19);
    }
    uVar16 = auStack_68[uVar11];
    auStack_68[uVar11] = uVar16 - 1;
    if ((ushort)(uVar16 - 1) == 0) {
      if (uVar5 == uVar11) {
        if (uVar18 != 0) {
          iVar4 = iVar14 + uVar18 * 4;
          *(undefined1 *)(iVar14 + uVar18 * 4) = 0x40;
          *(char *)(iVar4 + 1) = cVar1;
          *(undefined2 *)(iVar4 + 2) = 0;
        }
        *param_4 = iVar7 + uVar13 * 4;
        goto LAB_08003464;
      }
      uVar11 = (uint)param_2[local_84[1]];
    }
    if (uVar3 < uVar11) {
      uVar19 = uVar18 & uVar8;
      if (uVar19 != local_7c) {
        if (local_9c == 0) {
          local_9c = uVar3;
        }
        iVar14 = iVar14 + (4 << (uVar9 & 0xff));
        uVar9 = uVar11 - local_9c;
        for (iVar4 = 1 << (uVar9 & 0xff);
            (uVar9 + local_9c < uVar5 &&
            (iVar15 = local_9c + uVar9, 0 < (int)(iVar4 - (uint)auStack_68[iVar15])));
            iVar4 = (iVar4 - (uint)auStack_68[iVar15]) * 2) {
          uVar9 = uVar9 + 1;
        }
        uVar13 = uVar13 + (1 << (uVar9 & 0xff));
        if (param_1 == 1) {
          bVar21 = 0x353 < uVar13;
          bVar20 = uVar13 == 0x354;
LAB_080033ee:
          if (bVar21 && !bVar20) {
            return 1;
          }
        }
        else if (param_1 == 2) {
          bVar21 = 0x24f < uVar13;
          bVar20 = uVar13 == 0x250;
          goto LAB_080033ee;
        }
        iVar4 = iVar7 + uVar19 * 4;
        *(char *)(iVar7 + uVar19 * 4) = (char)uVar9;
        *(char *)(iVar4 + 1) = (char)uVar3;
        *(short *)(iVar4 + 2) = (short)(iVar14 - iVar7 >> 2);
        local_7c = uVar19;
      }
    }
    uVar19 = uVar18;
    local_84 = local_84 + 1;
  } while( true );
}




void init_block(int param_1)

{
  int iVar1;
  
  iVar1 = param_1;
  do {
    *(undefined2 *)(iVar1 + 0x94) = 0;
    iVar1 = iVar1 + 4;
  } while (iVar1 != param_1 + 0x478);
  iVar1 = param_1;
  do {
    *(undefined2 *)(iVar1 + 0x988) = 0;
    iVar1 = iVar1 + 4;
  } while (iVar1 != param_1 + 0x78);
  iVar1 = param_1;
  do {
    *(undefined2 *)(iVar1 + 0xa7c) = 0;
    iVar1 = iVar1 + 4;
  } while (iVar1 != param_1 + 0x4c);
  *(undefined2 *)(param_1 + 0x494) = 1;
  *(undefined4 *)(param_1 + 0x16ac) = 0;
  *(undefined4 *)(param_1 + 0x16a8) = 0;
  *(undefined4 *)(param_1 + 0x16b0) = 0;
  *(undefined4 *)(param_1 + 0x16a0) = 0;
  return;
}




void pqdownheap(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar7 = *(int *)(param_1 + param_3 * 4 + 0xb5c);
  iVar8 = *(int *)(param_1 + 0x1450);
  while( true ) {
    iVar4 = param_3 * 2;
    iVar3 = param_3 + 0x2d6;
    if (iVar8 < iVar4) break;
    iVar6 = param_1 + param_3 * 8;
    iVar5 = *(int *)(iVar6 + 0xb5c);
    uVar1 = *(ushort *)(param_2 + iVar5 * 4);
    param_3 = iVar4;
    if (iVar4 < iVar8) {
      iVar6 = *(int *)(iVar6 + 0xb60);
      uVar2 = *(ushort *)(param_2 + iVar6 * 4);
      if ((uVar2 < uVar1) ||
         ((uVar2 == uVar1 &&
          (*(byte *)(iVar6 + param_1 + 0x1458) <= *(byte *)(iVar5 + param_1 + 0x1458))))) {
        param_3 = iVar4 + 1;
      }
    }
    uVar1 = *(ushort *)(param_2 + iVar7 * 4);
    iVar4 = *(int *)(param_1 + param_3 * 4 + 0xb5c);
    uVar2 = *(ushort *)(param_2 + iVar4 * 4);
    if ((uVar1 < uVar2) ||
       ((uVar1 == uVar2 &&
        (*(byte *)(param_1 + iVar7 + 0x1458) <= *(byte *)(param_1 + iVar4 + 0x1458))))) break;
    *(int *)(param_1 + iVar3 * 4 + 4) = iVar4;
  }
  *(int *)(param_1 + iVar3 * 4 + 4) = iVar7;
  return;
}




void scan_tree(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  uVar1 = *(ushort *)(param_2 + 2);
  *(undefined2 *)(param_2 + param_3 * 4 + 6) = 0xffff;
  iVar3 = 0;
  if (uVar1 == 0) {
    iVar9 = 3;
    iVar8 = 0x8a;
  }
  else {
    iVar9 = 4;
    iVar8 = 7;
  }
  uVar7 = 0xffffffff;
  uVar4 = (uint)uVar1;
  for (iVar6 = 0; iVar6 <= param_3; iVar6 = iVar6 + 1) {
    iVar3 = iVar3 + 1;
    uVar5 = (uint)*(ushort *)(param_2 + 6 + iVar6 * 4);
    if ((iVar8 <= iVar3) || (uVar4 != uVar5)) {
      sVar2 = (short)iVar3;
      if (iVar3 < iVar9) {
        iVar3 = param_1 + uVar4 * 4;
        *(short *)(iVar3 + 0xa7c) = sVar2 + *(short *)(iVar3 + 0xa7c);
      }
      else if (uVar4 == 0) {
        if (iVar3 < 0xb) {
          *(short *)(param_1 + 0xac0) = *(short *)(param_1 + 0xac0) + 1;
        }
        else {
          *(short *)(param_1 + 0xac4) = *(short *)(param_1 + 0xac4) + 1;
        }
      }
      else {
        bVar10 = uVar7 != uVar4;
        if (bVar10) {
          uVar7 = param_1 + uVar4 * 4;
          sVar2 = *(short *)(uVar7 + 0xa7c) + 1;
        }
        if (bVar10) {
          *(short *)(uVar7 + 0xa7c) = sVar2;
        }
        *(short *)(param_1 + 0xabc) = *(short *)(param_1 + 0xabc) + 1;
      }
      uVar7 = uVar4;
      if (uVar5 == 0) {
        iVar9 = 3;
        iVar8 = 0x8a;
        iVar3 = 0;
      }
      else {
        if (uVar4 == uVar5) {
          iVar9 = 3;
          iVar8 = 6;
        }
        else {
          iVar9 = 4;
          iVar8 = 7;
        }
        iVar3 = 0;
      }
    }
    uVar4 = uVar5;
  }
  return;
}




void send_tree(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined2 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  
  if (*(ushort *)(param_2 + 2) == 0) {
    iVar11 = 3;
    iVar2 = 0x8a;
  }
  else {
    iVar11 = 4;
    iVar2 = 7;
  }
  uVar7 = 0xffffffff;
  iVar6 = 0;
  uVar8 = (uint)*(ushort *)(param_2 + 2);
  for (iVar13 = 0; iVar13 <= param_3; iVar13 = iVar13 + 1) {
    iVar4 = iVar6 + 1;
    uVar12 = (uint)*(ushort *)(param_2 + 6 + iVar13 * 4);
    if ((iVar2 <= iVar4) || (uVar8 != uVar12)) {
      uVar3 = *(uint *)(param_1 + 0x16bc);
      uVar9 = (uint)*(ushort *)(param_1 + 0x16b8);
      if (iVar4 < iVar11) {
        iVar11 = param_1 + uVar8 * 4;
        do {
          uVar7 = *(uint *)(param_1 + 0x16bc);
          uVar9 = (uint)*(ushort *)(iVar11 + 0xa7c);
          uVar10 = (uint)*(ushort *)(iVar11 + 0xa7e);
          uVar3 = uVar9 << (uVar7 & 0xff) & 0xffff | (uint)*(ushort *)(param_1 + 0x16b8);
          uVar5 = (undefined2)uVar3;
          if ((int)(0x10 - uVar10) < (int)uVar7) {
            iVar2 = *(int *)(param_1 + 0x14);
            *(undefined2 *)(param_1 + 0x16b8) = uVar5;
            *(int *)(param_1 + 0x14) = iVar2 + 1;
            *(char *)(*(int *)(param_1 + 8) + iVar2) = (char)uVar3;
            iVar2 = *(int *)(param_1 + 0x14);
            *(int *)(param_1 + 0x14) = iVar2 + 1;
            *(char *)(*(int *)(param_1 + 8) + iVar2) =
                 (char)((ushort)*(undefined2 *)(param_1 + 0x16b8) >> 8);
            uVar5 = (undefined2)((int)uVar9 >> (0x10U - *(int *)(param_1 + 0x16bc) & 0xff));
            iVar2 = (uVar10 - 0x10) + *(int *)(param_1 + 0x16bc);
          }
          else {
            iVar2 = uVar7 + uVar10;
          }
          iVar4 = iVar4 + -1;
          *(undefined2 *)(param_1 + 0x16b8) = uVar5;
          *(int *)(param_1 + 0x16bc) = iVar2;
        } while (iVar4 != 0);
      }
      else {
        if (uVar8 == 0) {
          if (iVar4 < 0xb) {
            uVar7 = (uint)*(ushort *)(param_1 + 0xac2);
            uVar1 = *(ushort *)(param_1 + 0xac0);
            uVar9 = uVar9 | (uint)uVar1 << (uVar3 & 0xff) & 0xffff;
            if ((int)(0x10 - uVar7) < (int)uVar3) {
              iVar11 = *(int *)(param_1 + 0x14);
              *(short *)(param_1 + 0x16b8) = (short)uVar9;
              *(int *)(param_1 + 0x14) = iVar11 + 1;
              *(char *)(*(int *)(param_1 + 8) + iVar11) = (char)uVar9;
              iVar11 = *(int *)(param_1 + 0x14);
              *(int *)(param_1 + 0x14) = iVar11 + 1;
              *(char *)(*(int *)(param_1 + 8) + iVar11) =
                   (char)((ushort)*(undefined2 *)(param_1 + 0x16b8) >> 8);
              uVar9 = (int)(uint)uVar1 >> (0x10U - *(int *)(param_1 + 0x16bc) & 0xff) & 0xffff;
              uVar3 = *(int *)(param_1 + 0x16bc) + (uVar7 - 0x10);
            }
            else {
              uVar3 = uVar3 + uVar7;
            }
            *(uint *)(param_1 + 0x16bc) = uVar3;
            if ((int)uVar3 < 0xe) {
              *(ushort *)(param_1 + 0x16b8) =
                   (ushort)uVar9 | (ushort)((iVar6 - 2U & 0xffff) << (uVar3 & 0xff));
              iVar11 = uVar3 + 3;
            }
            else {
              uVar7 = iVar6 - 2U & 0xffff;
              iVar11 = *(int *)(param_1 + 0x14);
              uVar9 = uVar7 << (uVar3 & 0xff) & 0xffff | uVar9;
              *(short *)(param_1 + 0x16b8) = (short)uVar9;
              *(int *)(param_1 + 0x14) = iVar11 + 1;
              *(char *)(*(int *)(param_1 + 8) + iVar11) = (char)uVar9;
              iVar11 = *(int *)(param_1 + 0x14);
              *(int *)(param_1 + 0x14) = iVar11 + 1;
              *(char *)(*(int *)(param_1 + 8) + iVar11) =
                   (char)((ushort)*(undefined2 *)(param_1 + 0x16b8) >> 8);
              *(short *)(param_1 + 0x16b8) =
                   (short)((int)uVar7 >> (0x10U - *(int *)(param_1 + 0x16bc) & 0xff));
              iVar11 = *(int *)(param_1 + 0x16bc) + -0xd;
            }
          }
          else {
            uVar1 = *(ushort *)(param_1 + 0xac4);
            uVar7 = (uint)*(ushort *)(param_1 + 0xac6);
            uVar9 = uVar9 | (uint)uVar1 << (uVar3 & 0xff) & 0xffff;
            if ((int)(0x10 - uVar7) < (int)uVar3) {
              iVar11 = *(int *)(param_1 + 0x14);
              *(short *)(param_1 + 0x16b8) = (short)uVar9;
              *(int *)(param_1 + 0x14) = iVar11 + 1;
              *(char *)(*(int *)(param_1 + 8) + iVar11) = (char)uVar9;
              iVar11 = *(int *)(param_1 + 0x14);
              *(int *)(param_1 + 0x14) = iVar11 + 1;
              *(char *)(*(int *)(param_1 + 8) + iVar11) =
                   (char)((ushort)*(undefined2 *)(param_1 + 0x16b8) >> 8);
              uVar9 = (int)(uint)uVar1 >> (0x10U - *(int *)(param_1 + 0x16bc) & 0xff) & 0xffff;
              uVar3 = (uVar7 - 0x10) + *(int *)(param_1 + 0x16bc);
            }
            else {
              uVar3 = uVar3 + uVar7;
            }
            *(uint *)(param_1 + 0x16bc) = uVar3;
            if ((int)uVar3 < 10) {
              *(ushort *)(param_1 + 0x16b8) =
                   (ushort)uVar9 | (ushort)((iVar6 - 10U & 0xffff) << (uVar3 & 0xff));
              iVar11 = uVar3 + 7;
            }
            else {
              uVar7 = iVar6 - 10U & 0xffff;
              iVar11 = *(int *)(param_1 + 0x14);
              uVar9 = uVar9 | uVar7 << (uVar3 & 0xff) & 0xffff;
              *(short *)(param_1 + 0x16b8) = (short)uVar9;
              *(int *)(param_1 + 0x14) = iVar11 + 1;
              *(char *)(*(int *)(param_1 + 8) + iVar11) = (char)uVar9;
              iVar11 = *(int *)(param_1 + 0x14);
              *(int *)(param_1 + 0x14) = iVar11 + 1;
              *(char *)(*(int *)(param_1 + 8) + iVar11) =
                   (char)((ushort)*(undefined2 *)(param_1 + 0x16b8) >> 8);
              *(short *)(param_1 + 0x16b8) =
                   (short)((int)uVar7 >> (0x10U - *(int *)(param_1 + 0x16bc) & 0xff));
              iVar11 = *(int *)(param_1 + 0x16bc) + -9;
            }
          }
        }
        else {
          if (uVar7 != uVar8) {
            iVar11 = param_1 + uVar8 * 4;
            uVar7 = (uint)*(ushort *)(iVar11 + 0xa7e);
            uVar10 = (uint)*(ushort *)(iVar11 + 0xa7c);
            uVar9 = uVar9 | uVar10 << (uVar3 & 0xff) & 0xffff;
            uVar5 = (undefined2)uVar9;
            if ((int)(0x10 - uVar7) < (int)uVar3) {
              iVar11 = *(int *)(param_1 + 0x14);
              *(undefined2 *)(param_1 + 0x16b8) = uVar5;
              *(int *)(param_1 + 0x14) = iVar11 + 1;
              *(char *)(*(int *)(param_1 + 8) + iVar11) = (char)uVar9;
              iVar11 = *(int *)(param_1 + 0x14);
              *(int *)(param_1 + 0x14) = iVar11 + 1;
              *(char *)(*(int *)(param_1 + 8) + iVar11) =
                   (char)((ushort)*(undefined2 *)(param_1 + 0x16b8) >> 8);
              uVar3 = *(uint *)(param_1 + 0x16bc);
              uVar5 = (undefined2)((int)uVar10 >> (0x10 - uVar3 & 0xff));
              uVar7 = uVar7 - 0x10;
            }
            *(uint *)(param_1 + 0x16bc) = uVar7 + uVar3;
            *(undefined2 *)(param_1 + 0x16b8) = uVar5;
            iVar4 = iVar6;
          }
          uVar7 = *(uint *)(param_1 + 0x16bc);
          uVar1 = *(ushort *)(param_1 + 0xabc);
          uVar9 = (uint)*(ushort *)(param_1 + 0xabe);
          uVar3 = (uint)uVar1 << (uVar7 & 0xff) & 0xffff | (uint)*(ushort *)(param_1 + 0x16b8);
          if ((int)(0x10 - uVar9) < (int)uVar7) {
            iVar11 = *(int *)(param_1 + 0x14);
            *(short *)(param_1 + 0x16b8) = (short)uVar3;
            *(int *)(param_1 + 0x14) = iVar11 + 1;
            *(char *)(*(int *)(param_1 + 8) + iVar11) = (char)uVar3;
            iVar11 = *(int *)(param_1 + 0x14);
            *(int *)(param_1 + 0x14) = iVar11 + 1;
            *(char *)(*(int *)(param_1 + 8) + iVar11) =
                 (char)((ushort)*(undefined2 *)(param_1 + 0x16b8) >> 8);
            uVar7 = *(uint *)(param_1 + 0x16bc);
            uVar3 = (int)(uint)uVar1 >> (0x10 - uVar7 & 0xff) & 0xffff;
            uVar9 = uVar9 - 0x10;
          }
          uVar7 = uVar7 + uVar9;
          *(uint *)(param_1 + 0x16bc) = uVar7;
          uVar9 = iVar4 - 3U & 0xffff;
          if ((int)uVar7 < 0xf) {
            *(ushort *)(param_1 + 0x16b8) = (ushort)(uVar9 << (uVar7 & 0xff)) | (ushort)uVar3;
            iVar11 = uVar7 + 2;
          }
          else {
            iVar11 = *(int *)(param_1 + 0x14);
            uVar3 = uVar9 << (uVar7 & 0xff) & 0xffff | uVar3;
            *(short *)(param_1 + 0x16b8) = (short)uVar3;
            *(int *)(param_1 + 0x14) = iVar11 + 1;
            *(char *)(*(int *)(param_1 + 8) + iVar11) = (char)uVar3;
            iVar11 = *(int *)(param_1 + 0x14);
            *(int *)(param_1 + 0x14) = iVar11 + 1;
            *(char *)(*(int *)(param_1 + 8) + iVar11) =
                 (char)((ushort)*(undefined2 *)(param_1 + 0x16b8) >> 8);
            *(short *)(param_1 + 0x16b8) =
                 (short)((int)uVar9 >> (0x10U - *(int *)(param_1 + 0x16bc) & 0xff));
            iVar11 = *(int *)(param_1 + 0x16bc) + -0xe;
          }
        }
        *(int *)(param_1 + 0x16bc) = iVar11;
      }
      uVar7 = uVar8;
      if (uVar12 == 0) {
        iVar11 = 3;
        iVar2 = 0x8a;
        iVar4 = 0;
      }
      else {
        if (uVar8 == uVar12) {
          iVar11 = 3;
          iVar2 = 6;
        }
        else {
          iVar11 = 4;
          iVar2 = 7;
        }
        iVar4 = 0;
      }
    }
    iVar6 = iVar4;
    uVar8 = uVar12;
  }
  return;
}




void compress_block(int param_1,int param_2,int param_3)

{
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  
  if (*(int *)(param_1 + 0x16a0) != 0) {
    uVar4 = 0;
    do {
      iVar6 = *(int *)(param_1 + 0x1698);
      uVar9 = *(uint *)(param_1 + 0x16bc);
      uVar5 = (uint)CONCAT11(*(undefined1 *)(iVar6 + uVar4 + 1),*(undefined1 *)(iVar6 + uVar4));
      uVar7 = (uint)*(byte *)(iVar6 + uVar4 + 2);
      uVar4 = uVar4 + 3;
      if (uVar5 == 0) {
        uVar8 = (uint)*(ushort *)(param_2 + uVar7 * 4);
        uVar7 = (uint)*(ushort *)(param_2 + uVar7 * 4 + 2);
        uVar5 = (uint)*(ushort *)(param_1 + 0x16b8) | uVar8 << (uVar9 & 0xff) & 0xffff;
        *(short *)(param_1 + 0x16b8) = (short)uVar5;
        if ((int)(0x10 - uVar7) < (int)uVar9) {
          iVar6 = *(int *)(param_1 + 0x14);
          *(int *)(param_1 + 0x14) = iVar6 + 1;
          *(char *)(*(int *)(param_1 + 8) + iVar6) = (char)uVar5;
          iVar6 = *(int *)(param_1 + 0x14);
          *(int *)(param_1 + 0x14) = iVar6 + 1;
          *(char *)(*(int *)(param_1 + 8) + iVar6) =
               (char)((ushort)*(undefined2 *)(param_1 + 0x16b8) >> 8);
          *(short *)(param_1 + 0x16b8) =
               (short)((int)uVar8 >> (0x10U - *(int *)(param_1 + 0x16bc) & 0xff));
          *(uint *)(param_1 + 0x16bc) = *(int *)(param_1 + 0x16bc) + (uVar7 - 0x10);
        }
        else {
          *(uint *)(param_1 + 0x16bc) = uVar9 + uVar7;
        }
      }
      else {
        uVar13 = (uint)*(byte *)(DAT_08003cbc + uVar7);
        uVar12 = (uint)*(ushort *)(param_2 + (uVar13 + 0x101) * 4);
        uVar11 = (uint)*(ushort *)(param_2 + (uVar13 + 0x101) * 4 + 2);
        uVar8 = (uint)*(ushort *)(param_1 + 0x16b8) | uVar12 << (uVar9 & 0xff) & 0xffff;
        if ((int)(0x10 - uVar11) < (int)uVar9) {
          iVar6 = *(int *)(param_1 + 0x14);
          *(short *)(param_1 + 0x16b8) = (short)uVar8;
          *(int *)(param_1 + 0x14) = iVar6 + 1;
          *(char *)(*(int *)(param_1 + 8) + iVar6) = (char)uVar8;
          iVar6 = *(int *)(param_1 + 0x14);
          *(int *)(param_1 + 0x14) = iVar6 + 1;
          *(char *)(*(int *)(param_1 + 8) + iVar6) =
               (char)((ushort)*(undefined2 *)(param_1 + 0x16b8) >> 8);
          uVar8 = (int)uVar12 >> (0x10U - *(int *)(param_1 + 0x16bc) & 0xff) & 0xffff;
          uVar9 = *(int *)(param_1 + 0x16bc) + (uVar11 - 0x10);
        }
        else {
          uVar9 = uVar9 + uVar11;
        }
        iVar6 = DAT_08003cc0;
        *(short *)(param_1 + 0x16b8) = (short)uVar8;
        iVar6 = *(int *)(iVar6 + uVar13 * 4);
        *(uint *)(param_1 + 0x16bc) = uVar9;
        if (iVar6 != 0) {
          uVar7 = uVar7 - *(int *)(DAT_08003cc4 + uVar13 * 4) & 0xffff;
          uVar8 = uVar8 | uVar7 << (uVar9 & 0xff) & 0xffff;
          *(short *)(param_1 + 0x16b8) = (short)uVar8;
          if (0x10 - iVar6 < (int)uVar9) {
            iVar10 = *(int *)(param_1 + 0x14);
            *(int *)(param_1 + 0x14) = iVar10 + 1;
            *(char *)(*(int *)(param_1 + 8) + iVar10) = (char)uVar8;
            iVar10 = *(int *)(param_1 + 0x14);
            *(int *)(param_1 + 0x14) = iVar10 + 1;
            *(char *)(*(int *)(param_1 + 8) + iVar10) =
                 (char)((ushort)*(undefined2 *)(param_1 + 0x16b8) >> 8);
            *(short *)(param_1 + 0x16b8) =
                 (short)((int)uVar7 >> (0x10U - *(int *)(param_1 + 0x16bc) & 0xff));
            *(int *)(param_1 + 0x16bc) = *(int *)(param_1 + 0x16bc) + iVar6 + -0x10;
          }
          else {
            *(uint *)(param_1 + 0x16bc) = uVar9 + iVar6;
          }
        }
        uVar7 = *(uint *)(param_1 + 0x16bc);
        uVar5 = uVar5 - 1;
        if (uVar5 < 0x100) {
          bVar1 = *(byte *)(DAT_08003cc8 + uVar5);
        }
        else {
          bVar1 = *(byte *)(DAT_08003cc8 + (uVar5 >> 7) + 0x100);
        }
        uVar8 = (uint)bVar1;
        uVar11 = (uint)*(ushort *)(param_3 + uVar8 * 4);
        uVar12 = (uint)*(ushort *)(param_3 + uVar8 * 4 + 2);
        uVar9 = uVar11 << (uVar7 & 0xff) & 0xffff | (uint)*(ushort *)(param_1 + 0x16b8);
        if ((int)(0x10 - uVar12) < (int)uVar7) {
          iVar6 = *(int *)(param_1 + 0x14);
          *(short *)(param_1 + 0x16b8) = (short)uVar9;
          *(int *)(param_1 + 0x14) = iVar6 + 1;
          *(char *)(*(int *)(param_1 + 8) + iVar6) = (char)uVar9;
          iVar6 = *(int *)(param_1 + 0x14);
          *(int *)(param_1 + 0x14) = iVar6 + 1;
          *(char *)(*(int *)(param_1 + 8) + iVar6) =
               (char)((ushort)*(undefined2 *)(param_1 + 0x16b8) >> 8);
          uVar9 = (int)uVar11 >> (0x10U - *(int *)(param_1 + 0x16bc) & 0xff) & 0xffff;
          uVar7 = *(int *)(param_1 + 0x16bc) + (uVar12 - 0x10);
        }
        else {
          uVar7 = uVar7 + uVar12;
        }
        iVar6 = DAT_08003ccc;
        *(short *)(param_1 + 0x16b8) = (short)uVar9;
        iVar6 = *(int *)(iVar6 + uVar8 * 4);
        *(uint *)(param_1 + 0x16bc) = uVar7;
        if (iVar6 != 0) {
          uVar5 = uVar5 - *(int *)(DAT_08003cd0 + uVar8 * 4) & 0xffff;
          uVar9 = uVar9 | uVar5 << (uVar7 & 0xff) & 0xffff;
          *(short *)(param_1 + 0x16b8) = (short)uVar9;
          if (0x10 - iVar6 < (int)uVar7) {
            iVar10 = *(int *)(param_1 + 0x14);
            *(int *)(param_1 + 0x14) = iVar10 + 1;
            *(char *)(*(int *)(param_1 + 8) + iVar10) = (char)uVar9;
            iVar10 = *(int *)(param_1 + 0x14);
            *(int *)(param_1 + 0x14) = iVar10 + 1;
            *(char *)(*(int *)(param_1 + 8) + iVar10) =
                 (char)((ushort)*(undefined2 *)(param_1 + 0x16b8) >> 8);
            *(short *)(param_1 + 0x16b8) =
                 (short)((int)uVar5 >> (0x10U - *(int *)(param_1 + 0x16bc) & 0xff));
            *(int *)(param_1 + 0x16bc) = *(int *)(param_1 + 0x16bc) + iVar6 + -0x10;
          }
          else {
            *(uint *)(param_1 + 0x16bc) = uVar7 + iVar6;
          }
        }
      }
    } while (uVar4 < *(uint *)(param_1 + 0x16a0));
  }
  uVar7 = (uint)*(ushort *)(param_2 + 0x402);
  uVar5 = *(uint *)(param_1 + 0x16bc);
  uVar2 = *(ushort *)(param_2 + 0x400);
  uVar4 = (uint)uVar2 << (uVar5 & 0xff) & 0xffff | (uint)*(ushort *)(param_1 + 0x16b8);
  uVar3 = (undefined2)uVar4;
  if ((int)(0x10 - uVar7) < (int)uVar5) {
    iVar6 = *(int *)(param_1 + 0x14);
    *(undefined2 *)(param_1 + 0x16b8) = uVar3;
    *(int *)(param_1 + 0x14) = iVar6 + 1;
    *(char *)(*(int *)(param_1 + 8) + iVar6) = (char)uVar4;
    iVar6 = *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar6 + 1;
    *(char *)(*(int *)(param_1 + 8) + iVar6) =
         (char)((ushort)*(undefined2 *)(param_1 + 0x16b8) >> 8);
    uVar3 = (undefined2)((int)(uint)uVar2 >> (0x10U - *(int *)(param_1 + 0x16bc) & 0xff));
    iVar6 = (uVar7 - 0x10) + *(int *)(param_1 + 0x16bc);
  }
  else {
    iVar6 = uVar5 + uVar7;
  }
  *(undefined2 *)(param_1 + 0x16b8) = uVar3;
  *(int *)(param_1 + 0x16bc) = iVar6;
  return;
}




void build_tree(int param_1,int *param_2)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  void *pvVar4;
  uint uVar5;
  int iVar6;
  ushort *puVar7;
  uint uVar8;
  int iVar9;
  short *psVar10;
  ushort uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  int *piVar22;
  int iVar23;
  int local_64;
  ushort auStack_48 [18];
  
  piVar22 = (int *)param_2[2];
  iVar17 = *param_2;
  iVar12 = *piVar22;
  iVar18 = piVar22[3];
  *(undefined4 *)(param_1 + 0x1454) = 0x23d;
  *(undefined4 *)(param_1 + 0x1450) = 0;
  local_64 = -1;
  for (iVar13 = 0; iVar6 = *(int *)(param_1 + 0x1450), iVar13 < iVar18; iVar13 = iVar13 + 1) {
    if (*(short *)(iVar17 + iVar13 * 4) == 0) {
      *(undefined2 *)(iVar17 + 2 + iVar13 * 4) = 0;
    }
    else {
      *(int *)(param_1 + 0x1450) = iVar6 + 1;
      *(int *)(param_1 + iVar6 * 4 + 0xb60) = iVar13;
      *(undefined1 *)(param_1 + 0x1458 + iVar13) = 0;
      local_64 = iVar13;
    }
  }
  while (iVar13 = *(int *)(param_1 + 0x1450), iVar13 < 2) {
    if (local_64 < 2) {
      iVar6 = local_64 + 1;
    }
    else {
      iVar6 = 0;
    }
    *(int *)(param_1 + 0x1450) = iVar13 + 1;
    if (local_64 < 2) {
      local_64 = iVar6;
    }
    *(int *)(param_1 + iVar13 * 4 + 0xb60) = iVar6;
    *(undefined2 *)(iVar17 + iVar6 * 4) = 1;
    *(undefined1 *)(iVar6 + param_1 + 0x1458) = 0;
    *(int *)(param_1 + 0x16a8) = *(int *)(param_1 + 0x16a8) + -1;
    if (iVar12 != 0) {
      *(uint *)(param_1 + 0x16ac) =
           *(int *)(param_1 + 0x16ac) - (uint)*(ushort *)(iVar6 * 4 + iVar12 + 2);
    }
  }
  param_2[1] = local_64;
  iVar13 = iVar13 >> 1;
  do {
    pqdownheap(param_1,iVar17,iVar13);
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  do {
    iVar20 = *(int *)(param_1 + 0xb60);
    iVar13 = *(int *)(param_1 + 0x1450);
    iVar6 = iVar13 + -1;
    *(int *)(param_1 + 0x1450) = iVar6;
    *(undefined4 *)(param_1 + 0xb60) = *(undefined4 *)(param_1 + iVar13 * 4 + 0xb5c);
    pqdownheap(param_1,iVar17,1);
    iVar14 = *(int *)(param_1 + 0x1454);
    iVar9 = *(int *)(param_1 + 0xb60);
    iVar15 = param_1 + iVar14 * 4;
    iVar13 = iVar14 + -2;
    *(int *)(iVar15 + 0xb58) = iVar20;
    *(int *)(param_1 + 0x1454) = iVar13;
    *(int *)(iVar15 + 0xb54) = iVar9;
    *(short *)(iVar17 + iVar18 * 4) =
         *(short *)(iVar17 + iVar20 * 4) + *(short *)(iVar17 + iVar9 * 4);
    bVar1 = *(byte *)(iVar20 + param_1 + 0x1458);
    bVar2 = *(byte *)(iVar9 + param_1 + 0x1458);
    if (bVar2 <= bVar1) {
      bVar2 = bVar1;
    }
    *(byte *)(param_1 + 0x1458 + iVar18) = bVar2 + 1;
    *(short *)(iVar17 + iVar9 * 4 + 2) = (short)iVar18;
    *(short *)(iVar17 + iVar20 * 4 + 2) = (short)iVar18;
    *(int *)(param_1 + 0xb60) = iVar18;
    pqdownheap(param_1,iVar17,1);
    iVar18 = iVar18 + 1;
  } while (1 < iVar6);
  iVar18 = *(int *)(param_1 + 0xb60);
  *(int *)(param_1 + 0x1454) = iVar14 + -3;
  *(int *)(iVar15 + 0xb50) = iVar18;
  iVar9 = piVar22[1];
  iVar14 = piVar22[2];
  iVar15 = param_2[1];
  uVar19 = piVar22[4];
  pvVar4 = memset((void *)(param_1 + 0xb3c),0,0x20);
  iVar6 = 0;
  *(undefined2 *)(iVar17 + iVar18 * 4 + 2) = 0;
  for (iVar18 = iVar13; iVar18 < 0x23d; iVar18 = iVar18 + 1) {
    iVar20 = *(int *)(param_1 + 0xb5c + iVar18 * 4);
    iVar23 = iVar17 + iVar20 * 4;
    uVar5 = *(ushort *)(iVar17 + (uint)*(ushort *)(iVar23 + 2) * 4 + 2) + 1;
    if ((int)uVar19 < (int)uVar5) {
      iVar6 = iVar6 + 1;
      uVar5 = uVar19;
    }
    *(short *)(iVar23 + 2) = (short)uVar5;
    if (iVar20 <= iVar15) {
      iVar21 = param_1 + uVar5 * 2;
      *(short *)(iVar21 + 0xb3c) = *(short *)(iVar21 + 0xb3c) + 1;
      iVar23 = iVar14;
      if (iVar14 <= iVar20) {
        iVar23 = iVar20 - iVar14;
        iVar21 = iVar9;
      }
      uVar16 = (uint)*(ushort *)(iVar17 + iVar20 * 4);
      if (iVar14 <= iVar20) {
        iVar23 = *(int *)(iVar21 + iVar23 * 4);
      }
      if (iVar20 < iVar14) {
        iVar23 = 0;
      }
      *(uint *)(param_1 + 0x16a8) = uVar16 * (uVar5 + iVar23) + *(int *)(param_1 + 0x16a8);
      if (iVar12 != 0) {
        *(uint *)(param_1 + 0x16ac) =
             uVar16 * (iVar23 + (uint)*(ushort *)(iVar20 * 4 + iVar12 + 2)) +
             *(int *)(param_1 + 0x16ac);
      }
    }
  }
  if (iVar6 != 0) {
    iVar12 = param_1 + uVar19 * 2;
    uVar5 = uVar19;
    do {
      do {
        uVar5 = uVar5 - 1;
        sVar3 = *(short *)((int)pvVar4 + uVar5 * 2);
      } while (sVar3 == 0);
      iVar18 = param_1 + uVar5 * 2;
      *(short *)(iVar18 + 0xb3c) = sVar3 + -1;
      *(short *)(iVar18 + 0xb3e) = *(short *)(iVar18 + 0xb3e) + 2;
      iVar6 = iVar6 + -2;
      *(short *)(iVar12 + 0xb3c) = *(short *)(iVar12 + 0xb3c) + -1;
      uVar5 = uVar19;
    } while (0 < iVar6);
    iVar12 = 0x23d - iVar13;
    if (0x23d < iVar13) {
      iVar12 = 0;
    }
    iVar12 = iVar12 + iVar13;
    for (; uVar19 != 0; uVar19 = uVar19 - 1) {
      for (uVar5 = (uint)*(ushort *)((int)pvVar4 + uVar19 * 2); uVar5 != 0; uVar5 = uVar5 - 1) {
        do {
          iVar12 = iVar12 + -1;
          iVar13 = *(int *)(param_1 + 0xb5c + iVar12 * 4);
        } while (iVar15 < iVar13);
        iVar18 = iVar17 + iVar13 * 4;
        uVar16 = (uint)*(ushort *)(iVar18 + 2);
        if (uVar16 != uVar19) {
          *(uint *)(param_1 + 0x16a8) =
               (uint)*(ushort *)(iVar17 + iVar13 * 4) * (uVar19 - uVar16) +
               *(int *)(param_1 + 0x16a8);
          *(short *)(iVar18 + 2) = (short)uVar19;
        }
      }
    }
  }
  psVar10 = (short *)(param_1 + 0xb3a);
  puVar7 = auStack_48;
  uVar11 = 0;
  do {
    psVar10 = psVar10 + 1;
    uVar11 = (uVar11 + *psVar10) * 2;
    puVar7 = puVar7 + 1;
    *puVar7 = uVar11;
  } while (psVar10 != (short *)(param_1 + 0xb58));
  for (iVar12 = 0; iVar12 <= local_64; iVar12 = iVar12 + 1) {
    uVar19 = (uint)*(ushort *)(iVar17 + 2 + iVar12 * 4);
    if (uVar19 != 0) {
      uVar16 = (uint)auStack_48[uVar19];
      auStack_48[uVar19] = auStack_48[uVar19] + 1;
      uVar5 = 0;
      do {
        uVar8 = uVar16 & 1 | uVar5;
        uVar19 = uVar19 - 1;
        uVar16 = uVar16 >> 1;
        uVar5 = uVar8 << 1;
      } while (uVar19 != 0);
      *(short *)(iVar17 + iVar12 * 4) = (short)uVar8;
    }
  }
  return;
}




void bi_windup(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x16bc) < 9) {
    if (0 < *(int *)(param_1 + 0x16bc)) {
      iVar1 = *(int *)(param_1 + 0x14);
      *(int *)(param_1 + 0x14) = iVar1 + 1;
      *(char *)(*(int *)(param_1 + 8) + iVar1) = (char)*(undefined2 *)(param_1 + 0x16b8);
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar1 + 1;
    *(char *)(*(int *)(param_1 + 8) + iVar1) = (char)*(undefined2 *)(param_1 + 0x16b8);
    iVar1 = *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar1 + 1;
    *(char *)(*(int *)(param_1 + 8) + iVar1) =
         (char)((ushort)*(undefined2 *)(param_1 + 0x16b8) >> 8);
  }
  *(undefined2 *)(param_1 + 0x16b8) = 0;
  *(undefined4 *)(param_1 + 0x16bc) = 0;
  return;
}




void bi_flush(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x16bc) == 0x10) {
    iVar1 = *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar1 + 1;
    *(char *)(*(int *)(param_1 + 8) + iVar1) = (char)*(undefined2 *)(param_1 + 0x16b8);
    iVar1 = *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar1 + 1;
    *(char *)(*(int *)(param_1 + 8) + iVar1) =
         (char)((ushort)*(undefined2 *)(param_1 + 0x16b8) >> 8);
    iVar1 = 0;
    *(undefined2 *)(param_1 + 0x16b8) = 0;
  }
  else {
    if (*(int *)(param_1 + 0x16bc) < 8) {
      return;
    }
    iVar1 = *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar1 + 1;
    *(char *)(*(int *)(param_1 + 8) + iVar1) = (char)*(undefined2 *)(param_1 + 0x16b8);
    *(ushort *)(param_1 + 0x16b8) = *(ushort *)(param_1 + 0x16b8) >> 8;
    iVar1 = *(int *)(param_1 + 0x16bc) + -8;
  }
  *(int *)(param_1 + 0x16bc) = iVar1;
  return;
}




void _tr_init(int param_1)

{
  *(int *)(param_1 + 0xb18) = param_1 + 0x94;
  *(undefined4 *)(param_1 + 0xb20) = DAT_08004120;
  *(int *)(param_1 + 0xb24) = param_1 + 0x988;
  *(undefined4 *)(param_1 + 0xb2c) = DAT_08004124;
  *(int *)(param_1 + 0xb30) = param_1 + 0xa7c;
  *(undefined4 *)(param_1 + 0xb38) = DAT_08004128;
  *(undefined2 *)(param_1 + 0x16b8) = 0;
  *(undefined4 *)(param_1 + 0x16bc) = 0;
  init_block();
  return;
}




void _tr_stored_block(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  uint uVar5;
  
  uVar2 = *(uint *)(param_1 + 0x16bc);
  uVar5 = (param_4 & 0xffff) << (uVar2 & 0xff) & 0xffff | (uint)*(ushort *)(param_1 + 0x16b8);
  uVar4 = (undefined2)uVar5;
  if ((int)uVar2 < 0xe) {
    iVar3 = uVar2 + 3;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x14);
    *(undefined2 *)(param_1 + 0x16b8) = uVar4;
    *(int *)(param_1 + 0x14) = iVar3 + 1;
    *(char *)(*(int *)(param_1 + 8) + iVar3) = (char)uVar5;
    iVar3 = *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar3 + 1;
    *(char *)(*(int *)(param_1 + 8) + iVar3) =
         (char)((ushort)*(undefined2 *)(param_1 + 0x16b8) >> 8);
    uVar4 = (undefined2)((int)(param_4 & 0xffff) >> (0x10U - *(int *)(param_1 + 0x16bc) & 0xff));
    iVar3 = *(int *)(param_1 + 0x16bc) + -0xd;
  }
  *(undefined2 *)(param_1 + 0x16b8) = uVar4;
  *(int *)(param_1 + 0x16bc) = iVar3;
  bi_windup(param_1);
  iVar3 = *(int *)(param_1 + 0x14);
  *(int *)(param_1 + 0x14) = iVar3 + 1;
  *(byte *)(*(int *)(param_1 + 8) + iVar3) = (byte)param_3;
  iVar3 = *(int *)(param_1 + 0x14);
  *(int *)(param_1 + 0x14) = iVar3 + 1;
  bVar1 = (byte)((uint)param_3 >> 8);
  *(byte *)(*(int *)(param_1 + 8) + iVar3) = bVar1;
  iVar3 = *(int *)(param_1 + 0x14);
  *(int *)(param_1 + 0x14) = iVar3 + 1;
  *(byte *)(*(int *)(param_1 + 8) + iVar3) = ~(byte)param_3;
  iVar3 = *(int *)(param_1 + 0x14);
  *(int *)(param_1 + 0x14) = iVar3 + 1;
  *(byte *)(*(int *)(param_1 + 8) + iVar3) = ~bVar1;
  if (param_3 != 0) {
    zmemcpy(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14),param_2,param_3,
            *(int *)(param_1 + 0x14),param_4);
  }
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + param_3;
  return;
}




void _tr_flush_bits(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x16bc) == 0x10) {
    iVar1 = *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar1 + 1;
    *(char *)(*(int *)(param_1 + 8) + iVar1) = (char)*(undefined2 *)(param_1 + 0x16b8);
    iVar1 = *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar1 + 1;
    *(char *)(*(int *)(param_1 + 8) + iVar1) =
         (char)((ushort)*(undefined2 *)(param_1 + 0x16b8) >> 8);
    iVar1 = 0;
    *(undefined2 *)(param_1 + 0x16b8) = 0;
  }
  else {
    if (*(int *)(param_1 + 0x16bc) < 8) {
      return;
    }
    iVar1 = *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar1 + 1;
    *(char *)(*(int *)(param_1 + 8) + iVar1) = (char)*(undefined2 *)(param_1 + 0x16b8);
    *(ushort *)(param_1 + 0x16b8) = *(ushort *)(param_1 + 0x16b8) >> 8;
    iVar1 = *(int *)(param_1 + 0x16bc) + -8;
  }
  *(int *)(param_1 + 0x16bc) = iVar1;
  return;
}




void _tr_align(int param_1)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = *(uint *)(param_1 + 0x16bc);
  uVar2 = 2 << (uVar3 & 0xff) & 0xffffU | (uint)*(ushort *)(param_1 + 0x16b8);
  uVar1 = (undefined2)uVar2;
  if ((int)uVar3 < 0xe) {
    iVar4 = uVar3 + 3;
  }
  else {
    iVar4 = *(int *)(param_1 + 0x14);
    *(undefined2 *)(param_1 + 0x16b8) = uVar1;
    *(int *)(param_1 + 0x14) = iVar4 + 1;
    *(char *)(*(int *)(param_1 + 8) + iVar4) = (char)uVar2;
    iVar4 = *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar4 + 1;
    *(char *)(*(int *)(param_1 + 8) + iVar4) =
         (char)((ushort)*(undefined2 *)(param_1 + 0x16b8) >> 8);
    uVar1 = (undefined2)(2 >> (0x10U - *(int *)(param_1 + 0x16bc) & 0xff));
    iVar4 = *(int *)(param_1 + 0x16bc) + -0xd;
  }
  *(undefined2 *)(param_1 + 0x16b8) = uVar1;
  *(int *)(param_1 + 0x16bc) = iVar4;
  if (iVar4 < 10) {
    iVar4 = iVar4 + 7;
  }
  else {
    iVar4 = *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar4 + 1;
    *(char *)(*(int *)(param_1 + 8) + iVar4) = (char)uVar1;
    iVar4 = *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar4 + 1;
    *(char *)(*(int *)(param_1 + 8) + iVar4) =
         (char)((ushort)*(undefined2 *)(param_1 + 0x16b8) >> 8);
    *(undefined2 *)(param_1 + 0x16b8) = 0;
    iVar4 = *(int *)(param_1 + 0x16bc) + -9;
  }
  *(int *)(param_1 + 0x16bc) = iVar4;
  bi_flush();
  return;
}




void _tr_flush_block(int *param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int *piVar3;
  undefined2 uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  ushort uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  byte *pbVar14;
  
  if (param_1[0x21] < 1) {
    uVar5 = param_3 + 5;
    iVar11 = 0;
    uVar13 = uVar5;
  }
  else {
    if (*(int *)(*param_1 + 0x2c) == 2) {
      uVar5 = DAT_08004408;
      piVar6 = param_1;
      do {
        if (((uVar5 & 1) != 0) && ((short)piVar6[0x25] != 0)) {
          uVar1 = 0;
          goto LAB_080042d8;
        }
        piVar6 = piVar6 + 1;
        uVar5 = uVar5 >> 1;
      } while (piVar6 != param_1 + 0x20);
      if ((((short)param_1[0x2e] == 0) && ((short)param_1[0x2f] == 0)) &&
         ((short)param_1[0x32] == 0)) {
        piVar6 = param_1;
        do {
          if ((short)piVar6[0x45] != 0) goto LAB_0800438c;
          piVar6 = piVar6 + 1;
          uVar1 = 0;
        } while (param_1 + 0xe0 != piVar6);
      }
      else {
LAB_0800438c:
        uVar1 = 1;
      }
LAB_080042d8:
      *(undefined4 *)(*param_1 + 0x2c) = uVar1;
    }
    build_tree(param_1,param_1 + 0x2c6);
    build_tree(param_1,param_1 + 0x2c9);
    uVar1 = scan_tree(param_1,param_1 + 0x25,param_1[0x2c7]);
    uVar1 = scan_tree(uVar1,param_1 + 0x262,param_1[0x2ca]);
    build_tree(uVar1,param_1 + 0x2cc);
    iVar11 = 0x12;
    do {
      if (*(short *)((int)param_1 + (uint)*(byte *)(DAT_0800440c + iVar11) * 4 + 0xa7e) != 0) break;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 2);
    iVar7 = iVar11 * 3 + param_1[0x5aa];
    uVar13 = param_1[0x5ab] + 10U >> 3;
    uVar5 = iVar7 + 0x1b;
    param_1[0x5aa] = iVar7 + 0x11;
    if (uVar5 >> 3 < uVar13) {
      uVar5 = uVar5 >> 3;
      if (param_1[0x22] == 4) {
        uVar5 = uVar13;
      }
    }
    else {
      uVar5 = uVar13;
    }
  }
  if ((uVar5 < param_3 + 4U) || (param_2 == 0)) {
    uVar8 = param_1[0x5af];
    uVar2 = (uint)*(ushort *)(param_1 + 0x5ae);
    if (uVar5 == uVar13) {
      uVar5 = param_4 + 2U & 0xffff;
      if ((int)uVar8 < 0xe) {
        uVar10 = (ushort)(uVar5 << (uVar8 & 0xff)) | *(ushort *)(param_1 + 0x5ae);
        iVar11 = uVar8 + 3;
      }
      else {
        iVar11 = param_1[5];
        uVar2 = uVar5 << (uVar8 & 0xff) & 0xffff | uVar2;
        *(short *)(param_1 + 0x5ae) = (short)uVar2;
        param_1[5] = iVar11 + 1;
        *(char *)(param_1[2] + iVar11) = (char)uVar2;
        iVar11 = param_1[5];
        param_1[5] = iVar11 + 1;
        *(char *)(param_1[2] + iVar11) = (char)((uint)param_1[0x5ae] >> 8);
        uVar10 = (ushort)((int)uVar5 >> (0x10U - param_1[0x5af] & 0xff));
        iVar11 = param_1[0x5af] + -0xd;
      }
      param_1[0x5af] = iVar11;
      piVar9 = DAT_08004414;
      piVar6 = DAT_08004410;
      *(ushort *)(param_1 + 0x5ae) = uVar10;
      piVar3 = param_1;
    }
    else {
      if ((int)uVar8 < 0xe) {
        uVar2 = uVar2 | (param_4 + 4U & 0xffff) << (uVar8 & 0xff) & 0xffff;
        uVar8 = uVar8 + 3;
      }
      else {
        uVar5 = param_4 + 4U & 0xffff;
        iVar7 = param_1[5];
        uVar2 = uVar5 << (uVar8 & 0xff) & 0xffff | uVar2;
        *(short *)(param_1 + 0x5ae) = (short)uVar2;
        param_1[5] = iVar7 + 1;
        *(char *)(param_1[2] + iVar7) = (char)uVar2;
        iVar7 = param_1[5];
        param_1[5] = iVar7 + 1;
        *(char *)(param_1[2] + iVar7) = (char)((uint)param_1[0x5ae] >> 8);
        uVar2 = (int)uVar5 >> (0x10U - param_1[0x5af] & 0xff) & 0xffff;
        uVar8 = param_1[0x5af] - 0xd;
      }
      uVar5 = param_1[0x2ca];
      param_1[0x5af] = uVar8;
      uVar13 = param_1[0x2c7] - 0x100U & 0xffff;
      if ((int)uVar8 < 0xc) {
        uVar2 = uVar2 | uVar13 << (uVar8 & 0xff) & 0xffff;
        uVar8 = uVar8 + 5;
      }
      else {
        iVar7 = param_1[5];
        uVar2 = uVar13 << (uVar8 & 0xff) & 0xffff | uVar2;
        *(short *)(param_1 + 0x5ae) = (short)uVar2;
        param_1[5] = iVar7 + 1;
        *(char *)(param_1[2] + iVar7) = (char)uVar2;
        iVar7 = param_1[5];
        param_1[5] = iVar7 + 1;
        *(char *)(param_1[2] + iVar7) = (char)((uint)param_1[0x5ae] >> 8);
        uVar2 = (int)uVar13 >> (0x10U - param_1[0x5af] & 0xff) & 0xffff;
        uVar8 = param_1[0x5af] - 0xb;
      }
      param_1[0x5af] = uVar8;
      uVar13 = uVar5 & 0xffff;
      if ((int)uVar8 < 0xc) {
        uVar2 = uVar2 | uVar13 << (uVar8 & 0xff) & 0xffff;
        uVar8 = uVar8 + 5;
      }
      else {
        iVar7 = param_1[5];
        uVar2 = uVar2 | uVar13 << (uVar8 & 0xff) & 0xffff;
        *(short *)(param_1 + 0x5ae) = (short)uVar2;
        param_1[5] = iVar7 + 1;
        *(char *)(param_1[2] + iVar7) = (char)uVar2;
        iVar7 = param_1[5];
        param_1[5] = iVar7 + 1;
        *(char *)(param_1[2] + iVar7) = (char)((uint)param_1[0x5ae] >> 8);
        uVar2 = (int)uVar13 >> (0x10U - param_1[0x5af] & 0xff) & 0xffff;
        uVar8 = param_1[0x5af] - 0xb;
      }
      param_1[0x5af] = uVar8;
      uVar13 = iVar11 - 3U & 0xffff;
      if ((int)uVar8 < 0xd) {
        uVar10 = (ushort)uVar2 | (ushort)(uVar13 << (uVar8 & 0xff));
        iVar7 = uVar8 + 4;
      }
      else {
        iVar7 = param_1[5];
        uVar2 = uVar13 << (uVar8 & 0xff) & 0xffff | uVar2;
        *(short *)(param_1 + 0x5ae) = (short)uVar2;
        param_1[5] = iVar7 + 1;
        *(char *)(param_1[2] + iVar7) = (char)uVar2;
        iVar7 = param_1[5];
        param_1[5] = iVar7 + 1;
        *(char *)(param_1[2] + iVar7) = (char)((uint)param_1[0x5ae] >> 8);
        uVar10 = (ushort)((int)uVar13 >> (0x10U - param_1[0x5af] & 0xff));
        iVar7 = param_1[0x5af] + -0xc;
      }
      pbVar14 = DAT_0800463c;
      *(ushort *)(param_1 + 0x5ae) = uVar10;
      param_1[0x5af] = iVar7;
      iVar7 = 0;
      do {
        uVar2 = param_1[0x5af];
        uVar8 = (uint)*(ushort *)((int)param_1 + (uint)*pbVar14 * 4 + 0xa7e);
        uVar13 = uVar8 << (uVar2 & 0xff) & 0xffff | (uint)*(ushort *)(param_1 + 0x5ae);
        uVar4 = (undefined2)uVar13;
        if ((int)uVar2 < 0xe) {
          iVar12 = uVar2 + 3;
        }
        else {
          iVar12 = param_1[5];
          *(undefined2 *)(param_1 + 0x5ae) = uVar4;
          param_1[5] = iVar12 + 1;
          *(char *)(param_1[2] + iVar12) = (char)uVar13;
          iVar12 = param_1[5];
          param_1[5] = iVar12 + 1;
          *(char *)(param_1[2] + iVar12) = (char)((uint)param_1[0x5ae] >> 8);
          uVar4 = (undefined2)((int)uVar8 >> (0x10U - param_1[0x5af] & 0xff));
          iVar12 = param_1[0x5af] + -0xd;
        }
        iVar7 = iVar7 + 1;
        *(undefined2 *)(param_1 + 0x5ae) = uVar4;
        param_1[0x5af] = iVar12;
        pbVar14 = pbVar14 + 1;
      } while (iVar7 != iVar11 + 1);
      piVar6 = param_1 + 0x25;
      uVar1 = send_tree(param_1,piVar6);
      piVar9 = param_1 + 0x262;
      piVar3 = (int *)send_tree(uVar1,piVar9,uVar5);
    }
    compress_block(piVar3,piVar6,piVar9);
  }
  else {
    _tr_stored_block(param_1,param_2,param_3,param_4);
  }
  init_block(param_1);
  if (param_4 == 0) {
    return;
  }
  bi_windup(param_1);
  return;
}




int uncompress2(undefined1 *param_1,int *param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_5c [4];
  undefined4 local_58;
  int local_54;
  undefined1 *local_4c;
  int local_48;
  int local_44;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  
  iVar3 = *param_2;
  iVar5 = *param_4;
  if (iVar3 == 0) {
    iVar3 = 1;
    param_1 = auStack_5c;
  }
  else {
    *param_2 = 0;
  }
  local_54 = 0;
  local_30 = 0;
  local_38 = 0;
  uStack_34 = 0;
  local_58 = param_3;
  iVar1 = inflateInit_(&local_58,DAT_080046f8,0x38);
  if (iVar1 == 0) {
    local_48 = 0;
    local_4c = param_1;
    do {
      iVar4 = iVar3;
      if (local_48 == 0) {
        iVar4 = local_48;
        local_48 = iVar3;
      }
      iVar6 = iVar5;
      if (local_54 == 0) {
        iVar6 = local_54;
        local_54 = iVar5;
      }
      iVar2 = inflate(&local_58,0);
      iVar3 = iVar4;
      iVar5 = iVar6;
    } while (iVar2 == 0);
    *param_4 = (*param_4 - local_54) - iVar6;
    if (param_1 == auStack_5c) {
      if ((local_44 != 0) && (iVar2 == -5)) {
        iVar4 = 1;
      }
    }
    else {
      *param_2 = local_44;
    }
    inflateEnd(&local_58);
    if (iVar2 != 1) {
      if (iVar2 == 2) {
        iVar1 = -3;
      }
      else if (iVar2 == -5) {
        if (iVar4 + local_48 == 0) {
          iVar1 = -5;
        }
        else {
          iVar1 = -3;
        }
      }
      else {
        iVar1 = iVar2;
      }
    }
  }
  return iVar1;
}




void uncompress(void)

{
  uncompress2();
  return;
}




void zmemcpy(int param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar3;
  undefined1 *puVar2;
  
  if (param_3 != 0) {
    puVar1 = (undefined1 *)(param_1 + -1);
    puVar3 = param_2;
    do {
      puVar2 = puVar3 + 1;
      puVar1 = puVar1 + 1;
      *puVar1 = *puVar3;
      puVar3 = puVar2;
    } while (puVar2 != param_2 + param_3);
  }
  return;
}




void zmemzero(void *param_1,size_t param_2)

{
  if (param_2 == 0) {
    return;
  }
  memset(param_1,0,param_2);
  return;
}




void * memset(void *m,int c,size_t n)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
                    /* Unresolved local var: char * s@[DW_OP_reg0(r0)]
                       Unresolved local var: uint i@[???]
                       Unresolved local var: ulong buffer@[???]
                       Unresolved local var: ulong * aligned_addr@[???]
                       Unresolved local var: uint d@[DW_OP_breg1(r1): 0; DW_OP_const1u: 255;
                       DW_OP_and; DW_OP_stack_value] */
  if (((uint)m & 3) == 0) {
    piVar3 = m;
  }
  else {
    if (n == 0) {
      return m;
    }
    piVar4 = m;
    while( true ) {
      n = n - 1;
      piVar3 = (int *)((int)piVar4 + 1);
      *(char *)piVar4 = (char)c;
      if (((uint)piVar3 & 3) == 0) break;
      piVar4 = piVar3;
      if (n == 0) {
        return m;
      }
    }
  }
  if (3 < n) {
    iVar2 = (c & 0xffU) * 0x1010101;
    if (0xf < n) {
      piVar4 = piVar3;
      do {
        *piVar4 = iVar2;
        piVar4[1] = iVar2;
        piVar4[2] = iVar2;
        piVar4[3] = iVar2;
        piVar4 = piVar4 + 4;
      } while (piVar4 != (int *)((int)piVar3 + (n - 0x10 & 0xfffffff0) + 0x10));
      uVar1 = n & 0xc;
      piVar3 = piVar3 + ((n - 0x10 >> 4) + 1) * 4;
      n = n & 0xf;
      if (uVar1 == 0) goto joined_r0x080047a8;
    }
    piVar4 = (int *)((n - 4 & 0xfffffffc) + 4 + (int)piVar3);
    do {
      piVar5 = piVar3 + 1;
      *piVar3 = iVar2;
      piVar3 = piVar5;
    } while (piVar4 != piVar5);
    n = n & 3;
    piVar3 = piVar4;
  }
joined_r0x080047a8:
  if (n != 0) {
    piVar4 = piVar3;
    do {
      piVar5 = (int *)((int)piVar4 + 1);
      *(char *)piVar4 = (char)c;
      piVar4 = piVar5;
    } while (piVar5 != (int *)(n + (int)piVar3));
  }
  return m;
}




void * memcpy(void *__dest,void *__src,size_t __n)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  
  puVar3 = __dest;
  if ((((uint)__src | (uint)__dest) & 3) != 0) {
    if (__n < 8) {
      uVar8 = __n - 4;
      puVar1 = __dest;
      if (3 < __n) {
        do {
          puVar6 = __src;
          puVar4 = puVar1;
          bVar9 = uVar8 != 0;
          uVar8 = uVar8 - 1;
          *puVar4 = *puVar6;
          puVar1 = puVar4 + 1;
          __src = puVar6 + 1;
        } while (bVar9);
        puVar4[1] = puVar6[1];
        puVar4[2] = puVar6[2];
        puVar4[3] = puVar6[3];
        return __dest;
      }
      goto LAB_0800489c;
    }
    if ((((uint)__src & 3) != 0) && (uVar8 = (uint)__dest & 3, uVar8 != 0)) {
      __n = __n - (4 - uVar8);
      puVar2 = __dest;
      puVar5 = __src;
      if (((uint)__dest & 1) != 0) {
        puVar5 = (undefined4 *)((int)__src + 1);
        puVar2 = (undefined4 *)((int)__dest + 1);
        *(undefined1 *)__dest = *(undefined1 *)__src;
      }
      puVar3 = puVar2;
      __src = puVar5;
      if ((uVar8 * -0x40000000 & 0x80000000) != 0) {
        __src = (void *)((int)puVar5 + 2);
        puVar3 = (undefined4 *)((int)puVar2 + 2);
        *(undefined2 *)puVar2 = *(undefined2 *)puVar5;
      }
    }
  }
  while (0x3f < __n) {
    *puVar3 = *(undefined4 *)__src;
    puVar3[1] = *(undefined4 *)((int)__src + 4);
    puVar3[2] = *(undefined4 *)((int)__src + 8);
    puVar3[3] = *(undefined4 *)((int)__src + 0xc);
    puVar3[4] = *(undefined4 *)((int)__src + 0x10);
    puVar3[5] = *(undefined4 *)((int)__src + 0x14);
    puVar3[6] = *(undefined4 *)((int)__src + 0x18);
    puVar3[7] = *(undefined4 *)((int)__src + 0x1c);
    puVar3[8] = *(undefined4 *)((int)__src + 0x20);
    puVar3[9] = *(undefined4 *)((int)__src + 0x24);
    puVar3[10] = *(undefined4 *)((int)__src + 0x28);
    puVar3[0xb] = *(undefined4 *)((int)__src + 0x2c);
    puVar3[0xc] = *(undefined4 *)((int)__src + 0x30);
    puVar3[0xd] = *(undefined4 *)((int)__src + 0x34);
    puVar3[0xe] = *(undefined4 *)((int)__src + 0x38);
    puVar3[0xf] = *(undefined4 *)((int)__src + 0x3c);
    puVar3 = puVar3 + 0x10;
    __src = (undefined4 *)((int)__src + 0x40);
    __n = __n - 0x40;
  }
  uVar7 = __n - 0x10;
  if (0xffffffcf < __n - 0x40) {
    do {
      *puVar3 = *(undefined4 *)__src;
      puVar3[1] = *(undefined4 *)((int)__src + 4);
      puVar2 = (undefined4 *)((int)__src + 0xc);
      puVar5 = puVar3 + 3;
      puVar3[2] = *(undefined4 *)((int)__src + 8);
      __src = (void *)((int)__src + 0x10);
      puVar3 = puVar3 + 4;
      *puVar5 = *puVar2;
      bVar9 = 0xf < uVar7;
      uVar7 = uVar7 - 0x10;
    } while (bVar9);
  }
  uVar8 = uVar7 + 0xc;
  puVar5 = puVar3;
  puVar2 = __src;
  if (0xfffffff3 < uVar7) {
    do {
      __src = puVar2 + 1;
      *puVar5 = *puVar2;
      bVar9 = 3 < uVar8;
      uVar8 = uVar8 - 4;
      puVar3 = puVar5 + 1;
      puVar5 = puVar5 + 1;
      puVar2 = __src;
    } while (bVar9);
  }
LAB_0800489c:
  if (uVar8 != 0xfffffffc) {
    puVar2 = puVar3;
    puVar5 = __src;
    if ((uVar8 & 1) != 0) {
      puVar5 = (undefined4 *)((int)__src + 1);
      puVar2 = (undefined4 *)((int)puVar3 + 1);
      *(undefined1 *)puVar3 = *(undefined1 *)__src;
    }
    if ((uVar8 & 2) != 0) {
      *(undefined2 *)puVar2 = *(undefined2 *)puVar5;
    }
  }
  return __dest;
}




/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void memcpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




int memcmp(void *m1,void *m2,size_t n)

{
  int *piVar1;
  int *piVar2;
  byte *pbVar3;
  byte *pbVar4;
  
                    /* Unresolved local var: uchar * s1@[DW_OP_reg0(r0)]
                       Unresolved local var: uchar * s2@[DW_OP_reg1(r1)]
                       Unresolved local var: ulong * a1@[???]
                       Unresolved local var: ulong * a2@[???] */
  if (3 < n) {
    piVar1 = m1;
    piVar2 = m2;
    if ((((uint)m2 | (uint)m1) & 3) != 0) goto LAB_0800493a;
    do {
      m2 = piVar2 + 1;
      m1 = piVar1 + 1;
      if (*piVar1 != *piVar2) goto LAB_0800493a;
      n = n - 4;
      piVar2 = m2;
      piVar1 = m1;
    } while (3 < n);
  }
  piVar1 = m1;
  piVar2 = m2;
  if (n == 0) {
    return 0;
  }
LAB_0800493a:
  pbVar4 = (byte *)((int)piVar1 + -1);
  pbVar3 = (byte *)((int)piVar2 + -1);
  do {
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if ((uint)*pbVar4 != (uint)*pbVar3) {
      return (uint)*pbVar4 - (uint)*pbVar3;
    }
  } while ((byte *)((int)piVar1 + (n - 1)) != pbVar4);
  return 0;
}



