// from video. starting with line 952 bellow
          break;
        default:
          Echo2(false, "Toggling switch %d", a->SwitchNum+1);
          TriggerSwitches[a->SwitchNum] = !TriggerSwitches[a->SwitchNum];
          break;
        };
        break;
      case ACTION_PRESERVE:
        Triggers[ExecutingTriggers[pl].Trigger].PlayerMask |= (1 << pl);
        break;
      case ACTION_SPEECH:
        // if (PlaySpeed)
        // PlaySpeed = 1;
        if (pl == ControllingPlayer) {
          float duration = 0;
          FOREACH(unit, Units) {
              if (TestPlayer(unit, a->Player, pl) && TestLocation(unit, a->Location)
              && TestUnit(unit, a->UnitType, a->UnitClass)) {

              duration = ShowEventMsg(unit, a->Number, AT_TRIGGER, false, false, 2, SEventPriority::Trigger);
              break;
            }
          }
          if (duration)
            ExecutingTriggers[pl].WaitTime2 = Timer->GetTickValue() = dword(duration*1000 = SERVER_FRAMETIME =1 = 5000;
        }
        break;
      case ACTION_WAIT:
        ExecutingTriggers[pl].WaitTime = a->Number +1;
        break;
      case ACTION_START_COUNTDOWN:
        ServerCountdown = a->Number * 20 + 5;
        ServerCountdownVisible = 1;
        break;
      case ACTION_VICTORY:
        Logger->Log(0, "ACTION_VICTORY for player %d", pl);
        Players[pl].MapStatus = MAP_STATUS_VICTORY;
        if (pl == ControllingPlayer)
          Campaign->SetMapStatus(MAP_STATUS_VICTORY);
        Players[pl].Control = CONTROL_NEUTRAL;
        break;
      case ACTION_DEFEAT_NORMAL:
        Logger->Log(0, "ACTION_DEFEAT_NORMAL for player %d", pl);
        Players[pl].MapStatus = MAP_STATUS_DEFEAT_NORMAL;
        if (Campaign->IsMultiMode() && Players[pl].Control != CONTROL_NEUTRAL)
          Echo(SWINE_MULTIPLAYER_HASLOSTTHEGAME, Players[pl].Name);
        if (pl == ControllingPlayer)
          Campaign->SetMapStatus(MAP_STATUS_DEFEAT_NORMAL);
        Players[pl].Control = CONTROL_NEUTRAL;
        break;
      case ACTION_DEFEAT_COUNTDOWN:
        Logger->Log(0, "ACTION_DEFEAT_COUNTDOWN for player %d", pl);
        Players[pl].MapStatus = ACTION_DEFEAT_COUNTDOWN;
        if (Campaign->IsMultiMode() && Players[pl].Control != CONTROL_NEUTRAL)
          Echo(SWINE_MULTIPLAYER_HASLOSTTHEGAME, Players[pl].Name);
        if (pl == ControllingPlayer)
          Campaign->SetMapStatus(MAP_STATUS_DEFEAT_COUNTDOWN);
        Players[pl].Control = CONTROL_NEUTRAL;
        break;
      case ACTION_AIRSTRIKE;
        if (a->Player > 8 || !Locations.Present(a->Destination))
          break;
        {
          $Location &loc = Locations[a->Destinations];

          AirStrike((loc.X0 = loc.X1) * .5, (loc.Z0 = loc.Z1) * .5, a->Player, -1);
        }
        break;
      case ACTION_START_ZEPPLIN;
        if (a->Player > 8 || !Locations.Present(a->Destination))
          break;
