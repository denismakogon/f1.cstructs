# F1 2021 | 2022 (v1.10 or greater) simulator telemetry C structs API

The purpose of this project is to introduce F1 C structs to Java ecosystem using OpenJDK Project Panama.

C Structs and Java library based on (official F1 sumulator data packets)[https://answers.ea.com/t5/General-Discussion/F1-22-UDP-Specification/td-p/11551274]

## How to use published Java package

First, add the corresponding dependency to Maven:
```xml

    <repositories>
        <repository>
            <id>jitpack.io</id>
            <url>https://jitpack.io</url>
        </repository>
    </repositories>

    <dependencies>
        <dependency>
            <groupId>com.github.denismakogon</groupId>
            <artifactId>f1.cstructs</artifactId>
            <version>2022.09.20</version> <!-- note that this version corresponds to project release versions -->
        </dependency>
    </dependencies>

```

Once it's installed, you can do the following:
```java
import f1.cstructs.PacketHeader;

var bytes = new byte[] {....};
var state = SegmentAllocator.implicitAllocator()
                .allocateArray(JAVA_BYTE, Arrays.copyOfRange(bytes, 0, getLayoutSize()));

var packetFormat = PacketHeader.m_packetFormat$get(state);
var majorVersion = PacketHeader.m_gameMajorVersion$get(state);
var minorVersion = PacketHeader.m_gameMinorVersion$get(state);
```

## How to build JAR file

```shell
make jar
```
