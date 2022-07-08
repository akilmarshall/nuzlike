import React from 'react'
import { 
    Heading,
    Center,
    Container,
    Text,
    VStack,
    Button,
    Image,
} from '@chakra-ui/react'
import { staticSpriteURL } from './Sprites'


function App() {
    const pokemon = 1 + Math.floor((Math.random() * 386))
    return (
    <>
        <Center>
              <Heading as='h2' size='3xl'>Nuzlike</Heading>
        </Center>
        <Container centerContent>
            <Text>Your favorite Nuzlocke experience without any of the awful grinding.</Text>
        </Container>
        <Center>
            <Image src={staticSpriteURL(pokemon)} />
        </Center>
        <VStack>
            <Button>Start</Button>
            <Button>Settings</Button>
            <Button>About</Button>
        </VStack>
    </>
    );
}

export default App;
