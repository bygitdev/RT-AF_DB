<XCom 3.4>
<S1F0 N Abort Transaction (S1F0)
>

<S1F1 P Are You There Request (R)
>

<S1F2 S On Line Data (D)
  <LIST 2 
    <MDLN>
    <SOFTREV>
  >
>

<S1F2 S On Line Data (D)
  <LIST 0 
  >
>

<S1F3 P Selected Equipment Status Request (SSR)
  <LIST n 
    <SVID>
  >
>

<S1F4 S Selected Equipment Status Data (SSD)
	Undefined Structure
>
<S1F11 P Status Variable Namelist Request (SVNR)
  <LIST n 
    <SVID>
  >
>

<S1F12 S Status Variable Namelist Reply (SVNRR)
  <LIST n 
    <LIST 3 
      <SVID>
      <SVNAME>
      <UNITS>
    >
  >
>

<S1F13 P Establish Communications Request (CR)
  <LIST 2 
    <MDLN>
    <SOFTREV>
  >
>

<S1F13 P Establish Communications Request (CR)
  <LIST 0 
  >
>

<S1F14 S Establish Communications Request Acknowledge (CRA)
  <LIST 2 
    <COMMACK>
    <LIST 2 
      <MDLN>
      <SOFTREV>
    >
  >
>

<S1F14 S Establish Communications Request Acknowledge (CRA)
  <LIST 2 
    <COMMACK>
    <LIST 0 
    >
  >
>

<S1F15 P Request OFF-LINE (ROFL)
>

<S1F16 S OFF-LINE Acknowledge (OFLA)
  <OFLACK>
>

<S1F17 P Request ON-LINE (RONL)
>

<S1F18 S ON-LINE Acknowledge (ONLA)
  <ONLACK>
>

<S1F21 P Data Variable Namelist Request (DVNR)
  <LIST n 
    <VID>
  >
>

<S1F22 S Data Variable Namelist (DVN)
  <LIST n 
    <LIST 3 
      <VID>
      <DVVALNAME>
      <UNITS>
    >
  >
>

<S1F23 P Collection Event Namelist (CEN)
  <LIST n 
    <CEID>
  >
>

<S1F24 S Collection Event Namelist (CEN)
  <LIST n 
    <LIST 3 
      <CEID>
      <CENAME>
      <LIST n 
        <VID>
      >
    >
  >
>

<S2F0 N Abort Transaction (S2F0)
>

<S2F13 P Equipment Constant Request (ECR)
  <LIST n 
    <ECID>
  >
>

<S2F14 S Equipment Constant Data (ECD)
	Undefined Structure
>
<S2F15 P New Equipment Constant Send (ECS)
	Undefined Structure
>
<S2F16 S New Equipment Constant Acknowledge (ECA)
  <EAC>
>

<S2F17 P Date and Time Request (DTR)
>

<S2F18 S Date and Time Data (DTD)
  <TIME>
>

<S2F23 P Trace Initialize Send (TIS)
  <LIST 5 
    <TRID>
    <DSPER>
    <TOTSMP>
    <REPGSZ>
    <LIST n 
      <SVID>
    >
  >
>

<S2F24 S Trace Initialize Acknowledge (TIA)
  <TIAACK>
>

<S2F25 P Loopback Diagnostic Request (LDR)
  <ABS>
>

<S2F26 S Loopback Diagnostic Data (LDD)
  <ABS>
>

<S2F29 P Equipment Constant Namelist Request (ECNR)
  <LIST n ECID Lists
    <ECID>
  >
>

<S2F30 S Equipment Constant Namelist (ECN)
	Undefined Structure
>
<S2F31 P Data and Time Set Request (DTS)
  <TIME>
>

<S2F32 S Date and Time Set Acknowledge (DTA)
  <TIACK>
>

<S2F33 P Define Report (DR)
  <LIST 2 
    <DATAID>
    <LIST n 
      <LIST 2 
        <RPTID>
        <LIST n 
          <VID>
        >
      >
    >
  >
>

<S2F34 S Define Report Acknowledge (DRA)
  <DRACK>
>

<S2F35 P Link Event Report (LER)
  <LIST 2 
    <DATAID>
    <LIST n 
      <LIST 2 
        <CEID>
        <LIST n 
          <RPTID>
        >
      >
    >
  >
>

<S2F36 S Link Event Report Acknowledge (LERA)
  <LRACK>
>

<S2F37 P Enable/Disable Event Report (EDER)
  <LIST 2 
    <CEED>
    <LIST n 
      <CEID>
    >
  >
>

<S2F38 S Enable/Disable Event Report Acknowledge (EERA)
  <ERACK>
>

<S2F39 P Multi Block Inquire (DMBI)
  <LIST 2 
    <DATAID>
    <DATALENGTH>
  >
>

<S2F40 S Multi Block Grant (DMBG)
  <GRANT>
>

<S2F41 P Host Command Send (HCS)
  <LIST 2 
    <RCMD>
    <LIST n 
      <LIST 2 
        <CPNAME>
        <CPVAL>
      >
    >
  >
>

<S2F42 S Host Command Acknowledge (HCA)
  <LIST 2 
    <HCACK>
    <LIST n 
      <LIST 2 
        <CPNAME>
        <CPACK>
      >
    >
  >
>

<S2F43 P Reset Spooling Streams and Functions (RSSF)
  <LIST n 
    <LIST 2 
      <STRID>
      <LIST n 
        <FCNID>
      >
    >
  >
>

<S2F44 S Reset Spooling Acknowledge (RSA)
  <LIST 2 
    <RSPACK>
    <LIST n 
      <LIST 3 
        <STRID>
        <STRACK>
        <LIST n 
          <FCNID>
        >
      >
    >
  >
>

<S2F45 P Define Variable Limit Attributes (DVLA)
  <LIST 2 
    <DATAID>
    <LIST n 
      <LIST 2 
        <VID>
        <LIST n 
          <LIST 2 
            <LIMITID>
            <LIST 2 
              <UPPERDB>
              <LOWERDB>
            >
          >
        >
      >
    >
  >
>

<S2F46 S Variable Limit Attribute Acknowledge (VLAA)
  <LIST 2 
    <VLAACK>
    <LIST n 
      <LIST 3 
        <VID>
        <LVACK>
        <LIST 0 
        >
      >
    >
  >
>

<S2F46 S Variable Limit Attribute Acknowledge (VLAA)
  <LIST 2 
    <VLAACK>
    <LIST n 
      <LIST 3 
        <VID>
        <LVACK>
        <LIST 2 
          <LIMITID>
          <LIMITACK>
        >
      >
    >
  >
>

<S2F47 P Variable Limit Attribute Request (VLAR)
  <LIST n 
    <VID>
  >
>

<S2F48 S Variable Limit Attributes Send (VLAS)
  <LIST n 
    <LIST 2 
      <VID>
      <LIST 0 
      >
    >
  >
>

<S2F48 S Variable Limit Attributes Send (VLAS)
  <LIST n 
    <LIST 2 
      <VID>
      <LIST 4 
        <UNITS>
        <LIMITMIN>
        <LIMITMAX>
        <LIST n 
          <LIST 3 
            <LIMITID>
            <UPPERDB>
            <LOWERDB>
          >
        >
      >
    >
  >
>

<S5F0 N Abort Transaction (S5F0)
>

<S5F1 P Alarm Report Send (ARS)
  <LIST 3 
    <ALCD>
    <ALID>
    <ALTX>
  >
>

<S5F2 S Alarm Report Acknowledge (ARA)
  <ACKC5>
>

<S5F3 P Enable/Disable Alarm Send (EAS)
  <LIST 2 
    <ALED>
    <ALID>
  >
>

<S5F4 S Enable/Disable Alarm Acknowledge (EAA)
  <ACKC5>
>

<S5F5 P List Alarms Request (LAR)
  <LIST n 
    <ALID>
  >
>

<S5F5 P List Alarms Request (LAR)
  <ALID>
>

<S5F6 S List Alarms Data (LAD)
  <LIST n 
    <LIST 3 
      <ALCD>
      <ALID>
      <ALTX>
    >
  >
>

<S5F7 P List Alarms Enable Request (LEAR)
>

<S5F8 S List Alarms Enable Data (LEAD)
  <LIST n 
    <LIST 3 
      <ALCD>
      <ALID>
      <ALTX>
    >
  >
>

<S6F0 N Abort Transaction (S6F0)
>

<S6F1 P Trace Data Send (TDS)
	Undefined Structure
>
<S6F2 S Trace Data Acknowledge (TDA)
  <ACKC6>
>

<S6F11 P Event Report Send (ERS)
	Undefined Structure
>
<S6F12 S Event Report Acknowledge (ERA)
  <ACKC6>
>

<S6F15 P Event Report Request (ERR)
  <CEID>
>

<S6F16 S Event Report Data (ERD)
	Undefined Structure
>
<S6F19 P Individual Report Request (IRR)
  <RPTID>
>

<S6F20 S Individual Report Data (IRD)
	Undefined Structure
>
<S6F23 P Request Spooled Data (RSD)
  <RSDC>
>

<S6F24 S Request Spooled Data Acknowledgement Send (RSDAS)
  <RSDA>
>

<S7F0 N Abort Transaction (S7F0)
>

<S7F1 P Process Program Load Inquire (PPI)
  <LIST 2 
    <PPID>
    <LENGTH>
  >
>

<S7F2 S Process Program Load Grant (PPG)
  <PPGNT>
>

<S7F3 P Process Program Send (PPS)
  <LIST 2 
    <PPID>
    <PPBODY>
  >
>

<S7F4 S Process Program Acknowledge (PPA)
  <ACKC7>
>

<S7F5 P Process Program Request (PPR)
  <PPID>
>

<S7F6 S Process Program Data (PPD)
  <LIST 2 
    <PPID>
    <PPBODY>
  >
>

<S7F6 S Process Program Data (PPD)
  <LIST 0 
  >
>

<S7F17 P Delete Process Program Send (DPS)
  <LIST n 
    <PPID>
  >
>

<S7F18 S Delete Process Program Acknowledge (DPA)
  <ACKC7>
>

<S7F19 P Current EPPD Request (RER)
>

<S7F20 S Current EPPD Data (RED)
  <LIST n 
    <PPID>
  >
>

<S7F23 P Formatted Process Program Send (FPS)
  <LIST 4 
    <PPID>
    <MDLN>
    <SOFTREV>
    <LIST n CCODE n PPARM Lists
      <LIST 2 n-th list items
        <CCODE>
        <LIST n PPARM Lists
          <PPARM>
        >
      >
    >
  >
>

<S7F23 P Formatted Process Program Send (FPS)
  <LIST 4 
    <PPID>
    <MDLN>
    <SOFTREV>
    <LIST n CCODE n PPARM Lists
      <LIST 2 n-th list items
        <CCODE>
        <LIST n PPARM Lists
          <LIST 2 
            <PPNAME>
            <PPVALUE>
          >
        >
      >
    >
  >
>

<S7F24 S Formatted Process Program Acknowledge (FPA)
  <ACKC7>
>

<S7F25 P Formatted Process Program Request (FPR)
  <PPID>
>

<S7F26 S Formatted Process Program Data (FPD)
  <LIST 4 
    <PPID>
    <MDLN>
    <SOFTREV>
    <LIST n Number of Process Commands
      <LIST 2 
        <CCODE>
        <LIST n Number of Parameters
          <PPARM>
        >
      >
    >
  >
>

<S7F26 S Extension Formatted Process Program Data (FPD)
  <LIST 4 
    <PPID>
    <MDLN>
    <SOFTREV>
    <LIST n Number of Process Commands
      <LIST 2 
        <CCODE>
        <LIST n PPARM Lists
          <LIST 2 
            <PPNAME>
            <PPVALUE>
          >
        >
      >
    >
  >
>

<S7F27 P Process Program Verification Send (PVS)
  <LIST 2 
    <PPID>
    <LIST n number of errors being reported
      <LIST 3 
        <ACKC7A>
        <SEQNUM>
        <ERRW7>
      >
    >
  >
>

<S7F28 S Process Program Verification Acknowledge (PVA)
>

<S10F0 N Abort Transaction (S10F0)
>

<S10F1 P Terminal Request (TRN)
  <LIST 2 
    <TID>
    <TEXT>
  >
>

<S10F2 S Terminal Request Acknowledge (TRA)
  <ACKC10>
>

<S10F3 P Terminal Display, Single (VTN)
  <LIST 2 
    <TID>
    <TEXT>
  >
>

<S10F4 S Terminal Display, Single Acknowledge (VTA)
  <ACKC10>
>

<S10F5 P Terminal Display, Multi-Block (VTN)
  <LIST 2 
    <TID>
    <LIST n 
      <TEXT>
    >
  >
>

<S10F6 S Terminal Display, Multi-Block Acknowledge (VMA)
  <ACKC10>
>

