class SVersion
{
    public void SVersion(class SString );
    public void SVersion(int );
    public void SVersion(enum SwineVersionType ,int ,int );
    public void SVersion();
    public class SString GetVersionTypeString();
    public enum SwineVersionType GetVersionTypeFromString(char * );
    public float GetFloat();
    public int GetInt();
    public class SString GetLongString();
    public class SString GetShortString();
    public class SString GetNetworkString();
    public bool IsGoodVersion(class SVersion );
    public int GetMajorVersion();
    public int GetMinorVersion();
    public enum SwineVersionType GetVersionType();
    private int MajorVersion;
    private int MinorVersion;
    private enum SwineVersionType VersionType;
};
