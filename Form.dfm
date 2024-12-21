object Form1: TForm1
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Robots'
  ClientHeight = 350
  ClientWidth = 676
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnMouseWheel = FormMouseWheel
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 168
    Top = 64
    Width = 326
    Height = 45
    Caption = 'Simulador de robots'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -37
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 132
    Top = 143
    Width = 410
    Height = 13
    Caption = 
      'Ingrese la cantidad de robots que desea simular en un rango de v' +
      'alores entre 1 y 50.'
  end
  object Label3: TLabel
    Left = 227
    Top = 162
    Width = 220
    Height = 13
    Caption = 'Posterior a esto pulse en el boton "Comenzar"'
  end
  object Edit1: TEdit
    Left = 264
    Top = 193
    Width = 137
    Height = 21
    TabOrder = 0
  end
  object Button1: TButton
    Left = 296
    Top = 236
    Width = 75
    Height = 25
    Caption = 'Comenzar'
    TabOrder = 1
    OnClick = Button1Click
  end
end
