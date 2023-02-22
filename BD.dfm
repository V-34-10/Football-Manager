object BD: TBD
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 215
  Width = 200
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=MSDASQL.1;Persist Security Info=False;Extended Properti' +
      'es="DSN=MySQL;DESCRIPTION=driver for MySQL;SERVER=localhost;UID=' +
      'root;DATABASE=football_manager;PORT=3306"'
    LoginPrompt = False
    Left = 24
    Top = 16
  end
  object DataSource1: TDataSource
    DataSet = ADOQuery1
    Left = 80
    Top = 16
  end
  object ADOQuery1: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      
        'SELECT * FROM football_manager.player INNER JOIN football_manage' +
        'r.klub ON player.Id_klub = klub.Id_klub;')
    Left = 136
    Top = 16
  end
  object ADOQuery2: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      
        'SELECT * FROM football_manager.plan INNER JOIN football_manager.' +
        'list_player ON `plan`.id_plan = `list_player`.id_plan INNER JOIN' +
        ' football_manager.player ON `list_player`.id_player = `player`.i' +
        'd_player INNER JOIN football_manager.klub ON `klub`.Id_klub = `p' +
        'layer`.Id_klub;')
    Left = 80
    Top = 64
  end
  object DataSource2: TDataSource
    DataSet = ADOQuery2
    Left = 24
    Top = 64
  end
  object ADOQuery3: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM football_manager.klub;')
    Left = 136
    Top = 64
  end
  object DataSource3: TDataSource
    DataSet = ADOQuery3
    Left = 24
    Top = 112
  end
  object ADOQuery4: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      
        'SELECT *  FROM football_manager.match INNER JOIN football_manage' +
        'r.klub ON `match`.id_klub1 = `klub`.Id_klub  INNER JOIN football' +
        '_manager.plan ON `match`.id_plan = `plan`.id_plan;')
    Left = 136
    Top = 112
  end
  object DataSource4: TDataSource
    DataSet = ADOQuery4
    Left = 80
    Top = 112
  end
  object ADOQuery5: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      
        'SELECT * FROM football_manager.transfer INNER JOIN football_mana' +
        'ger.player ON `transfer`.id_player = `player`.id_player INNER JO' +
        'IN football_manager.klub ON `player`.Id_klub = `klub`.Id_klub;')
    Left = 24
    Top = 160
  end
  object DataSource5: TDataSource
    DataSet = ADOQuery5
    Left = 80
    Top = 160
  end
  object ADOQuery6: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM football_manager.transfer;')
    Left = 136
    Top = 160
  end
end
