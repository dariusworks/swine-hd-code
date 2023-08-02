SVersion * __thiscall SVersion::SVersion(SVersion *this)
{
  this->MajorVersion = 1;
  this->MinorVersion = 6;
  this->VersionType = Gold;
  return this;
}


SwineVersionType __thiscall SVersion::GetVersionTypeFromString(SVersion *this,char *param_1)
{
  int version;
  
  version = _stricmp(param_1,"Developer");
  if (version != 0) {
    version = _stricmp(param_1,"HD Remaster");
    if (version == 0) {
      return Gold;
    }
  }
  return Developer;
}

// multiplayer probably
bool __thiscall SVersion::IsGoodVersion(SVersion *this,SVersion param_1) 
{
  if (((this->VersionType == param_1.VersionType) && (this->MajorVersion == param_1.MajorVersion))
     && (this->MinorVersion == param_1.MinorVersion)) {
    return true;
  }
  return false;
}
